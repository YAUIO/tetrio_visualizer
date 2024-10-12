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
        try{
        auto igedata = IgeData(
                to_string(json["type"]),
                to_string(json["gameid"]),
                Target::getTarget(json["targets"]),
                to_int(json["frame"]),
                to_bool(json["value"]),
                to_string(json["key"]),
                to_bool(json["hoisted"]),
                to_int(json["subframe"]),
                IntData::getIntData(json["data"])
        );
        return igedata;
        }catch(std::exception & e){
            return IgeData();
        }
    }
};

#endif //TETR_IO_VISULIZER_IGEDATA_H
