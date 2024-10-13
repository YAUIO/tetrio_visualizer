//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.h"
#ifndef TETR_IO_VISULIZER_FALLING_H
#define TETR_IO_VISULIZER_FALLING_H


class Falling {
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

    static Falling getFalling(nlohmann::json const &json) {
        try {
            auto falling = Falling(
                to_bool(nullable_handle(json, "sleep")),
                to_bool(nullable_handle(json, "deep_sleep")),
                to_bool(nullable_handle(json, "hibernated")),
                to_int(nullable_handle(json, "locking")),
                to_int(nullable_handle(json, "lockresets")),
                to_bool(nullable_handle(json, "forcelock")),
                to_bool(nullable_handle(json, "floored")),
                to_bool(nullable_handle(json, "clamped")),
                to_int(nullable_handle(json, "safelock")),
                to_int(nullable_handle(json, "x")),
                to_int(nullable_handle(json, "y")),
                to_int(nullable_handle(json, "r")),
                to_string(nullable_handle(json, "type")),
                to_int(nullable_handle(json, "highesty")),
                to_string(nullable_handle(json, "last")),
                to_int(nullable_handle(json, "lastkick")),
                to_string(nullable_handle(json, "lastrotation")),
                to_int(nullable_handle(json, "irs")),
                to_bool(nullable_handle(json, "ihs")),
                to_int(nullable_handle(json, "aox")),
                to_int(nullable_handle(json, "aoy")),
                to_int(nullable_handle(json, "keys"))
            );
            return falling;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_FALLING_H
