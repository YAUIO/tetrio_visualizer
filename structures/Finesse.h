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

#ifndef TETR_IO_VISULIZER_FINESSE_H
#define TETR_IO_VISULIZER_FINESSE_H

class Finesse {
public:
    int combo;
    int faults;
    int perfectpieces;

    Finesse getFinesse(nlohmann::json const &json) {
        auto finesse = Finesse(
                to_int(json["combo"]),
                to_int(json["faults"]),
                to_int(json["perfectpieces"])
        );
        return finesse;
    }
};


#endif //TETR_IO_VISULIZER_FINESSE_H
