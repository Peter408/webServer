#include "WebServer.hpp"

#include <string.h>
#include <unistd.h>

#include <iostream>
#include <sstream>
#include <thread>
#include <functional>
#include <memory>

#include <boost/asio.hpp>

#include "multithread/Worker.hpp"

#include "http/Request.hpp"
#include "http/Resource.hpp"
#include "http/ResponseFactory.hpp"
#include "http/responses/Response.hpp"


WebServer::WebServer() : httpdConf("conf/httpd.conf"), mimeTypes("conf/mime.types") {
    configuration();
}

void WebServer::start() {
    boost::asio::io_service ios;

    boost::asio::ip::tcp::endpoint endpoint(boost::asio::ip::tcp::v4(), httpdConf.getPort());
    boost::asio::ip::tcp::acceptor acceptor( ios, endpoint);

    for(;;) {
        std::cout << "running server..." << std::endl;

        Worker* worker = new Worker();
        acceptor.accept(worker->getClient()->socket());

        std::thread ( [&]{worker->run(httpdConf, mimeTypes);} ).detach();
    }
}

void WebServer::configuration() {
    httpdConf.load();
    mimeTypes.load();
}