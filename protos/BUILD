package(default_visibility = ["//visibility:public"])

load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cpp_proto_library")
load("@org_pubref_rules_protobuf//python:rules.bzl", "py_proto_library")

filegroup(
    name = "protos",
    srcs = ["service.proto"],
)

cpp_proto_library(
    name = "cpp",
    protos = [":protos"],
    with_grpc = True,
)

py_proto_library(
    name = "py",
    protos = [":protos"],
    with_grpc = True,
)
