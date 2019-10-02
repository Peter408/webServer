#ifndef RESOURCE_HPP
#define RESOURCE_HPP

#include <string>
#include <fstream>
#include <unordered_map>

#include "../configuration/HttpdConf.hpp"
#include "../configuration/MimeTypes.hpp"
#include "Request.hpp"

class Resource {
public:
    Resource(Request&, HttpdConf&, MimeTypes&);
    std::ifstream* getServerStream();
    const std::string getHeaderValue(std::string);
    std::unordered_map<std::string, std::string> getHeaders();
    bool getValid();
    const std::string getPath();
    char* getFile();
private:
    std::string path;
    bool isAlias = false;
    bool isScript = false;
    bool isProtected = false;
    bool isValid = false;
    std::string verb;
    char* file;
    std::ifstream serverDocumentStream;
    std::unordered_map<std::string, std::string> headers;

    HttpdConf& config;
    MimeTypes& types;

    void configuration();
    std::string replace(std::string&, const std::string&, const std::string&);
    bool replaceAlias();
    bool replaceScriptAlias();
    void buildPath();
    uint getFileSize(std::string);
    std::string getContentType(std::string);
};

#endif