#ifndef RESPONSEFACTORY_HPP
#define RESPONSEFACTORY_HPP

#include <unordered_map>
#include <string>

#include "Request.hpp"
#include "Resource.hpp"
#include "responses/Response.hpp"


class ResponseFactory {
public:
    enum ResponseType {
        DEFAULT,
        GET,
        HEAD,
        POST,
        PUT,
        DELETE
    };

    Response* getResponse(std::string, Resource&);
private:
    std::unordered_map<std::string, ResponseType> verbMap {
        { "GET", GET },
        { "HEAD", HEAD },
        { "POST", POST },
        { "PUT", PUT },
        { "DELETE", DELETE }
    };
    bool isFile(Resource&);
};

#endif