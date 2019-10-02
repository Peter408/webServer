#ifndef RESPONSE_HEAD_HPP
#define RESPONSE_HEAD_HPP

#include "Response.hpp"

class Response_Head : public Response {
public:
    Response_Head(Resource&);
    void send(std::ostream&) override;
};

#endif