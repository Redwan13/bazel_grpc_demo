package(default_visibility = ["//visibility:public"])

load("@pip_grpcio//:requirements.bzl", "requirement")

py_binary(
    name = "py_client",
    srcs = [
        "py_client.py",
    ],
    data = ["index.html"],
    deps = [
        "//protos:py",
        requirement("grpcio"),
	    requirement("flask"),
        requirement("tornado")
    ],
)
