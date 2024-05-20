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

    tData gettData(nlohmann::json const &json) {
        auto tdata = tData(
                to_int(json["id"]),
                to_int(json["frame"]),
                to_string(json["type"]),
                IgeData().getIgeData(json["data"]),
                to_int(json["cid"]),
                to_bool(json["successful"]),
                to_string(json["gameoverreason"]),
                Replay().getReplay(json["replay"]),
                Source().getSource(json["source"]),
                Options().getOptions(json["options"]),
                getStats(json["stats"]),
                to_int(json["diyusi"]),
                getEnemy(json["enemies"]),
                getTarget(json["targets"]),
                to_int(json["fire"]),
                getBoardV(json["board"]),
                getBag(json["bag"]),
                Hold().getHold(json["hold"]),
                to_double(json["g"]),
                Controlling().getControlling(json["controlling"]),
                Falling().getFalling(json["falling"]),
                Handling().getHandling(json["handling"]),
                to_bool(json["playing"])
        );

        return tdata;
    }
};


#endif //TETR_IO_VISULIZER_TDATA_H
