#include "service.h"
#include <iostream>

using namespace demoservice;
using namespace grpc;

int main(int argc, char** argv) {
  const std::string address = "0.0.0.0:8888";

  std::cout << "Starting service on address " << address << std::endl;

  DemoService myService;

  ServerBuilder builder;
    builder.AddListeningPort(address, grpc::InsecureServerCredentials());
  
  builder.RegisterService(&myService);
  std::unique_ptr<Server> server(builder.BuildAndStart());

  server->Wait();
  return 0;
}