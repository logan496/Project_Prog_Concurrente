//
// Created by wolverine on 12/8/24.
//

#ifndef JSONREADER_H
#define JSONREADER_H

#include <string>
#include <variant>
#include <map>
#include <vector>


class JsonReader {
public:
    using JsonValue = std::variant<std::string, double, bool, std::nullptr_t,
        std::map<std::string, JsonValue>,
        std::vector<JsonValue> >;

    JsonValue readJsonFile(const std::string& filename);
    JsonValue parse(const std::string& jsonString);
private:
    JsonValue parseValue(const std::string& jsonString, size_t& index);
};


#endif //JSONREADER_H
