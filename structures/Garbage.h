//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "../Utils.h"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_GARBAGE_H
#define TETR_IO_VISULIZER_GARBAGE_H

class Garbage {
public:
    int sent;
    int received;
    int attack;
    int cleared;

    static Garbage getGarbage(nlohmann::json const &json) {
        try {
            auto garbage = Garbage(
                to_int(nullable_handle(json,"sent")),
                to_int(nullable_handle(json,"received")),
                to_int(nullable_handle(json,"attack")),
                to_int(nullable_handle(json,"cleared"))
            );
            return garbage;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_GARBAGE_H
