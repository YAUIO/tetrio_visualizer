//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>

#include "fmt/core.h"
#include "fmt/ranges.h"
#ifndef TETR_IO_VISULIZER_BOARDV_H
#define TETR_IO_VISULIZER_BOARDV_H


class BoardV {
public:
    std::vector<std::string> row;


    static std::vector<std::string> getRow(nlohmann::json const &json) {
        try {
            auto row = std::vector<std::string>();
            nlohmann::json ison;
            int i = 0;
            while (i < json.size()) {
                ison = json[i];
                if (ison == nlohmann::detail::value_t::null) {
                    row.push_back("null");
                } else {
                    row.push_back(to_string(ison));
                }
                i++;
            }
            return row;
        } catch (std::exception &e) {
            return {};
        }
    }

    static std::vector<BoardV> getBoardV(nlohmann::json const &fulljson) {
        try {
            auto boardV = std::vector<BoardV>();
            nlohmann::json json;
            int i = 0;
            while (i < fulljson.size()) {
                json = fulljson[i];
                boardV.push_back(BoardV(getRow(json)));
                i++;
            }
            return boardV;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_BOARDV_H
