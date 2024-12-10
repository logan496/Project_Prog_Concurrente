#include "JsonReader.hpp"
#include <fstream>
#include <stdexcept>
#include <cctype>

// Lire un fichier JSON
JsonReader::JsonValue JsonReader::readJsonFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Impossible d'ouvrir le fichier JSON : " + filename);
    }

    std::string jsonString((std::istreambuf_iterator<char>(file)),
                            std::istreambuf_iterator<char>());
    return parse(jsonString);
}

// Analyser une chaîne JSON
JsonReader::JsonValue JsonReader::parse(const std::string& jsonString) {
    size_t index = 0;
    return parseValue(jsonString, index);
}

// Fonctions internes pour analyser les différents types
JsonReader::JsonValue JsonReader::parseValue(const std::string& jsonString, size_t& index) {
    skipWhitespace(jsonString, index);

    if (jsonString[index] == '{') return parseObject(jsonString, index);
    if (jsonString[index] == '[') return parseArray(jsonString, index);
    if (jsonString[index] == '"') return parseString(jsonString, index);
    if (std::isdigit(jsonString[index]) || jsonString[index] == '-') return parseNumber(jsonString, index);
    if (jsonString.substr(index, 4) == "true" || jsonString.substr(index, 5) == "false") return parseBoolean(jsonString, index);
    if (jsonString.substr(index, 4) == "null") return parseNull(jsonString, index);

    throw std::runtime_error("Valeur JSON invalide à l'index " + std::to_string(index));
}

std::string JsonReader::parseString(const std::string& jsonString, size_t& index) {
    if (jsonString[index] != '"') {
        throw std::runtime_error("Chaîne attendue à l'index " + std::to_string(index));
    }
    index++; // Sauter le guillemet ouvrant

    std::string result;
    while (index < jsonString.size() && jsonString[index] != '"') {
        if (jsonString[index] == '\\') {
            index++;
            if (jsonString[index] == 'n') result += '\n';
            else if (jsonString[index] == 't') result += '\t';
            else if (jsonString[index] == '"') result += '"';
            else result += jsonString[index];
        } else {
            result += jsonString[index];
        }
        index++;
    }
    if (index >= jsonString.size() || jsonString[index] != '"') {
        throw std::runtime_error("Chaîne non terminée à l'index " + std::to_string(index));
    }
    index++; // Sauter le guillemet fermant
    return result;
}

double JsonReader::parseNumber(const std::string& jsonString, size_t& index) {
    size_t start = index;
    while (index < jsonString.size() && (std::isdigit(jsonString[index]) || jsonString[index] == '.' || jsonString[index] == '-')) {
        index++;
    }
    return std::stod(jsonString.substr(start, index - start));
}

bool JsonReader::parseBoolean(const std::string& jsonString, size_t& index) {
    if (jsonString.substr(index, 4) == "true") {
        index += 4;
        return true;
    } else if (jsonString.substr(index, 5) == "false") {
        index += 5;
        return false;
    }
    throw std::runtime_error("Valeur booléenne invalide à l'index " + std::to_string(index));
}

std::nullptr_t JsonReader::parseNull(const std::string& jsonString, size_t& index) {
    if (jsonString.substr(index, 4) == "null") {
        index += 4;
        return nullptr;
    }
    throw std::runtime_error("Valeur nulle invalide à l'index " + std::to_string(index));
}

std::map<std::string, JsonReader::JsonValue> JsonReader::parseObject(const std::string& jsonString, size_t& index) {
    if (jsonString[index] != '{') {
        throw std::runtime_error("Objet attendu à l'index " + std::to_string(index));
    }
    index++; // Sauter '{'

    std::map<std::string, JsonValue> object;
    skipWhitespace(jsonString, index);

    while (index < jsonString.size() && jsonString[index] != '}') {
        skipWhitespace(jsonString, index);
        std::string key = parseString(jsonString, index);
        skipWhitespace(jsonString, index);

        if (jsonString[index] != ':') {
            throw std::runtime_error("':' attendu à l'index " + std::to_string(index));
        }
        index++; // Sauter ':'

        JsonValue value = parseValue(jsonString, index);
        object[key] = value;

        skipWhitespace(jsonString, index);
        if (jsonString[index] == ',') {
            index++; // Sauter ','
        } else if (jsonString[index] != '}') {
            throw std::runtime_error("',' ou '}' attendu à l'index " + std::to_string(index));
        }
    }
    if (index >= jsonString.size() || jsonString[index] != '}') {
        throw std::runtime_error("Objet non terminé à l'index " + std::to_string(index));
    }
    index++; // Sauter '}'
    return object;
}

std::vector<JsonReader::JsonValue> JsonReader::parseArray(const std::string& jsonString, size_t& index) {
    if (jsonString[index] != '[') {
        throw std::runtime_error("Tableau attendu à l'index " + std::to_string(index));
    }
    index++; // Sauter '['

    std::vector<JsonValue> array;
    skipWhitespace(jsonString, index);

    while (index < jsonString.size() && jsonString[index] != ']') {
        JsonValue value = parseValue(jsonString, index);
        array.push_back(value);

        skipWhitespace(jsonString, index);
        if (jsonString[index] == ',') {
            index++; // Sauter ','
        } else if (jsonString[index] != ']') {
            throw std::runtime_error("',' ou ']' attendu à l'index " + std::to_string(index));
        }
    }
    if (index >= jsonString.size() || jsonString[index] != ']') {
        throw std::runtime_error("Tableau non terminé à l'index " + std::to_string(index));
    }
    index++; // Sauter ']'
    return array;
}

void JsonReader::skipWhitespace(const std::string& jsonString, size_t& index) {
    while (index < jsonString.size() && std::isspace(jsonString[index])) {
        index++;
    }
}
