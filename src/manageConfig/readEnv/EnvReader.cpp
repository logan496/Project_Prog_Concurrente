//
// Created by wolverine on 12/8/24.
//

#include "EnvReader.h"
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <unordered_map>

std::unordered_map<std::string, std::string> EnvReader::readEnv(const std::string &filename) {
    std::unordered_map<std::string, std::string> envVars;
    std::ifstream file(filename);
    if(!file.is_open()) {
        throw std::runtime_error("EnvReader::readEnv(): File could not be opened");
    }

    std::string line;
    while(std::getline(file, line)) {
        if(line.empty() || line[0] == '#') continue;

        std::stringstream ss(line);
        std::string key, value;
        if(std::getline(ss, key, '=') && std::getline(ss, value)) {
            envVars[key] = value;
        }
    }
    return envVars;
}

std::string EnvReader::getEnvVar(const std::string &key) {
    const char* val = std::getenv(key.c_str());
    if(val) {
        return std::string(val);
    }
    throw std::runtime_error("EnvReader::getEnvVar(): Environment variable not found");
}

