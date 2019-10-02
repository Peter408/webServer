#include "HttpdConf.hpp"

#include <iostream>
#include <sstream>
#include <algorithm>

HttpdConf::HttpdConf(std::string fileName) : ConfigurationReader(fileName) {
    createDispatch();
}

void HttpdConf::load() {
    while(hasMoreLines()) {
        std::istringstream iss(nextLine());
        std::vector<std::string> tokens((std::istream_iterator<std::string>(iss)),
                                        std::istream_iterator<std::string>());
        dispatcher[tokens[0]](tokens);
    }
    closeFile();
}

std::string HttpdConf::removeQuotes(std::string &str) {
    str.erase(remove( str.begin(), str.end(), '\"' ),str.end());
    return str;
}

void HttpdConf::createDispatch() {
    dispatcher = {
        {"ServerRoot", [&](std::vector<std::string> tokens) {
            serverRoot = removeQuotes(tokens[1]); 
        }},
        {"DocumentRoot", [&](std::vector<std::string> tokens) {
            documentRoot = removeQuotes(tokens[1]); 
        }},
        {"Listen", [&](std::vector<std::string> tokens) {
            port = std::stoi(tokens[1]);
        }},
        {"LogFile", [&](std::vector<std::string> tokens) {
            logFile = removeQuotes(tokens[1]);
        }},
        {"ScriptAlias", [&](std::vector<std::string> tokens) {
            scriptAliases [tokens[1]] = removeQuotes(tokens[2]);
        }},
        {"Alias", [&](std::vector<std::string> tokens) {
            aliases [tokens[1]] = removeQuotes(tokens[2]);
        }},
        {"AccessFile", [&](std::vector<std::string> tokens) {
            accessFile = removeQuotes(tokens[1]);
        }},
        {"DirectoryIndex", [&](std::vector<std::string> tokens) {
            directoryIndex = removeQuotes(tokens[1]);
        }}
    };
}

const std::unordered_map<std::string, std::string>& HttpdConf::getAliases() {
    return aliases;
}

const std::unordered_map<std::string, std::string>& HttpdConf::getScriptAliases() {
    return scriptAliases;
}

const std::string HttpdConf::getDocumentRoot() {
    return documentRoot;
}

const std::string HttpdConf::getLog() {
    return logFile;
}

const uint HttpdConf::getPort() {
    return port;
}
