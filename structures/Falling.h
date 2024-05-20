//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_FALLING_H
#define TETR_IO_VISULIZER_FALLING_H


class Falling{
public:
    bool sleep;
    bool deep_sleep;
    bool hibernated;
    int locking;
    int lockresets;
    bool forcelock;
    bool floored;
    bool clamped;
    int safelock;
    int x;
    int y;
    int r;
    std::string type;
    int highesty;
    std::string last;
    int lastkick;
    std::string lastrotation;
    int irs;
    bool ihs;
    int aox;
    int aoy;
    int keys;
};


#endif //TETR_IO_VISULIZER_FALLING_H
