// TODO:
//  vendor dependencies & build statically
//    - replace ncurses with libtickit?

const std = @import("std");
const builtin = @import("builtin");
const Build = std.Build;
const Step = std.Build.Step;
const Allocator = std.mem.Allocator;

const exe_name = "sc-im";
const help_dir = "share/" ++ exe_name;
const lib_dir = "share/doc/ " ++ exe_name;
const man_dir = "share/man/man1";
const history_dir = ".cache";
const history_file = "sc-sciminfo";
const config_dir = ".config/sc-im";
const config_file = "scimrc";

const src_dir = thisDir() ++ "/src";

const Macro = struct {
    name: []const u8,
    value: ?[]const u8 = null,
};

pub fn build(b: *Build) !void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const exe = try buildExe(b, target, optimize);
    exe.install();

    {
        const install_step = b.getInstallStep();

        const install_scopen = b.addInstallFile(
            .{ .path = src_dir ++ "/scopen", },
            "bin/scopen",
        );
        const install_help = b.addInstallFile(
            .{ .path = src_dir ++ "/doc", },
            help_dir ++ "/sc-im_help",
        );
        const install_man = b.addInstallFile(
            .{ .path = src_dir ++ "/sc-im.1", },
            man_dir ++ "/sc-im.1",
        );

        const plot_files: []const []const u8 = &.{
            src_dir ++ "/plot_bar",
            src_dir ++ "/plot_line",
            src_dir ++ "/plot_pie",
            src_dir ++ "/plot_scatter",
        };
        inline for (plot_files) |path| {
            const install_plot_file = b.addInstallFile(
                .{ .path = path },
                help_dir ++ "/" ++ comptime std.fs.path.basename(path),
            );
            install_step.dependOn(&install_plot_file.step);
        }

        install_step.dependOn(&install_scopen.step);
        install_step.dependOn(&install_help.step);
        install_step.dependOn(&install_man.step);
    }

    {
        const run_cmd = exe.run();

        run_cmd.step.dependOn(b.getInstallStep());

        if (b.args) |args| {
            run_cmd.addArgs(args);
        }

        const run_step = b.step("run", "Run the app");
        run_step.dependOn(&run_cmd.step);
    }

    {
        const buffer_test = b.addTest(.{
            .root_source_file = .{ .path = "tests/buffer.zig", },
        });

        buffer_test.addIncludePath(src_dir);
        buffer_test.linkLibC();

        buffer_test.addCSourceFiles(&.{
                src_dir ++ "/buffer.c",
                src_dir ++ "/utils/string.c",
            },
            &.{ "-Wall", "-g", },
        );

        const all_tests_step = b.step("test", "Runs all tests");
        all_tests_step.dependOn(&buffer_test.step);
    }

    {
        const clean_step = b.step("clean", "Remove generated files");

        const dirs_to_remove: []const []const u8 = &.{
            "zig-cache",
            "zig-out",
            "docs",
            "src/expressions.h",
            "src/satements.h",
            "src/y.tab.h",
            "src/y.tab.c",
        };

        for (dirs_to_remove) |dir| {
            const remove = b.addRemoveDirTree(dir);
            clean_step.dependOn(&remove.step);
        }
    }
}

