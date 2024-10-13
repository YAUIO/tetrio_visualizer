//
// Created by yudek on 10/12/24.
//
#pragma once
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "tEvent.h"

struct Replays {
    std::vector<tEvent> events;

    static std::vector<Replays> getReplays(nlohmann::json const &json) {
        std::vector<Replays> replays = std::vector<Replays>();
        try {
            nlohmann::json ison;
            int i = 0;
            while (i < json.size()) {
                ison = json[i];
                replays.push_back(
                    Replays(tEvent::getEvents(nullable_handle(ison,"events")))
                );
                i++;
            }
            return replays;
        } catch (std::exception &e) {
            return replays;
        }
    }
};
