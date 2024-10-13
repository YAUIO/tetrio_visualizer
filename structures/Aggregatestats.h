//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.h"
#ifndef TETR_IO_VISULIZER_AGGREGATESTATS_H
#define TETR_IO_VISULIZER_AGGREGATESTATS_H

class Aggregatestats{
public:
    double apm;
    double pps;
    double vsscore;

    static Aggregatestats getAggregatestats(nlohmann::json const &json) {
        try{
            auto aggregatestats = Aggregatestats(
                    to_double(nullable_handle(json,"apm")),
                    to_double(nullable_handle(json,"ppm")),
                    to_double(nullable_handle(json,"vsscore"))
            );
            return aggregatestats;
        }catch(std::exception & e){
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_AGGREGATESTATS_H
