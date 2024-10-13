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

    static Handling getHandling(nlohmann::json const &json) {
        try {
            auto handling = Handling(
                to_int(nullable_handle(json, "arr")),
                to_int(nullable_handle(json, "das")),
                to_int(nullable_handle(json, "dcd")),
                to_int(nullable_handle(json, "sdf")),
                to_bool(nullable_handle(json, "safelock")),
                to_bool(nullable_handle(json, "cancel")),
                to_bool(nullable_handle(json, "may20g"))
            );
            return handling;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_HANDLING_H
