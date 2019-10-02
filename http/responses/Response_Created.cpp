#include "Response_Created.hpp"

#include <iostream>

Response_Created::Response_Created(Resource& RESOURCE) : Response(RESOURCE) {
    code = 201;
    reasonPhrase = "Created";
}

void Response_Created::send(std::ostream& os) {
        std::cout << "creating file..." << std::endl;
        std::ofstream file;
        file.open(resource.getPath());
        file << resource.getFile();
        file.close();

    loadGeneralResponse();
    statusLine += "\r\n";

    os << statusLine << std::flush;
}