//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Objective.h"
#include "Handling.h"
#include "Minoskin.h"
#include "ConstantsOverrides.h"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_OPTIONS_H
#define TETR_IO_VISULIZER_OPTIONS_H


class Options {
public:
    int version;
    bool seed_random;
    double g;
    bool countdown;
    int countdown_count;
    int countdown_interval;
    int precountdown;
    int prestart;
    std::string mission;
    std::string mission_type;
    std::string zoominto;
    std::string slot_counter1;
    std::string slot_counter2;
    std::string slot_counter3;
    std::string slot_counter5;
    std::string slot_bar1;
    bool display_fire;
    bool display_username;
    bool hasgarbage;
    bool bgmnoreset;
    bool neverstopbgm;
    bool display_next;
    bool display_hold;
    bool infinite_hold;
    int gmargin;
    double gincrease;
    int garbagecap;
    int garbagecapincrease;
    int garbagecapmax;
    bool garbageabsolutecap;
    int garbageholesize;
    bool garbagephase;
    bool garbagequeue;
    int garbageare;
    std::string garbageentry;
    std::string garbageblocking;
    std::string garbagetargetbonus;
    std::string presets;
    std::string bagtype;
    std::string spinbonuses;
    std::string combotable;
    std::string kickset;
    int nextcount;
    bool allow_harddrop;
    bool display_shadow;
    int locktime;
    int garbagespeed;
    int forfeit_time;
    int are;
    int lineclear_are;
    bool infinitemovement;
    int lockresets;
    bool allow180;
    Objective objective;
    bool room_handling;
    int room_handling_arr;
    int room_handling_das;
    int room_handling_sdf;
    bool manual_allowed;
    bool b2bchaining;
    bool allclears;
    bool clutch;
    bool nolockout;
    std::string passthrough;
    bool can_undo;
    bool can_retry;
    bool retryisclear;
    bool noextrawidth;
    bool stride;
    int boardwidth;
    int boardheight;
    bool new_payback;
    int messiness_change;
    int messiness_inner;
    bool messiness_nosame;
    int messiness_timeout;
    bool usebombs;
    std::string song;
    std::string latencypreference;
    Handling handling;
    int fulloffset;
    int fullinterval;
    std::string gameid;
    std::string username;
    Constants_overrides constantsoverrides;
    bool gravitymax20g;
    bool garbageattackcap;
    bool nosound;
    bool shielded;
    int boardbuffer;
    int survival_cap;
    int survival_timer_itv;
    int survival_layer_min;
    Minoskin minoskin;
    std::string ghostskin;
    std::string boardskin;

    static Options getOptions(nlohmann::json const &json) {
        auto options = Options(
                to_int(json["version"]),
                to_bool(json["seed_random"]),
                to_double(json["g"]),
                to_bool(json["countdown"]),
                to_int(json["countdown_count"]),
                to_int(json["countdown_interval"]),
                to_int(json["precountdown"]),
                to_int(json["prestart"]),
                to_string(json["mission"]),
                to_string(json["mission_type"]),
                to_string(json["zoominto"]),
                to_string(json["slot_counter1"]),
                to_string(json["slot_counter2"]),
                to_string(json["slot_counter3"]),
                to_string(json["slot_counter5"]),
                to_string(json["slot_bar1"]),
                to_bool(json["display_fire"]),
                to_bool(json["display_username"]),
                to_bool(json["hasgarbage"]),
                to_bool(json["bgmnoreset"]),
                to_bool(json["neverstopbgm"]),
                to_bool(json["display_next"]),
                to_bool(json["display_hold"]),
                to_bool(json["infinite_hold"]),
                to_int(json["gmargin"]),
                to_double(json["gincrease"]),
                to_int(json["garbagecap"]),
                to_int(json["garbagecapincrease"]),
                to_int(json["garbagecapmax"]),
                to_bool(json["garbageabsolutecap"]),
                to_int(json["garbageholesize"]),
                to_bool(json["garbagephase"]),
                to_bool(json["garbagequeue"]),
                to_int(json["garbageare"]),
                to_string(json["garbageentry"]),
                to_string(json["garbageblocking"]),
                to_string(json["garbagetargetbonus"]),
                to_string(json["presets"]),
                to_string(json["bagtype"]),
                to_string(json["spinbonuses"]),
                to_string(json["combotable"]),
                to_string(json["kickset"]),
                to_int(json["nextcount"]),
                to_bool(json["allow_harddrop"]),
                to_bool(json["display_shadow"]),
                to_int(json["locktime"]),
                to_int(json["garbagespeed"]),
                to_int(json["forfeit_time"]),
                to_int(json["are"]),
                to_int(json["lineclear_are"]),
                to_bool(json["infinitemovement"]),
                to_int(json["lockresets"]),
                to_bool(json["allow180"]),
                Objective::getObjective(json["objective"]),
                to_bool(json["room_handling"]),
                to_int(json["room_handling_arr"]),
                to_int(json["room_handling_das"]),
                to_int(json["room_handling_sdf"]),
                to_bool(json["manual_allowed"]),
                to_bool(json["b2bchaining"]),
                to_bool(json["allclears"]),
                to_bool(json["clutch"]),
                to_bool(json["nolockout"]),
                to_string(json["passthrough"]),
                to_bool(json["can_undo"]),
                to_bool(json["can_retry"]),
                to_bool(json["retryisclear"]),
                to_bool(json["noextrawidth"]),
                to_bool(json["stride"]),
                to_int(json["boardwidth"]),
                to_int(json["boardheight"]),
                to_bool(json["new_payback"]),
                to_int(json["messiness_change"]),
                to_int(json["messiness_inner"]),
                to_bool(json["messiness_nosame"]),
                to_int(json["messiness_timeout"]),
                to_bool(json["usebombs"]),
                to_string(json["song"]),
                to_string(json["latencypreference"]),
                Handling::getHandling(json["handling"]),
                to_int(json["fulloffset"]),
                to_int(json["fullinterval"]),
                to_string(json["gameid"]),
                to_string(json["username"]),
                Constants_overrides::getConstants_overrides(json["constantsoverrides"]),
                to_bool(json["gravitymax20g"]),
                to_bool(json["garbageattackcap"]),
                to_bool(json["nosound"]),
                to_bool(json["shielded"]),
                to_int(json["boardbuffer"]),
                to_int(json["survival_cap"]),
                to_int(json["survival_timer_itv"]),
                to_int(json["survival_layer_min"]),
                Minoskin::getMinoskin(json["minoskin"]),
                to_string(json["ghostskin"]),
                to_string(json["boardskin"])
        );

        return options;
    }
};


#endif //TETR_IO_VISULIZER_OPTIONS_H
