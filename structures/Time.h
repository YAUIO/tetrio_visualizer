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
#ifndef TETR_IO_VISULIZER_TIME_H
#define TETR_IO_VISULIZER_TIME_H

class Time {
public:
    int start;
    bool zero;
    bool locked;
    int prev;
    int framoffset;

    static Time getTime(nlohmann::json const &json) {
        try {
            auto time = Time(
                to_int(nullable_handle(json,"start")),
                to_bool(nullable_handle(json,"zero")),
                to_bool(nullable_handle(json,"locked")),
                to_int(nullable_handle(json,"prev")),
                to_int(nullable_handle(json,"framoffset"))
            );
            return time;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_TIME_H
