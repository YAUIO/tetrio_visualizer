//
// Created by shira on 5/20/2024.
//
#pragma once
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
#include <json.hpp>
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

    static tData gettData(nlohmann::json const &json) {

        try {
            auto tdata = tData(
                to_int(errorHandle(json,"id")),
                to_int(errorHandle(json,"frame")),
                to_string(errorHandle(json,"type")),
                IgeData::getIgeData(errorHandle(json,"data")),
                to_int(errorHandle(json,"cid")),
                to_bool(errorHandle(json,"successful")),
                to_string(errorHandle(json,"gameoverreason")),
                Replay::getReplay(errorHandle(json,"replay")),
                Source::getSource(errorHandle(json,"source")),
                Options::getOptions(errorHandle(json,"options")),
                Stats::getStats(errorHandle(json,"stats")),
                to_int(errorHandle(json,"diyusi")),
                Enemy::getEnemy(errorHandle(json,"enemies")),
                Target::getTarget(errorHandle(json,"targets")),
                to_int(errorHandle(json,"fire")),
                BoardV::getBoardV(errorHandle(json,"board")),
                getBag(errorHandle(json,"bag")),
                Hold::getHold(errorHandle(json,"hold")),
                to_double(errorHandle(json,"g")),
                Controlling::getControlling(errorHandle(json,"controlling")),
                Falling::getFalling(errorHandle(json,"falling")),
                Handling::getHandling(errorHandle(json,"handling")),
                to_bool(errorHandle(json,"playing"))
            );

            return tdata;
        } catch (std::exception & e) {
            fmt::println("returned null at tdata");
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_TDATA_H
