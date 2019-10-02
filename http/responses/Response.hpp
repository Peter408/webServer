#ifndef RESPONSE_HPP
#define RESPONSE_HPP

#include "../Resource.hpp"

#include <string>
#include <ostream>

class Response {
public:
    Response(Resource& RESOURCE) : resource(RESOURCE) { }
    virtual void send(std::ostream&) =0;
    std::string getTime();
    int getCode();
protected:
    const std::string HTTP_VERSION = "HTTP/1.1";
    int code;
    std::string reasonPhrase;
    std::string statusLine;
    Resource& resource;
    void loadGeneralResponse();
    void loadContentHeaders();
};

#endif