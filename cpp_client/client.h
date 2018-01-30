#pragma once 

#include <grpc++/grpc++.h>
#include <string>

#include "protos/service.pb.h"
#include "protos/service.grpc.pb.h"

namespace demoservice {
    class DemoClient final {
    private:
        std::unique_ptr<Demo::Stub> _stub;
    public:
        DemoClient(std::shared_ptr<grpc::Channel> channel):
            _stub(Demo::NewStub(channel))
            {
            }

        std::string SayHello(const std::string& user);
    };
}