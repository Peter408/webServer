#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <string>

#include "../http/Request.hpp"
#include "../http/Resource.hpp"
#include "../http/responses/Response.hpp"

class Logger {
public:
    Logger(std::string);
    void writeLogger(Request&, Response*, Resource&);
private:
    std::string filename;
    std::string getLength(Resource&);
};

#endif