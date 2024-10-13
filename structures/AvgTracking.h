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
#ifndef TETR_IO_VISULIZER_AVGTRACKING_H
#define TETR_IO_VISULIZER_AVGTRACKING_H

class AvgTracking {
public:
    std::vector<double> arr;

    static AvgTracking getSecondaryAvgTracking(nlohmann::json const &json) {
        try {
            auto avgtracking = AvgTracking(getArr(nullable_handle(json,"secondaryAvgTracking")));
            return avgtracking;
        } catch (nlohmann::json::exception &e) {
            return {};
        }
    }

    static AvgTracking getTertiaryAvgTracking(nlohmann::json const &json) {
        try {
            auto avgtracking = AvgTracking(getArr(nullable_handle(json,"tertiaryAvgTracking")));
            return avgtracking;
        } catch (nlohmann::json::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_AVGTRACKING_H
