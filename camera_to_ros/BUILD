load("//bzl:module.bzl", "isaac_app", "isaac_subgraph")


isaac_app(
    name = "camera_to_ros",
    data = [
        ":camera_to_ros_subgraph",
    ],
    modules = [
        "sensors:v4l2_camera",
        "sight",
    ],
    tags = ["manual"],
)


isaac_subgraph(
    name = "camera_to_ros_subgraph",
    modules = [
        "behavior_tree",
        "ros_bridge",
        "viewers",
		    "navigation",
        "sight",
		    "cask",
    ],
    subgraph = "camera_to_ros.subgraph.json",
    tags = ["manual"],
    visibility = ["//visibility:public"],
)
