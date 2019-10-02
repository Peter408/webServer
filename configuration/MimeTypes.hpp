#ifndef MIMETYPES_HPP
#define MIMETYPES_HPP

#include "ConfigurationReader.hpp"

#include <unordered_map>

class MimeTypes : public ConfigurationReader {
public:
    MimeTypes(std::string);
    void load();
    std::string lookup(std::string);
private:
    std::unordered_map<std::string, std::string> types;
};

#endif