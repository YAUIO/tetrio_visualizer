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

    Objective getObjective(nlohmann::json const &json) {
        auto objective = Objective(to_string(json["type"]));
        return objective;
    }
};

#endif //TETR_IO_VISULIZER_OBJECTIVE_H
