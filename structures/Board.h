//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.h"
#ifndef TETR_IO_VISULIZER_BOARD_H
#define TETR_IO_VISULIZER_BOARD_H


class Board {
public:
    std::string id;
    std::string username;
    bool active;
    bool success;

    static std::vector<Board> getBoard(nlohmann::json const &fulljson) {
        try {
            auto board = std::vector<Board>();
            nlohmann::json json;
            int i = 0;
            while (i < fulljson.size()) {
                json = fulljson[i];
                board.push_back(
                    Board(to_string(nullable_handle(json, "id")),
                          to_string(nullable_handle(json, "username")),
                          to_bool(nullable_handle(json, "active")),
                          to_bool(nullable_handle(json, "success")))
                );
                i++;
            }
            return board;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_BOARD_H