fn buildExe(
    b: *Build,
    target: std.zig.CrossTarget,
    optimize: std.builtin.Mode,
) !*Build.CompileStep {
    const macros = comptime blk: {
        var ret: []const Macro = &.{
            .{ .name = "CONFIG_DIR",       .value = qw(config_dir) },
            .{ .name = "CONFIG_FILE",      .value = qw(config_file) },
            .{ .name = "DFLT_EDITOR",      .value = qw("vim") },
            .{ .name = "DFLT_PAGER",       .value = qw("less") },
            .{ .name = "HELP_PATH",        .value = qw(help_dir) },
            .{ .name = "HISTORY_DIR",      .value = qw(history_dir) },
            .{ .name = "HISTORY_FILE",     .value = qw(history_file) },
            .{ .name = "INS_HISTORY_FILE", .value = qw("sc-iminfo") },
            //.{ .name = "LIBDIR",           .value = qw(lib_dir) },
            .{ .name = "MAXROWS",          .value = "65536" },
            .{ .name = "SNAME",            .value = qw("sc-im") },
            .{ .name = "AUTOBACKUP",             },
            .{ .name = "GNUPLOT",                },
            .{ .name = "HAVE_PTHREAD",           },
            .{ .name = "MOUSE",                  },
            .{ .name = "NCURSES",                },
            .{ .name = "UNDO",                   },
            .{ .name = "USECOLORS"               },
            .{ .name = "USELOCALE",              },
            .{ .name = "XLUA"                    },
            .{ .name = "_GNU_SOURCE",            },
            .{ .name = "_XOPEN_SOURCE_EXTENDED", },
        };

        if (builtin.os.tag.isBSD())
            ret = ret ++ &.{ .{ .name = "NO_WORDEXP" } };

        break :blk ret;
    };

    const exe = b.addExecutable(.{
        .name = "sc-im",
        .target = target,
        .optimize = optimize,
    });

    const expressions_step = PipeToFileStep.create(
        b,
        "expressions",
        &.{ "sed", "-f", src_dir ++ "/make_expressions_header.sed", src_dir ++ "/gram.y" },
        src_dir ++ "/expressions.h",
    );

    const statements_step = PipeToFileStep.create(
        b,
        "statements",
        &.{ "sed", "-f", src_dir ++ "/make_statements_header.sed", src_dir ++ "/gram.y" },
        src_dir ++ "/satements.h",
    );

    const bison_run = b.addSystemCommand(&.{ "bison", "-d", "-y", src_dir ++ "/gram.y" });

    const mv_step1 = MoveFileStep.create(
        b,
        thisDir() ++ "/gram.c",
        src_dir ++ "/y.tab.c",
        thisDir() ++ "/y.tab.c",
    );
    const mv_step2 = MoveFileStep.create(
        b,
        thisDir() ++ "/tab.h",
        src_dir ++ "/y.tab.h",
        thisDir() ++ "/y.tab.h",
    );

    mv_step1.step.dependOn(&bison_run.step);
    mv_step2.step.dependOn(&bison_run.step);

    exe.step.dependOn(&expressions_step.step);
    exe.step.dependOn(&statements_step.step);
    exe.step.dependOn(&mv_step1.step);
    exe.step.dependOn(&mv_step2.step);

    for (macros) |macro| {
        exe.defineCMacro(macro.name, macro.value);
    }

    const src_files: []const []const u8 = &.{
        src_dir ++ "/block.c",
        src_dir ++ "/conf.c",
        src_dir ++ "/cmds/cmds_edit.c",
        src_dir ++ "/cmds/cmds_command.c",
        src_dir ++ "/cmds/cmds_normal.c",
        src_dir ++ "/cmds/cmds_insert.c",
        src_dir ++ "/cmds/cmds_visual.c",
        src_dir ++ "/cmds/cmds.c",
        src_dir ++ "/actions/filter.c",
        src_dir ++ "/actions/subtotal.c",
        src_dir ++ "/actions/sort.c",
        src_dir ++ "/actions/shift.c",
        src_dir ++ "/actions/hide_show.c",
        src_dir ++ "/actions/freeze.c",
        src_dir ++ "/actions/plot.c",
        src_dir ++ "/lua.c",
        src_dir ++ "/trigger.c",
        src_dir ++ "/xmalloc.c",
        src_dir ++ "/interp.c",
        src_dir ++ "/main.c",
        src_dir ++ "/buffer.c",
        src_dir ++ "/file.c",
        src_dir ++ "/pipe.c",
        src_dir ++ "/digraphs.c",
        src_dir ++ "/exec.c",
        src_dir ++ "/undo.c",
        src_dir ++ "/vmtbl.c",
        src_dir ++ "/help.c",
        src_dir ++ "/range.c",
        src_dir ++ "/yank.c",
        src_dir ++ "/y.tab.c",
        src_dir ++ "/color.c",
        src_dir ++ "/maps.c",
        src_dir ++ "/clipboard.c",
        src_dir ++ "/formats/xlsx.c",
        src_dir ++ "/formats/ods.c",
        src_dir ++ "/formats/xls.c",
        src_dir ++ "/function.c",
        src_dir ++ "/graph.c",
        src_dir ++ "/marks.c",
        src_dir ++ "/input.c",
        src_dir ++ "/utils/map.c",
        src_dir ++ "/utils/extra.c",
        src_dir ++ "/utils/dictionary.c",
        src_dir ++ "/utils/string.c",
        src_dir ++ "/sheet.c",
        src_dir ++ "/lex.c",
        src_dir ++ "/format.c",
        src_dir ++ "/history.c",
        src_dir ++ "/tui.c",
    };

    exe.addCSourceFiles(src_files, &.{ "-Wall", });

    exe.linkLibC();
    exe.linkSystemLibrary("m");
    exe.linkSystemLibrary("lua");
    exe.linkSystemLibrary("pthread");
    exe.linkSystemLibrary("ncursesw");

    return exe;
}

const PipeToFileStep = struct {
    step: Step,
    argv: []const []const u8,
    out_file: []const u8,

    fn create(
        b: *Build,
        name: []const u8,
        argv: []const []const u8,
        out_file: []const u8,
    ) *PipeToFileStep {
        const self = b.allocator.create(PipeToFileStep) catch @panic("OOM");

        self.* = .{
            .step = Step.init(.custom, name, b.allocator, make),
            .argv = argv,
            .out_file = out_file,
        };

        return self;
    }

    fn make(step: *Step) !void {
        const self = @fieldParentPtr(PipeToFileStep, "step", step);

        var gpa = std.heap.GeneralPurposeAllocator(.{}){};
        defer _ = gpa.deinit();
        const allocator = gpa.allocator();

        const exec_result = try std.ChildProcess.exec(.{
            .allocator = allocator,
            .argv = self.argv,
        });
        allocator.free(exec_result.stderr);
        defer allocator.free(exec_result.stdout);

        try std.fs.cwd().writeFile(self.out_file, exec_result.stdout);
    }
};

const MoveFileStep = struct {
    step: Step,
    src: []const u8,
    dest: []const u8,

    fn create(b: *Build, name: []const u8, dest: []const u8, src: []const u8) *MoveFileStep {
        const self = b.allocator.create(MoveFileStep) catch @panic("OOM");

        self.* = .{
            .step = Step.init(.custom, name, b.allocator, make),
            .src = src,
            .dest = dest,
        };

        return self;
    }

    fn make(step: *Step) !void {
        const self = @fieldParentPtr(MoveFileStep, "step", step);

        try std.fs.cwd().rename(self.src, self.dest);
    }
};

/// Returns the path of this build.zig file
inline fn thisDir() []const u8 {
	return comptime std.fs.path.dirname(@src().file) orelse ".";
}

inline fn qw(comptime str: []const u8) []const u8 {
    return "\"" ++ str ++ "\"";
}
