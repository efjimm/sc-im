const std = @import("std");

const c = @cImport({
    @cInclude("sc.h");
});

export const KeyAction = struct {
    name: []const u8,
    key_handler: *const fn(
};
