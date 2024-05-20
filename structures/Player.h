//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Handling.h"
#include "Points.h"
#include "AvgTracking.h"
#include "ExtraAvgTracking.h"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_PLAYER_H
#define TETR_IO_VISULIZER_PLAYER_H


class Player {
public:
    std::string id;
    std::string username;
    Handling handling;
    bool active;
    bool success;
    int inputs;
    int pieceplaced;
    int naturalorder;
    int score;
    int wins;
    Points points;
    AvgTracking secondaryAvgTracking;
    AvgTracking tertiaryAvgTracking;
    ExtraAvgTracking extraAvgTracking;
};


#endif //TETR_IO_VISULIZER_PLAYER_H
