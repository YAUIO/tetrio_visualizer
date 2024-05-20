//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.cpp"
#ifndef TETR_IO_VISULIZER_HANDLING_H
#define TETR_IO_VISULIZER_HANDLING_H


class Handling {
public:
    int arr;
    int das;
    int dcd;
    int sdf;
    bool safelock;
    bool cancel;
    bool may20g;

    Handling getHandling(nlohmann::json const &json) {
        auto handling = Handling(
                to_int(json["arr"]),
                to_int(json["das"]),
                to_int(json["dcd"]),
                to_int(json["sdf"]),
                to_bool(json["safelock"]),
                to_bool(json["cancel"]),
                to_bool(json["may20g"])
        );
        return handling;
    }
};


#endif //TETR_IO_VISULIZER_HANDLING_H
