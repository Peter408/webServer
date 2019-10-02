#include "Response_Ok.hpp"

Response_Ok::Response_Ok(Resource& RESOURCE) : Response(RESOURCE) {
    code = 200;
    reasonPhrase = "OK";
}

void Response_Ok::send(std::ostream& os) {
    loadGeneralResponse();
    loadContentHeaders();
    statusLine += "\r\n";

    os << statusLine << std::flush;
    os << resource.getServerStream()->rdbuf() << std::flush;
}