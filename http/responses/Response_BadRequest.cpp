#include "Response_BadRequest.hpp"

Response_BadRequest::Response_BadRequest(Resource& RESOURCE) : Response(RESOURCE) {
    code = 400;
    reasonPhrase = "Bad Request";
}

void Response_BadRequest::send(std::ostream& os) {
    loadGeneralResponse();
    statusLine += "\r\n";

    os << statusLine << std::flush;
}