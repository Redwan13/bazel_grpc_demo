#include "client.h"

#include <exception>

using namespace demoservice;
using namespace grpc;

std::string DemoClient::SayHello(const std::string& user) {
    HelloRequest request;
    request.set_name(user);

    HelloReply reply;
    ClientContext context;

    Status status = _stub->SayHello(&context, request, &reply);

    if (status.ok()) {
        return reply.msg();
    } else {
        throw std::runtime_error(status.error_message());
    }
}