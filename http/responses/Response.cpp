#include "Response.hpp"

#include <ctime>

std::string Response::getTime() {
    time_t ctime;
    struct tm* ptm;
    time(&ctime);
    ptm = gmtime(&ctime);

    char date_string[100];
    strftime(date_string, 50, "%a, %d %b %Y %T GMT", ptm);
    return date_string;
}

void Response::loadGeneralResponse() {
    statusLine = HTTP_VERSION + " " + std::to_string(code) + " " + reasonPhrase + "\r\n";
    
    statusLine += "Server: peterle-Server\r\n";
    statusLine += "Date: " + getTime() + "\r\n";
}

void Response::loadContentHeaders() {
    for(auto pair : resource.getHeaders()) {
        statusLine += pair.first + ": " + pair.second + "\r\n";
    }
}

int Response::getCode() {
    return code;
}