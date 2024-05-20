//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "PointsExtra.h"
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.cpp"
#ifndef TETR_IO_VISULIZER_POINTS_H
#define TETR_IO_VISULIZER_POINTS_H

class Points {
public:
    int primary;
    double secondary;
    double tertiary;
    PointsExtra extra;

    Points getPoints(nlohmann::json const &json) {
        auto points = Points(
                to_int(json["primary"]),
                to_double(json["secondary"]),
                to_double(json["tertiary"]),
                PointsExtra().getPointsExtra(json['extra'])
        );
        return points;
    }
};


#endif //TETR_IO_VISULIZER_POINTS_H
