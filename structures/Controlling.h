//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_CONTROLLING_H
#define TETR_IO_VISULIZER_CONTROLLING_H

class Controlling{
public:
    int ldas;
    int ldasiter;
    bool lshift;
    int rdas;
    int rdasiter;
    bool rshift;
    int lastshift;
    bool softdrop;
};


#endif //TETR_IO_VISULIZER_CONTROLLING_H
