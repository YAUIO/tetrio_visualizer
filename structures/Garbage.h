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

    Garbage getGarbage(nlohmann::json const &json) {
        auto garbage = Garbage(
                to_int(json["sent"]),
                to_int(json["received"]),
                to_int(json["attack"]),
                to_int(json["cleared"])
        );
        return garbage;
    }
};


#endif //TETR_IO_VISULIZER_GARBAGE_H
