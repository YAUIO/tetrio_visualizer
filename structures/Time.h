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
        try{
        auto time = Time(
                to_int(json["start"]),
                to_bool(json["zero"]),
                to_bool(json["locked"]),
                to_int(json["prev"]),
                to_int(json["framoffset"])
        );
        return time;
        }catch(std::exception & e){
            return Time();
        }
    }
};


#endif //TETR_IO_VISULIZER_TIME_H
