//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_OBJECTIVE_H
#define TETR_IO_VISULIZER_OBJECTIVE_H

class Objective {
public:
    std::string type;

    static Objective getObjective(nlohmann::json const &json) {
        try {
            auto objective = Objective(to_string(json["type"]));
            return objective;
        } catch (std::exception &e) {
            return {};
        }
    }
};

#endif //TETR_IO_VISULIZER_OBJECTIVE_H
