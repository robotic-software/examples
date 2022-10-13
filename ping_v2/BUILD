#COMANDI:   bazel build
#           bazel run

load("//bzl:module.bzl", "isaac_app", "isaac_cc_module")

isaac_app ( 
    name = "ping_v2", #Questo deve essere il nome del "pacchetto"
    modules = ["//apps/examples/ping_v2:ping_v2_comp"]
)

isaac_cc_module (
    name ="ping_v2_comp",
    srcs = ["Ping_v2.cpp", "Pong.cpp"],
    hdrs = ["Ping_v2.hpp", "Pong.hpp"],
)