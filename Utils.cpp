#include "Utils.h"

inline bool to_bool(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    if (jsonstr == "true") {
        return true;
    } else {
        return false;
    }
}

inline long to_long(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stol(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

inline long long to_longlong(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stoll(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

inline int to_int(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stoi(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

inline double to_double(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stod(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}


inline nlohmann::json errorHandle(nlohmann::json const & arg, std::string const & q) {
    try {
        return arg[q];
    }catch(std::exception & e) {
        return {};
    }
}

inline std::vector<double> getArr(nlohmann::json const &fulljson) {
    auto arr = std::vector<double>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        arr.push_back(to_double(json));
        i++;
    }
    return arr;
}

inline std::vector<std::string> getBag(nlohmann::json const &fulljson) {
    auto bag = std::vector<std::string>();
    nlohmann::json json;
    int i = 0;
    while (i < fulljson.size()) {
        json = fulljson[i];
        bag.push_back(to_string(json));
        i++;
    }
    return bag;
}

inline nlohmann::json parseJson(std::string const &path) {
    std::ifstream file(path);

    nlohmann::json json = nlohmann::json::parse(file);

    return json;
}




