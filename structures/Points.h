//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "PointsExtra.h"
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_POINTS_H
#define TETR_IO_VISULIZER_POINTS_H

class Points {
public:
    int primary;
    double secondary;
    double tertiary;
    PointsExtra extra;
};


#endif //TETR_IO_VISULIZER_POINTS_H
