#include "Response_NotFound.hpp"

Response_NotFound::Response_NotFound(Resource& RESOURCE) : Response(RESOURCE) {
    code = 404;
    reasonPhrase = "Not Found";
}

void Response_NotFound::send(std::ostream& os) {
    loadGeneralResponse();
    statusLine += "\r\n";

    os << statusLine << std::flush;
}