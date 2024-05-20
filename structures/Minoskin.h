//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_MINOSKIN_H
#define TETR_IO_VISULIZER_MINOSKIN_H


class Minoskin {
public:
    std::string z;
    std::string l;
    std::string o;
    std::string s;
    std::string i;
    std::string j;
    std::string t;
    std::string other;

    Minoskin getMinoskin(nlohmann::json const &json) {
        auto minoskin = Minoskin(
                to_string(json["z"]),
                to_string(json["l"]),
                to_string(json["o"]),
                to_string(json["s"]),
                to_string(json["i"]),
                to_string(json["j"]),
                to_string(json["t"]),
                to_string(json["other"])
        );
        return minoskin;
    }
};


#endif //TETR_IO_VISULIZER_MINOSKIN_H
