# GRPC demo

GRPC service and client demo with bazel build system

Structure:
protos/ - grpc service description and messages
service/ - C++ grpc service implementation
cpp\_client/ - C++ grpc service client
py\_client/ - Python client with flask frontend

## how to build

You need clang-5.0


```
bazel build //
```

Then start service and start client
