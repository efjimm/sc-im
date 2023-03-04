const std = @import("std");
const c = @cImport({
    @cInclude("buffer.h");
});

const t = std.testing;

test "buffer create" {
    const buf = c.buffer_create(0);
    defer c.buffer_destroy(buf);

    try t.expect(buf != null);
    try t.expect(c.buffer_size(buf) == 0);
    try t.expect(c.buffer_printable_len(buf) == 0);
}

test "buffer basic functions" {
    const buf = c.buffer_create(0);
    defer c.buffer_destroy(buf);

    for (0..100) |i| {
        c.buffer_append(buf, @intCast(u32, i));
        try t.expect(c.buffer_size(buf) == i + 1);
    }

    for (0..100) |i| {
        try t.expect(c.buffer_get(buf, i) == i);
    }

    for (0..100) |i| {
        try t.expect(c.buffer_contains(buf, @intCast(u32, i)));
    }

    c.buffer_reset(buf);
    try t.expect(c.buffer_size(buf) == 0);

    for (0..100) |i| {
        try t.expect(c.buffer_contains(buf, @intCast(u32, i)) == false);
    }
}

test "buffer append_buffer" {
    const buf1 = c.buffer_create(20);
    const buf2 = c.buffer_create(20);
    defer c.buffer_destroy(buf1);
    defer c.buffer_destroy(buf2);

    try t.expect(c.buffer_size(buf1) == 0);
    try t.expect(c.buffer_size(buf2) == 0);

    for (0..100) |i| {
        c.buffer_append(buf2, @intCast(u32, i));
    }

    try t.expect(c.buffer_size(buf1) == 0);
    try t.expect(c.buffer_size(buf2) == 100);

    c.buffer_append_buffer(buf1, buf2);

    try t.expect(c.buffer_size(buf1) == 100);
    try t.expect(c.buffer_size(buf2) == 100);

    for (0..100) |i| {
        try t.expect(c.buffer_get(buf1, i) == i);
    }

    c.buffer_reset(buf1);
    c.buffer_reset(buf2);

    for (0..5) |i| {
        c.buffer_append(buf1, @intCast(u32, i));
    }

    for (5..10) |i| {
        c.buffer_append(buf2, @intCast(u32, i));
    }

    try t.expect(c.buffer_size(buf1) == 5);
    try t.expect(c.buffer_size(buf2) == 5);

    c.buffer_append_buffer(buf1, buf2);
    try t.expect(c.buffer_size(buf1) == 10);

    for (0..10) |i| {
        try t.expect(c.buffer_get(buf1, i) == i);
    }
}
