#include "Parse.h"
#include "imports/json.hpp"
bool to_bool(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    if (jsonstr == "true") {
        return true;
    } else {
        return false;
    }
}

long to_long(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stol(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

long long to_longlong(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stoll(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

int to_int(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stoi(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

double to_double(nlohmann::json const &json) {
    std::string jsonstr = to_string(json);
    try {
        return std::stod(jsonstr);
    } catch (std::invalid_argument &e) {
        return 0;
    }
}

std::vector<double> getArr(nlohmann::json const &fulljson) {
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

AvgTracking getSecondaryAvgTracking(nlohmann::json const &json) {
    try {
        auto avgtracking = AvgTracking(getArr(json["secondaryAvgTracking"]));
        return avgtracking;
    } catch (nlohmann::json::exception &e) {
        return AvgTracking();
    }
}

AvgTracking getTertiaryAvgTracking(nlohmann::json const &json) {
    try {
        auto avgtracking = AvgTracking(getArr(json["tertiaryAvgTracking"]));
        return avgtracking;
    } catch (nlohmann::json::exception &e) {
        return AvgTracking();
    }
}

ExtraAvgTracking getExtraAvgTracking(nlohmann::json const &json) {
    nlohmann::json ison;
    try {
        ison = json["ExtraAvgTracking"];
        auto avgtracking = ExtraAvgTracking(getArr(json["aggregatestats___vsscore"])); //fix this bs pls
        return avgtracking;
    } catch (nlohmann::json::exception &e) {
        return ExtraAvgTracking();
    }
}

std::vector<std::string> getBag(nlohmann::json const &fulljson) {
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

nlohmann::json parseJson(std::string const &path) {
    std::ifstream file(path);

    nlohmann::json json = nlohmann::json::parse(file);

    return json;
}




