#ifndef HTTPDCONF_HPP
#define HTTPDCONF_HPP

#include <unordered_map>
#include <vector>
#include <functional>

#include "ConfigurationReader.hpp"

class HttpdConf : public ConfigurationReader {
public:
    HttpdConf(std::string fileName);
    void load();
    const std::unordered_map<std::string, std::string>& getAliases();
    const std::unordered_map<std::string, std::string>& getScriptAliases();
    const std::string getDocumentRoot();
    const std::string getLog();
    const uint getPort();
private:
    std::unordered_map<std::string, std::string> aliases;
    std::unordered_map<std::string, std::string> scriptAliases;
    std::string serverRoot;
    std::string documentRoot;
    uint port = 8080;
    std::string logFile;
    std::string accessFile;
    std::string directoryIndex;

    std::unordered_map<std::string, std::function<void(std::vector<std::string>) > > dispatcher;
    std::string removeQuotes(std::string &);
    void createDispatch();
};

#endif