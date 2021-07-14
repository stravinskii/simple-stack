load("@rules_cc//cc:defs.bzl", "cc_binary", "cc_library")

cc_library(
    name = "stack_node",
    srcs = ["src/stack_node.cpp"],
    hdrs = ["src/stack_node.h"],
)

cc_library(
    name = "stack",
    srcs = ["src/stack.cpp"],
    hdrs = ["src/stack.h"],
)

cc_binary(
    name = "main",
    srcs = ["src/main.cpp"],
    deps = [
        ":stack_node",
    ],
)
