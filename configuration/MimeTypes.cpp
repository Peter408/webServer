#include "MimeTypes.hpp"

#include <iostream>
#include <sstream>
#include <vector>

MimeTypes::MimeTypes(std::string fileName) : ConfigurationReader(fileName) { }

void MimeTypes::load() {
    while(hasMoreLines()) {
        std::istringstream iss(nextLine());
        std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());
        if(tokens.size() <= 1)
            continue;
        for(auto it = ++tokens.begin(); it != tokens.end(); ++it) {
            if(*tokens.begin() == "#")
                continue;
            types[*it] = *tokens.begin();
        }
    }
    closeFile();
}

std::string MimeTypes::lookup(std::string extention) {
    if(extention.empty()) {
        return NULL;
    }
    return types[extention];
}
