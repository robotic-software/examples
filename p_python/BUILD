load("//bzl:module.bzl", "isaac_pkg")


py_binary(
    name = "p_python",
    srcs = [
        "p_python.py",
    ],
    data = [
        "p_python.app.json",
        "//packages/sight:libsight_module.so",

    ],
    deps = ["//packages/pyalice"],
)

