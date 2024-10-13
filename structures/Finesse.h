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

#ifndef TETR_IO_VISULIZER_FINESSE_H
#define TETR_IO_VISULIZER_FINESSE_H

class Finesse {
public:
    int combo;
    int faults;
    int perfectpieces;

    static Finesse getFinesse(nlohmann::json const &json) {
        try {
            auto finesse = Finesse(
                to_int(nullable_handle(json,"combo")),
                to_int(nullable_handle(json,"faults")),
                to_int(nullable_handle(json,"perfectpieces"))
            );
            return finesse;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_FINESSE_H
