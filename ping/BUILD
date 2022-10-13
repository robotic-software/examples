load("//bzl:module.bzl", "isaac_app", "isaac_cc_module")

isaac_cc_module(
    name = "ping_components",
    srcs = ["Ping.cpp"],
    hdrs = ["Ping.hpp"],
)

isaac_app(
    name = "ping",
    data = [],
    modules = [
        "sight",
        "//apps/examples/ping:ping_components",
    ],
)
