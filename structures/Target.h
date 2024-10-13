//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_TARGET_H
#define TETR_IO_VISULIZER_TARGET_H

class Target {
public:
    static std::vector<Target> getTarget(nlohmann::json const &fulljson) {
        try {
            auto target = std::vector<Target>();
            nlohmann::json json;
            int i = 0;
            while (i < fulljson.size()) {
                json = fulljson[i];
                target.push_back(Target());
                i++;
            }
            return target;
        } catch (std::exception &e) {
            return {};
        }
    }
};

#endif //TETR_IO_VISULIZER_TARGET_H
