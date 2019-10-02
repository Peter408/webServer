#ifndef RESPONSE_NOTFOUND_HPP
#define RESPONSE_NOTFOUND_HPP

#include <ostream>

#include "Response.hpp"
#include "../Resource.hpp"

class Response_NotFound : public Response {
public:
    Response_NotFound(Resource&);
    void send(std::ostream&) override;
};

#endif