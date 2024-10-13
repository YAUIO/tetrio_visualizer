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

    static Stats getStats(nlohmann::json const &json) {
        try {
            auto stats = Stats(
                to_long(nullable_handle(json,"seed")),
                to_int(nullable_handle(json,"lines")),
                to_int(nullable_handle(json,"level_lines")),
                to_int(nullable_handle(json,"level_lines_needed")),
                to_int(nullable_handle(json,"inputs")),
                to_int(nullable_handle(json,"holds")),
                Time::getTime(nullable_handle(json,"time")),
                to_int(nullable_handle(json,"score")),
                to_int(nullable_handle(json,"zenlevel")),
                to_int(nullable_handle(json,"zenprogress")),
                to_int(nullable_handle(json,"level")),
                to_int(nullable_handle(json,"combo")),
                to_int(nullable_handle(json,"btb")),
                to_int(nullable_handle(json,"topbtb")),
                to_int(nullable_handle(json,"currentbtbchainpower")),
                to_int(nullable_handle(json,"tspins")),
                to_int(nullable_handle(json,"piecesplaced")),
                Clears::getClears(nullable_handle(json,"clears")),
                Garbage::getGarbage(nullable_handle(json,"garbage")),
                to_int(nullable_handle(json,"kills")),
                Finesse::getFinesse(nullable_handle(json,"finesse"))
            );
            return stats;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_STATS_H
