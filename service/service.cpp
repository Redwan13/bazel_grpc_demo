#include "service.h"

using namespace grpc;
using namespace demoservice;

Status DemoService::SayHello(ServerContext* context, const HelloRequest* request, HelloReply* response) {
    const auto& name = request->name();
    if (name.empty()) {
        return Status(StatusCode::INVALID_ARGUMENT, "name mustn't be empty");
    }
    response->set_msg("Hello to " + name + " from " + _serviceAuthor);
    return Status::OK;

}