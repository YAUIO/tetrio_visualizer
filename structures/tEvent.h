//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "tData.h"
#include "Killer.h"
#include "Aggregatestats.h.h"
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_TEVENT_H
#define TETR_IO_VISULIZER_TEVENT_H

class tEvent {
public:
    int frame;
    std::string type;
    tData data;
    Killer killer;
    Aggregatestats aggregatestats;
};


#endif //TETR_IO_VISULIZER_TEVENT_H
