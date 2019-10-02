#ifndef WEBSERVER_HPP
#define WEBSERVER_HPP

#include "configuration/HttpdConf.hpp"
#include "configuration/MimeTypes.hpp"

class WebServer {
public:
    WebServer();
    void start();
    
private:
    HttpdConf httpdConf;
    MimeTypes mimeTypes;

    void configuration();
};

#endif

/* main */
int main(int argc, char const *argv[]) {
    WebServer server;
    server.start();

    return 0;
}