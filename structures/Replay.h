//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_REPLAY_H
#define TETR_IO_VISULIZER_REPLAY_H

class Replay {
public:
    static Replay getReplay(nlohmann::json const &json) {
        auto replay = Replay(); //0 fields
        return replay;
    }
};

#endif //TETR_IO_VISULIZER_REPLAY_H
