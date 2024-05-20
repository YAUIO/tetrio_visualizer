//
// Created by shira on 5/20/2024.
//
#pragma once
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

    Stats getStats(nlohmann::json const &json) {
        auto stats = Stats(
                to_long(json["seed"]),
                to_int(json["lines"]),
                to_int(json["level_lines"]),
                to_int(json["level_lines_needed"]),
                to_int(json["inputs"]),
                to_int(json["holds"]),
                Time().getTime(json["time"]),
                to_int(json["score"]),
                to_int(json["zenlevel"]),
                to_int(json["zenprogress"]),
                to_int(json["level"]),
                to_int(json["combo"]),
                to_int(json["btb"]),
                to_int(json["topbtb"]),
                to_int(json["currentbtbchainpower"]),
                to_int(json["tspins"]),
                to_int(json["piecesplaced"]),
                Clears().getClears(json["clears"]),
                Garbage().getGarbage(json["garbage"]),
                to_int(json["kills"]),
                Finesse().getFinesse(json["finesse"])
        );
        return stats;
    }
};


#endif //TETR_IO_VISULIZER_STATS_H
