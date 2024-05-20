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

    std::vector<Board> getBoard(nlohmann::json const &fulljson) {
        auto board = std::vector<Board>();
        nlohmann::json json;
        int i = 0;
        while (i < fulljson.size()) {
            json = fulljson[i];
            board.push_back(
                    Board(to_string(json["id"]),
                          to_string(json["username"]),
                          to_bool(json["active"]),
                          to_bool(json["success"]))
            );
            i++;
        }
        return board;
    }
};



#endif //TETR_IO_VISULIZER_BOARD_H
