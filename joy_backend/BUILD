load("//bzl:module.bzl", "isaac_app", "isaac_cc_module")

isaac_cc_module(
    name = "joy_component",
    srcs = ["joy_node.cpp"],
    hdrs = ["joy_node.hpp"],
)

isaac_app(
     name = "joy_backend",
 		 data = [],
     modules = [
        "sight",
        "//apps/examples/joy_backend:joy_component",	
		"navigation",
    ],
)

