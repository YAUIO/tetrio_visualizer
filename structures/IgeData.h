//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Target.h"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_IGEDATA_H
#define TETR_IO_VISULIZER_IGEDATA_H

class IgeData{
public:
    std::string type;
    std::string gameid;
    std::vector<Target> targets;
    int frame;
    bool value;
    std::string key;
    bool hoisted;
    int subframe;

    IgeData data;
};

#endif //TETR_IO_VISULIZER_IGEDATA_H
