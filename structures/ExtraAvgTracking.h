//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "../Utils.h"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_EXTRAAVGTRACKING_H
#define TETR_IO_VISULIZER_EXTRAAVGTRACKING_H

class ExtraAvgTracking {
public:
    std::vector<double> aggregatestats___vsscore;

    static ExtraAvgTracking getExtraAvgTracking(nlohmann::json const &json) {
        try {
            auto avgtracking = ExtraAvgTracking(getArr(nullable_handle(json,"aggregatestats___vsscore")));
            return avgtracking;
        } catch (nlohmann::json::exception &e) {
            return {};
        }
    }
};

#endif //TETR_IO_VISULIZER_EXTRAAVGTRACKING_H
