//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_POINTSEXTRA_H
#define TETR_IO_VISULIZER_POINTSEXTRA_H

class PointsExtra {
public:
    std::string vs;

    static PointsExtra getPointsExtra(nlohmann::json const &json) {
        try{
        auto pointsExtra = PointsExtra(to_string(json["vs"]));
        return pointsExtra;
        }catch(std::exception & e){
            return PointsExtra();
        }
    }
};


#endif //TETR_IO_VISULIZER_POINTSEXTRA_H
