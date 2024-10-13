//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "PointsExtra.h"
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.h"
#ifndef TETR_IO_VISULIZER_POINTS_H
#define TETR_IO_VISULIZER_POINTS_H

class Points {
public:
    int primary;
    double secondary;
    double tertiary;
    PointsExtra extra;

    static Points getPoints(nlohmann::json const &json) {
        try {
            auto points = Points(
                to_int(json["primary"]),
                to_double(json["secondary"]),
                to_double(json["tertiary"]),
                PointsExtra::getPointsExtra(json["extra"])
            );
            return points;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_POINTS_H
