#ifndef CONFIGURATIONREADER_HPP
#define CONFIGURATIONREADER_HPP

#include <fstream>
#include <string>

class ConfigurationReader {
private:
    std::ifstream fin;
    std::string line;
    bool moreLine;
protected:
    void closeFile();
public:
    ConfigurationReader(std::string fileName);
    bool hasMoreLines();
    std::string nextLine();
    void load();
};

#endif