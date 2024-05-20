//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "tData.h"
#include "Killer.h"
#include "Aggregatestats.h"
#include "../Utils.cpp"
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

    std::vector<tEvent> getEvents(nlohmann::json const &fulljson) {
        auto events = std::vector<tEvent>();
        nlohmann::json json;
        int i = 0;
        while (i < fulljson.size()) {
            json = fulljson[i];
            events.push_back(
                    tEvent(to_int(json["frame"]),
                           to_string(json["type"]),
                           tData().gettData(json["data"]),
                           Killer().getKiller(json["killer"]),
                           Aggregatestats().getAggregatestats(json["aggregatestats"]))
            );
            i++;
        }
        return events;
    }
};


#endif //TETR_IO_VISULIZER_TEVENT_H
