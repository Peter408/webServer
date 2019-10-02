#include "Request.hpp"

#include <sstream>
#include <vector>
#include <iostream>
#include <cctype>
#include <typeinfo>

Request::Request(std::istream& CLIENT) : client(CLIENT) { }

void Request::parse() {
    parseRequestLine();
    parseHeaders();

    if(headers.find("content-length") != headers.end())
        parseBody();
}

void Request::parseRequestLine() {
    std::string line;

    std::getline(client, line);
    std::istringstream iss(line);
    std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());
    verb = tokens[0];
    uri = tokens[1];
    httpVersion = tokens[2];
}

void Request::parseHeaders() {
    std::string line;
    std::string key, value;
    while(std::getline(client, line) && !line.empty() && !(line == "\r") ) {
        std::string delimiter = ": ";
        size_t pos = line.find(delimiter);
        key = toLower( line.substr(0, pos) );
        value = line.substr(pos+2);
        headers[key] = value;
    }
}

void Request::parseBody() {
    char* ret = new char[stoi(headers["content-length"])];
    client.read(ret, stoi(headers["content-length"]));
    body = ret;
}

const std::string Request::getVerb() {
    return verb;
}

const std::string Request::getUri() {
    return uri;
}

const std::string Request::getHttpVersion() {
    return httpVersion;
}

char* Request::getBody() {
    return body;
}

std::string Request::toLower(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
    [](unsigned char c){ return std::tolower(c); });
    return str;
}
