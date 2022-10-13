load("//bzl:module.bzl", "isaac_app", "isaac_cc_module")

isaac_cc_module(
    name = "go_to",
    srcs = ["GoTo.cpp"],
    hdrs = ["GoTo.hpp"],
)

isaac_cc_module(
    name = "my_goal_generator",
    srcs = ["MyGoalGenerator.cpp"],
    hdrs = ["MyGoalGenerator.hpp"],
)


isaac_app(
    name = "my_goal_generator",
    modules = [
        "//apps/examples/goal_generator:go_to",
        "//apps/examples/goal_generator:my_goal_generator",
        "sight",
    ],
)



