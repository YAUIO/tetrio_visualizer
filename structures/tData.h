//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "IgeData.h"
#include "Replay.h"
#include "Source.h"
#include "Options.h"
#include "Stats.h"
#include "Enemy.h"
#include "BoardV.h"
#include "Hold.h"
#include "Controlling.h"
#include "Falling.h"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_TDATA_H
#define TETR_IO_VISULIZER_TDATA_H


class tData {
public:
    int id;
    int frame;
    std::string type;
    IgeData data;
    int cid;

    bool successful;
    std::string gameoverreason;
    Replay replay;
    Source source;
    Options options;
    Stats stats;
    int diyusi;
    std::vector<Enemy> enemies;
    std::vector<Target> targets;
    int fire;
    std::vector<BoardV> board;
    std::vector<std::string> bag;
    Hold hold;
    double g;
    Controlling controlling;
    Falling falling;
    Handling handling;
    bool playing;
};


#endif //TETR_IO_VISULIZER_TDATA_H
