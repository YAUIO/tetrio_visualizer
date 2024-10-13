//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Objective.h"
#include "Handling.h"
#include "../Parse.h"
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
        try{
        auto options = Options(
                to_int(nullable_handle(json,"version")),
                to_bool(nullable_handle(json,"seed_ranom")),
                to_double(nullable_handle(json,"g")),
               to_bool(nullable_handle(json,"countdow")),
                to_int(nullable_handle(json,"countdow_count")),
                to_int(nullable_handle(json,"countdow_interval")),
                to_int(nullable_handle(json,"precountown")),
                to_int(nullable_handle(json,"prestart")),
                to_string(nullable_handle(json,"mission")),
                to_string(nullable_handle(json,"mission_ype")),
                to_string(nullable_handle(json,"zoominto")),
                to_string(nullable_handle(json,"slot_couter1")),
                to_string(nullable_handle(json,"slot_couter2")),
                to_string(nullable_handle(json,"slot_couter3")),
                to_string(nullable_handle(json,"slot_couter5")),
                to_string(nullable_handle(json,"slot_bar")),
                to_bool(nullable_handle(json,"display_ire")),
                to_bool(nullable_handle(json,"display_sername")),
                to_bool(nullable_handle(json,"hasgarbae")),
                to_bool(nullable_handle(json,"bgmnorest")),
                to_bool(nullable_handle(json,"neverstobgm")),
                to_bool(nullable_handle(json,"display_ext")),
                to_bool(nullable_handle(json,"display_old")),
                to_bool(nullable_handle(json,"infinitehold")),
                to_int(nullable_handle(json,"gmargin")),
                to_double(nullable_handle(json,"gincreas")),
                to_int(nullable_handle(json,"garbagecp")),
                to_int(nullable_handle(json,"garbagecpincrease")),
                to_int(nullable_handle(json,"garbagecpmax")),
                to_bool(nullable_handle(json,"garbageasolutecap")),
                to_int(nullable_handle(json,"garbagehlesize")),
                to_bool(nullable_handle(json,"garbagepase")),
                to_bool(nullable_handle(json,"garbageqeue")),
                to_int(nullable_handle(json,"garbageae")),
                to_string(nullable_handle(json,"garbageetry")),
                to_string(nullable_handle(json,"garbagebocking")),
                to_string(nullable_handle(json,"garbagetrgetbonus")),
                to_string(nullable_handle(json,"presets")),
                to_string(nullable_handle(json,"bagtype")),
                to_string(nullable_handle(json,"spinbonues")),
                to_string(nullable_handle(json,"combotabe")),
                to_string(nullable_handle(json,"kickset")),
                to_int(nullable_handle(json,"nextcoun")),
                to_bool(nullable_handle(json,"allow_haddrop")),
                to_bool(nullable_handle(json,"display_hadow")),
                to_int(nullable_handle(json,"locktime")),
                to_int(nullable_handle(json,"garbageseed")),
                to_int(nullable_handle(json,"forfeit_ime")),
                to_int(nullable_handle(json,"are")),
               to_int(nullable_handle(json,"lineclea_are")),
                to_bool(nullable_handle(json,"infiniteovement")),
                to_int(nullable_handle(json,"lockreses")),
                to_bool(nullable_handle(json,"allow180")),
                Objective::getObjective(nullable_handle(json,"objectiv")),
                to_bool(nullable_handle(json,"room_hanling")),
                to_int(nullable_handle(json,"room_hanling_arr")),
                to_int(nullable_handle(json,"room_hanling_das")),
                to_int(nullable_handle(json,"room_hanling_sdf")),
                to_bool(nullable_handle(json,"manual_alowed")),
                to_bool(nullable_handle(json,"b2bchainng")),
                to_bool(nullable_handle(json,"allclear")),
                to_bool(nullable_handle(json,"clutch")),
                to_bool(nullable_handle(json,"nolockou")),
                to_string(nullable_handle(json,"passthrogh")),
                to_bool(nullable_handle(json,"can_undo")),
                to_bool(nullable_handle(json,"can_retr")),
                to_bool(nullable_handle(json,"retryiscear")),
                to_bool(nullable_handle(json,"noextrawdth")),
                to_bool(nullable_handle(json,"stride")),
                to_int(nullable_handle(json,"boardwidh")),
                to_int(nullable_handle(json,"boardheiht")),
                to_bool(nullable_handle(json,"new_paybck")),
                to_int(nullable_handle(json,"messines_change")),
                to_int(nullable_handle(json,"messines_inner")),
                to_bool(nullable_handle(json,"messines_nosame")),
                to_int(nullable_handle(json,"messines_timeout")),
                to_bool(nullable_handle(json,"usebombs")),
                to_string(nullable_handle(json,"song")),
                to_string(nullable_handle(json,"latencypeference")),
                Handling::getHandling(nullable_handle(json,"handling")),
                to_int(nullable_handle(json,"fulloffst")),
                to_int(nullable_handle(json,"fullinteval")),
                to_string(nullable_handle(json,"gameid")),
                to_string(nullable_handle(json,"username")),
                Constants_overrides::getConstants_overrides(nullable_handle(json,"constantoverrides")),
                to_bool(nullable_handle(json,"gravitymx20g")),
                to_bool(nullable_handle(json,"garbageatackcap")),
                to_bool(nullable_handle(json,"nosound")),
                to_bool(nullable_handle(json,"shielded")),
                to_int(nullable_handle(json,"boardbufer")),
                to_int(nullable_handle(json,"survivalcap")),
                to_int(nullable_handle(json,"survivaltimer_itv")),
                to_int(nullable_handle(json,"survivallayer_min")),
                Minoskin::getMinoskin(nullable_handle(json,"minoskin")),
                to_string(nullable_handle(json,"ghostski")),
                to_string(nullable_handle(json,"boardski"))
        );

        return options;
        }catch(std::exception & e){
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_OPTIONS_H
