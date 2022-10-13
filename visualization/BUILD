#COMANDI:   bazel build
#           bazel run

load("//bzl:module.bzl", "isaac_app", "isaac_cc_module")
load("@com_nvidia_isaac_engine//bzl:isaac_engine.bzl", "isaac_cc_binary")




isaac_cc_binary(
    name = "visualization",
    srcs = ["visualization.cpp"],
    data = [
        "@com_nvidia_isaac_engine//engine/gems/image/data",
        "@isaac_assets",
    ],
    
    deps = [
        "@com_nvidia_isaac_engine//engine/alice",
        "@com_nvidia_isaac_engine//engine/alice/tools:parse_command_line",
        "@com_nvidia_isaac_engine//engine/core",
        "@com_nvidia_isaac_engine//engine/gems/image",
        "//messages",
        "//packages/sight:libsight_module.so",
    ],
)

