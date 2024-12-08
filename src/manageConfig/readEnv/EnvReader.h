//
// Created by wolverine on 12/8/24.
//

#ifndef ENVREADER_H
#define ENVREADER_H

#include <string>
#include <unordered_map>

class EnvReader {
public:
    static std::unordered_map<std::string, std::string> readEnv(const std::string& filename);
    static std::string getEnvVar(const std::string& key);


};
#endif //ENVREADER_H
