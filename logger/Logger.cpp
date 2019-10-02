#include "Logger.hpp"

#include <iostream>

Logger::Logger(std::string FILENAME) : filename(FILENAME) { }

void Logger::writeLogger(Request& request, Response* response, Resource& resource) {
    std::string line = " [ " + response->getTime() + " ] \""
    + request.getVerb() + " " + request.getUri() + " " + request.getHttpVersion() + "\" "
    + std::to_string(response->getCode()) + " " + getLength(resource) + "\r\n";

    std::ofstream myfile(filename, std::ios_base::app);
    if(myfile.is_open()) {
        myfile << line << std::endl;
        myfile.close();
    }
    std::cout << line << std::endl;
}

std::string Logger::getLength(Resource& resource) {
    std::string str = resource.getHeaderValue("Content-Length");
    if(str.empty())
        return "0";
    return str;
}