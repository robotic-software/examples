load("//bzl:module.bzl", "isaac_pkg")

py_binary(
    name = "ping_python",
    srcs = [
        "ping_python.py",
    ],
    data = [
        "ping_python.app.json",
    ],
    deps = [
        "//packages/pyalice",
    ],
)

isaac_pkg(
    name = "ping_python-pkg",
    srcs = ["ping_python"],
)
