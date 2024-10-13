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
#include "Replays.h"
#include "tEvent.h"
#include "Board.h"

#ifndef TETR_IO_VISULIZER_DATA_H
#define TETR_IO_VISULIZER_DATA_H

class Data {
public:
    std::vector<Board> board;
    int frames;
    std::vector<Replays> replays;


    static std::vector<Data> getData(nlohmann::json const &fulljson) {
        auto data = std::vector<Data>();
        try {
            nlohmann::json json;
            int i = 0;
            while (i < fulljson.size()) {
                json = fulljson[i];
                data.push_back(
                    Data(Board::getBoard(nullable_handle(json, "board")),
                         to_int(nullable_handle(json, "frames")),
                         Replays::getReplays(nullable_handle(json, "replays")))
                );
                i++;
            }
            return data;
        } catch (std::exception &e) {
            return data;
        }
    }
};


#endif //TETR_IO_VISULIZER_DATA_H
