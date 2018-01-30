#!/usr/bin/python

from protos import service_pb2 as protos
from protos import service_pb2_grpc as services

from flask import Flask, render_template, request, jsonify
from datetime import datetime
from os import path

import grpc

app = Flask("democlient", template_folder=path.dirname(__file__))
service_proxy = None


@app.route("/")
def index():    
    return render_template("index.html")

@app.route("/hello", methods=["POST"])
def hello():
    name = request.get_json()["name"]
    message = None
    try:
        response = service_proxy.SayHello(protos.HelloRequest(name=name))
        message = response.msg
    except Exception, e:
        message = "Got exception. Reason: {details}".format(details=e.details())
    return jsonify({"message": message})


def run_server(port):
    from tornado.wsgi import WSGIContainer
    from tornado.httpserver import HTTPServer
    from tornado.ioloop import IOLoop

    http_server = HTTPServer(WSGIContainer(app))
    http_server.listen(port)
    IOLoop.instance().start()

def run():
    port = 8889
    print 'Web interface runs on {port}...'.format(port=port)

    channel = grpc.insecure_channel('localhost:8888')
    global service_proxy
    service_proxy = services.DemoStub(channel)

    run_server(port)
    

if __name__ == '__main__':
    run()