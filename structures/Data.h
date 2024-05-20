//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.cpp"
#include "tEvent.h"
#include "Board.h"

#ifndef TETR_IO_VISULIZER_DATA_H
#define TETR_IO_VISULIZER_DATA_H

class Data {
public:
    std::vector<Board> board;
    int frames;
    std::vector<tEvent> events;

    std::vector<Data> getData(nlohmann::json const &fulljson) {
        auto data = std::vector<Data>();
        nlohmann::json json;
        int i = 0;
        while (i < fulljson.size()) {
            json = fulljson[i];
            data.push_back(
                    Data(Board().getBoard(json["board"]),
                         to_int(json["frames"]),
                         tEvent().getEvents(json["events"]))
            );
            i++;
        }
        return data;
    }
};


#endif //TETR_IO_VISULIZER_DATA_H
