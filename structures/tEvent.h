//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "tData.h"
#include "Killer.h"
#include "Aggregatestats.h"
#include "../Utils.h"
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_TEVENT_H
#define TETR_IO_VISULIZER_TEVENT_H

class tEvent {
public:
    int frame;
    std::string type;
    tData data;
    Killer killer;
    Aggregatestats aggregatestats;

    static std::vector<tEvent> getEvents(nlohmann::json const &fulljson) {
        auto events = std::vector<tEvent>();
        try {
            nlohmann::json json;
            int i = 0;
            while (i < fulljson.size()) {
                json = fulljson[i];
                events.push_back(
                    tEvent(to_int(nullable_handle(json,"frame")),
                           to_string(nullable_handle(json,"type")),
                           tData::gettData(nullable_handle(json,"data")),
                           Killer::getKiller(nullable_handle(json,"killer")),
                           Aggregatestats::getAggregatestats(nullable_handle(json,"aggregatestats"))
                    ));
                i++;
            }
            return events;
        } catch (std::exception &e) {
            return events;
        }
    }
};


#endif //TETR_IO_VISULIZER_TEVENT_H
