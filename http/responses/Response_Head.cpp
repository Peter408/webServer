#include "Response_Head.hpp"

Response_Head::Response_Head(Resource& RESOURCE) : Response(RESOURCE) {
    code = 200;
    reasonPhrase = "OK";
}

void Response_Head::send(std::ostream& os) {
    loadGeneralResponse();
    loadContentHeaders();
    statusLine += "\r\n";

    os << statusLine << std::flush;
}