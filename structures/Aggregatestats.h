//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.cpp"
#ifndef TETR_IO_VISULIZER_AGGREGATESTATS_H
#define TETR_IO_VISULIZER_AGGREGATESTATS_H

class Aggregatestats{
public:
    double apm;
    double pps;
    double vsscore;

    Aggregatestats getAggregatestats(nlohmann::json const &json) {
        auto aggregatestats = Aggregatestats(
                to_double(json["apm"]),
                to_double(json["ppm"]),
                to_double(json["vsscore"])
        );
        return aggregatestats;
    }
};


#endif //TETR_IO_VISULIZER_AGGREGATESTATS_H
