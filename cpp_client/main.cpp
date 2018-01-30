#include "client.h"

#include <iostream>

using namespace demoservice;
using namespace grpc;

int main(int argc, char** argv) {
    DemoClient client(
        CreateChannel("localhost:8888", InsecureChannelCredentials()));
    
    {
        std::cout << "Trying correct input" << std::endl;

        std::string user = "user";
        std::string reply = client.SayHello(user);
        std::cout << "Client received: " << reply << std::endl;
    }

    {
        std::cout << "Trying bad input" << std::endl;
        try {
            std::string reply = client.SayHello("");
        } catch (const std::exception& e) {
            std::cout << "Got exception. Reason: " << e.what() << std::endl;
        }
    }

    return 0;
}