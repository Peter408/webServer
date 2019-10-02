#include "ConfigurationReader.hpp"

ConfigurationReader::ConfigurationReader(std::string fileName) {
    fin.open(fileName);
    load();
}

bool ConfigurationReader::hasMoreLines() {
    return moreLine;
}

std::string ConfigurationReader::nextLine() {
    std::string tmpLine = line;
    load();
    return tmpLine;
}

void ConfigurationReader::load() {
    if(std::getline(fin, line)) {
        moreLine = true;
    } else {
        moreLine = false;
    }
}

void ConfigurationReader::closeFile() {
    fin.close();
}