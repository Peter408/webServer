#ifndef RESPONSE_Ok_HPP
#define RESPONSE_Ok_HPP

#include <ostream>

#include "Response.hpp"
#include "../Resource.hpp"

class Response_Ok : public Response {
public:
    Response_Ok(Resource&);
    void send(std::ostream&) override;
};

#endif