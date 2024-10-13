//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Target.h"
#include <fstream>
#include <iostream>
#include "IntData.h"
#include "../Utils.h"

#ifndef TETR_IO_VISULIZER_IGEDATA_H
#define TETR_IO_VISULIZER_IGEDATA_H

class IgeData {
public:
    std::string type;
    std::string gameid;
    std::vector<Target> targets;
    int frame;
    bool value;
    std::string key;
    bool hoisted;
    int subframe;

    IntData data;

    static IgeData getIgeData(nlohmann::json const &json) {
        try {
            auto igedata = IgeData(
                to_string(nullable_handle(json, "type")),
                to_string(nullable_handle(json, "gameid")),
                Target::getTarget(nullable_handle(json, "targets")),
                to_int(nullable_handle(json, "frame")),
                to_bool(nullable_handle(json, "value")),
                to_string(nullable_handle(json, "key")),
                to_bool(nullable_handle(json, "hoisted")),
                to_int(nullable_handle(json, "subframe")),
                IntData::getIntData(nullable_handle(json, "data"))
            );
            return igedata;
        } catch (std::exception &e) {
            return {};
        }
    }
};

#endif //TETR_IO_VISULIZER_IGEDATA_H
