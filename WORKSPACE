workspace(name = "grpc_service_demo")

git_repository(
    name = "org_pubref_rules_protobuf",
    remote = "https://github.com/pubref/rules_protobuf.git",
    tag = "v0.8.1",
)

load("@org_pubref_rules_protobuf//protobuf:rules.bzl", "proto_compile")

# python protobuf support requires python rules

git_repository(
    name = "io_bazel_rules_python",
    remote = "https://github.com/bazelbuild/rules_python.git",
    commit = "73a154a181a53ee9e021668918f8a5bfacbf3b43",
)

load("@io_bazel_rules_python//python:pip.bzl", "pip_repositories", "pip_import")

pip_repositories()

pip_import(
   name = "pip_grpcio",
   requirements = "//deps:requirements.txt",
)

load("@pip_grpcio//:requirements.bzl", "pip_install")

pip_install()

# language support for protobuf clients

load("@org_pubref_rules_protobuf//cpp:rules.bzl", "cpp_proto_repositories")

cpp_proto_repositories()

load("@org_pubref_rules_protobuf//python:rules.bzl", "py_proto_repositories")

py_proto_repositories()

