#pragma once

#include <grpc++/grpc++.h>
#include <string>

#include "protos/service.pb.h"
#include "protos/service.grpc.pb.h"

namespace demoservice {

    // service interface for implementation is generated as class
    // <grpc service package>::<service name>::Service

    // some other useful service stubs are generated
    class DemoService final : public demoservice::Demo::Service {
    private:
        std::string _serviceAuthor;

    public:
        DemoService(const std::string& author = "incognito"):
            _serviceAuthor(author) 
            {
            }

        ::grpc::Status SayHello(::grpc::ServerContext* context, const ::demoservice::HelloRequest* request, ::demoservice::HelloReply* response) override;
    };
}