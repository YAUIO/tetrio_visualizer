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

#include "Game.h"
#include "fmt/chrono.h"
#ifndef TETR_IO_VISULIZER_TDATA_H
#define TETR_IO_VISULIZER_TDATA_H


class tData {
public:
    int id;
    int frame;
    std::string type;
    IgeData data;
    int cid;

    bool hoisted;

    std::string key;
    double subframe;

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
    Game game;

    static tData gettData(nlohmann::json const &json) {
        try {
            auto tdata = tData(
                to_int(nullable_handle(json, "id")),
                to_int(nullable_handle(json, "frame")),
                to_string(nullable_handle(json, "type")),
                IgeData::getIgeData(nullable_handle(json, "data")),
                to_int(nullable_handle(json, "cid")),
                to_bool(nullable_handle(json, "hoisted")),
                to_string(nullable_handle(json, "key")),
                to_double(nullable_handle(json, "subframe")),
                to_bool(nullable_handle(json, "successful")),
                to_string(nullable_handle(json, "gameoverreason")),
                Replay::getReplay(nullable_handle(json, "replay")),
                Source::getSource(nullable_handle(json, "source")),
                Options::getOptions(nullable_handle(json, "options")),
                Stats::getStats(nullable_handle(json, "stats")),
                to_int(nullable_handle(json, "diyusi")),
                Enemy::getEnemy(nullable_handle(json, "enemies")),
                Target::getTarget(nullable_handle(json, "targets")),
                to_int(nullable_handle(json, "fire")),
                Game::getGame(nullable_handle(json, "game"))
            );

            return tdata;
        } catch (std::exception &e) {
            fmt::println("returned null at tdata");
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_TDATA_H
