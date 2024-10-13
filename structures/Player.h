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

    static std::vector<Player> getEndcontext(nlohmann::json const &fulljson) {
        auto endcontext = std::vector<Player>();
        try {
            nlohmann::json json;
            int i = 0;

            while (i < fulljson.size()) {
                json = fulljson[i];
                endcontext.push_back(
                    Player(to_string(nullable_handle(json,"id")),
                           to_string(nullable_handle(json,"username")),
                           Handling::getHandling(nullable_handle(json,"handling")),
                           to_bool(nullable_handle(json,"active")),
                           to_bool(nullable_handle(json,"success")),
                           to_int(nullable_handle(json,"inputs")),
                           to_int(nullable_handle(json,"pieceplaced")),
                           to_int(nullable_handle(json,"naturalorder")),
                           to_int(nullable_handle(json,"score")),
                           to_int(nullable_handle(json,"wins")),
                           Points::getPoints(nullable_handle(json,"points")),
                           AvgTracking::getSecondaryAvgTracking(nullable_handle(json,"secondaryAvgTracking")),
                           AvgTracking::getTertiaryAvgTracking(nullable_handle(json,"tertiaryAvgTracking")),
                           ExtraAvgTracking::getExtraAvgTracking(nullable_handle(json,"extraAvgTracking"))));

                i++;
            }

            return endcontext;
        } catch (std::exception &e) {
            return endcontext;
        }
    }
};


#endif //TETR_IO_VISULIZER_PLAYER_H
