#ifndef RESPONSE_Created_HPP
#define RESPONSE_Created_HPP

#include <ostream>

#include "Response.hpp"
#include "../Resource.hpp"

class Response_Created : public Response {
public:
    Response_Created(Resource&);
    void send(std::ostream&) override;
};

#endif