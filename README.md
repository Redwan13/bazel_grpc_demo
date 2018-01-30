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
bazel build //service
bazel build //cpp_client
bazel build //py_client
```

Then start service and start client. Service should be started outside ```bazel run``` because bazel cant start only one binary simultaniously. Built binary will be located in ```bazel-bin/service/service```. Clients can be started like this

```
bazel run //cpp_client
bazel run //py_client
```
