//
// Created by yudek on 5/20/24.
//

#ifndef TETR_IO_VISULIZER_UTILS_H
#define TETR_IO_VISULIZER_UTILS_H
#pragma once
#include <fstream>
#include "imports/json.hpp"

inline bool to_bool(nlohmann::json const &json);

inline long to_long(nlohmann::json const &json);

inline long long to_longlong(nlohmann::json const &json);

inline int to_int(nlohmann::json const &json);

inline double to_double(nlohmann::json const &json);

inline std::vector<double> getArr(nlohmann::json const &fulljson);

inline std::vector<std::string> getBag(nlohmann::json const &fulljson);

inline nlohmann::json parseJson(std::string const &path);

#endif //TETR_IO_VISULIZER_UTILS_H
