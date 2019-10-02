#ifndef RESPONSE_BADREQUEST_HPP
#define RESPONSE_BADREQUEST_HPP

#include <ostream>

#include "Response.hpp"
#include "../Resource.hpp"

class Response_BadRequest : public Response {
public:
    Response_BadRequest(Resource&);
    void send(std::ostream&) override;
};

#endif