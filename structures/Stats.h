//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Time.h"
#include "Clears.h"
#include "Garbage.h"
#include "Finesse.h"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_STATS_H
#define TETR_IO_VISULIZER_STATS_H


class Stats {
public:
    long seed;
    int lines;
    int level_lines;
    int level_lines_needed;
    int inputs;
    int holds;
    Time time;
    int score;
    int zenlevel;
    int zenprogress;
    int level;
    int combo;
    int btb;
    int topbtb;
    int currentbtbchainpower;
    int tspins;
    int piecesplaced;
    Clears clears;
    Garbage garbage;
    int kills;
    Finesse finesse;
};


#endif //TETR_IO_VISULIZER_STATS_H
