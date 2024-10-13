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

    static Minoskin getMinoskin(nlohmann::json const &json) {
        try {
            auto minoskin = Minoskin(
                to_string(nullable_handle(json,"z")),
                to_string(nullable_handle(json,"l")),
                to_string(nullable_handle(json,"o")),
                to_string(nullable_handle(json,"s")),
                to_string(nullable_handle(json,"i")),
                to_string(nullable_handle(json,"j")),
                to_string(nullable_handle(json,"t")),
                to_string(nullable_handle(json,"other"))
            );
            return minoskin;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_MINOSKIN_H
