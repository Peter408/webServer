#include "Resource.hpp"

#include <iostream>
#include <sstream>

Resource::Resource(Request& request, HttpdConf& CONFIG, MimeTypes& TYPES) : path(request.getUri()), config(CONFIG), types(TYPES) {
    file = request.getBody();
    verb = request.getVerb();
    configuration();
}

void Resource::configuration() {
    isAlias = replaceAlias();
    buildPath();

    serverDocumentStream.open(path);
    isValid = serverDocumentStream ? true : false;

    if(verb == "HEAD" || verb == "GET") {
    headers["Content-Length"] = std::to_string(getFileSize(path));
    headers["Context-Type"] = getContentType(path);
    }
}

bool Resource::replaceAlias() {
    for(auto pair : config.getAliases()) {
        if(path.find(pair.first) != std::string::npos) {
            replace(path, pair.first, pair.second);
            return true;
        }
    }
    return false;
}

// TODO: implement script alias
bool Resource::replaceScriptAlias() {
    for(auto pair : config.getScriptAliases()) {
        if(path.find(pair.first) != std::string::npos) {
            return true;
        }
    }
    return false;
}

void Resource::buildPath() {
    std::string doc = config.getDocumentRoot();
    if(!isAlias)
        path = doc + path.substr(1);
    if(path.back() == '/' && !( verb == "PUT" || verb == "POST" ) )
        path += "index.html";
}

uint Resource::getFileSize(std::string arg_path) {
    std::ifstream in(arg_path, std::ifstream::ate | std::ifstream::binary);
    return in.tellg();
}

std::string Resource::getContentType(std::string arg_path) {
    std::string filename;
    std::size_t found = arg_path.find_last_of("/\\");
    filename = path.substr(found + 1);

    found = filename.find_last_of("\\.");
    std::string extension = filename.substr(found + 1);
    
    return types.lookup(extension);   
}

std::string Resource::replace(std::string& str, const std::string& toReplace, const std::string& replaceWith) {
    std::size_t pos = str.find(toReplace);
    if (pos == std::string::npos) return str;
    return str.replace(pos, toReplace.length(), replaceWith);
}

std::ifstream* Resource::getServerStream() {
    return &serverDocumentStream;
}

const std::string Resource::getHeaderValue(std::string key) {
    if(headers.find(key) != headers.end())
        return headers[key];
    return "";
}

std::unordered_map<std::string, std::string> Resource::getHeaders() {
    return headers;
}

bool Resource::getValid() {
    return isValid;
}

const std::string Resource::getPath() {
    return path;
}

char* Resource::getFile() {
    return file;
}
