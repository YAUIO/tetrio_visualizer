//
// Created by yudek on 10/13/24.
//
#pragma once
#include <string>
#include <vector>

#include "BoardV.h"
#include "Controlling.h"
#include "Falling.h"
#include "Handling.h"
#include "Hold.h"

struct Game {
    std::vector<std::string> bag;
    std::vector<BoardV> board;
    Controlling controlling;
    Falling falling;
    double g;
    Handling handling;
    Hold hold;
    bool playing;

    static Game getGame(nlohmann::json const& json) {
        try {
            auto game = Game(
            getBag(nullable_handle(json,"bag")),
            BoardV::getBoardV(nullable_handle(json,"board")),
            Controlling::getControlling(nullable_handle(json,"controlling")),
            Falling::getFalling(nullable_handle(json,"falling")),
            to_double(nullable_handle(json,"g")),
            Handling::getHandling(nullable_handle(json,"handling")),
            Hold::getHold(nullable_handle(json,"hold")),
            to_bool(nullable_handle(json,"playing"))
            );

            return game;
        }catch(std::exception & e) {
            return {};
        }
    }

};
