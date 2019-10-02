#ifndef REQUEST_HPP
#define REQUEST_HPP

#include <istream>
#include <string>
#include <unordered_map>

class Request {
public:
    Request(std::istream&);
    void parse();
    const std::string getVerb();
    const std::string getUri();
    const std::string getHttpVersion();
    char* getBody();
private:
    std::istream& client;
    std::string uri;
    std::string verb;
    std::string httpVersion;
    std::unordered_map<std::string, std::string> headers;
    char* body;
    std::string toLower(std::string);
    void parseRequestLine();
    void parseHeaders();
    void parseBody();
};

#endif