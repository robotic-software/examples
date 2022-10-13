#COMANDI:   bazel build
#           bazel run

load("//bzl:module.bzl", "isaac_app", "isaac_cc_module")
load("@com_nvidia_isaac_engine//bzl:isaac_engine.bzl", "isaac_cc_binary")

isaac_cc_binary(
    name = "ping_no_json",
    srcs = ["ping_no_json.cpp"],
    data = [
        
    ],
    
    deps = [
        "@com_nvidia_isaac_engine//engine/alice",
        "@com_nvidia_isaac_engine//engine/alice/tools:parse_command_line",
        "@com_nvidia_isaac_engine//engine/core",
        
    ],
)

