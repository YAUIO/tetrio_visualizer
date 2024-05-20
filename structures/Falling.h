//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.cpp"
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

    Falling getFalling(nlohmann::json const &json) {
        auto falling = Falling(
                to_bool(json["sleep"]),
                to_bool(json["deep_sleep"]),
                to_bool(json["hibernated"]),
                to_int(json["locking"]),
                to_int(json["lockresets"]),
                to_bool(json["forcelock"]),
                to_bool(json["floored"]),
                to_bool(json["clamped"]),
                to_int(json["safelock"]),
                to_int(json["x"]),
                to_int(json["y"]),
                to_int(json["r"]),
                to_string(json["type"]),
                to_int(json["highesty"]),
                to_string(json["last"]),
                to_int(json["lastkick"]),
                to_string(json["lastrotation"]),
                to_int(json["irs"]),
                to_bool(json["ihs"]),
                to_int(json["aox"]),
                to_int(json["aoy"]),
                to_int(json["keys"])
        );
        return falling;
    }
};


#endif //TETR_IO_VISULIZER_FALLING_H
