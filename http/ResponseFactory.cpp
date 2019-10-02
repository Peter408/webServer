#include "ResponseFactory.hpp"

#include <iostream>

#include "responses/Response_Ok.hpp"
#include "responses/Response_Head.hpp"
#include "responses/Response_NotFound.hpp"
#include "responses/Response_BadRequest.hpp"
#include "responses/Response_Created.hpp"


Response* ResponseFactory::getResponse(std::string verb, Resource& resource) {
    
    switch (verbMap[verb])
    {
    case GET:
        if(!resource.getValid()) return new Response_NotFound(resource);
        return new Response_Ok(resource);
    case HEAD:
        return new Response_Head(resource);
    case POST:
        if(isFile(resource)) return new Response_Created(resource);
        return new Response_BadRequest(resource);
    case PUT:
        if(isFile(resource)) return new Response_Created(resource);
        return new Response_BadRequest(resource);
    case DELETE:
        return nullptr;
    default:
        return new Response_BadRequest(resource);
    }
}

bool ResponseFactory::isFile(Resource& resource) {
    std::string path = resource.getPath();
    std::cout << path << std::endl;
    if(path.back() == '/')
        return false;
    return true;
}
