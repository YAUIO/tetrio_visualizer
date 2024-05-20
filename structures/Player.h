//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Handling.h"
#include "Points.h"
#include "AvgTracking.h"
#include "ExtraAvgTracking.h"
#include <fstream>
#include <iostream>
#include "../Utils.h"

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

    std::vector<Player> getEndcontext(nlohmann::json const &fulljson) {
        auto endcontext = std::vector<Player>();
        nlohmann::json json;
        int i = 0;

        while (i < fulljson.size()) {
            json = fulljson[i];
            endcontext.push_back(
                    Player(to_string(json["id"]),
                           to_string(json["username"]),
                           Handling().getHandling(json["handling"]),
                           to_bool(json["active"]),
                           to_bool(json["success"]),
                           to_int(json["inputs"]),
                           to_int(json["pieceplaced"]),
                           to_int(json["naturalorder"]),
                           to_int(json["score"]),
                           to_int(json["wins"]),
                           Points::getPoints(json["points"]),
                           AvgTracking::getSecondaryAvgTracking(json["secondaryAvgTracking"]),
                           AvgTracking::getTertiaryAvgTracking(json["tertiaryAvgTracking"]),
                           ExtraAvgTracking::getExtraAvgTracking(json["extraAvgTracking"])));

            i++;
        }

        return endcontext;
    }
};


#endif //TETR_IO_VISULIZER_PLAYER_H
