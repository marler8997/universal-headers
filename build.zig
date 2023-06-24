// tested using zig version 0.11.0-dev.2619+bd3e248c7
const std = @import("std");

pub fn build(b: *std.build.Builder) void {
    const target = b.standardTargetOptions(.{});
    const optimize = b.standardOptimizeOption(.{});

    const arocc_dep = b.dependency("arocc", .{
        .target = target,
        .optimize = optimize,
    });

    const exe = b.addExecutable(.{
        .name = "universal-headers",
        .root_source_file = .{ .path = "src/main.zig" },
        .target = target,
        .optimize = optimize,
    });
    exe.addModule("arocc", arocc_dep.module("aro"));
    //b.installArtifact(exe);

    const run_cmd = b.addRunArtifact(exe);
    run_cmd.step.dependOn(b.getInstallStep());
    if (b.args) |args| {
        run_cmd.addArgs(args);
    }

    const run_step = b.step("run", "Run the app");
    run_step.dependOn(&run_cmd.step);

    const analyzer_exe = b.addExecutable(.{
        .name = "cc-header-analyzer",
        .root_source_file = .{ .path = "src/cc-header-analyzer.zig" },
        .target = target,
        .optimize = optimize,
    });
    analyzer_exe.addModule("arocc", arocc_dep.module("aro"));
    b.installArtifact(analyzer_exe);
}
