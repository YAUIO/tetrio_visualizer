//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
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
};


#endif //TETR_IO_VISULIZER_TIME_H
