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

#ifndef TETR_IO_VISULIZER_HOLD_H
#define TETR_IO_VISULIZER_HOLD_H


class Hold {
public:
    std::string piece;
    bool locked;

    static Hold getHold(nlohmann::json const &json) {
        try {
            auto hold = Hold(
                to_string(nullable_handle(json, "piece")),
                to_bool(nullable_handle(json, "locked"))
            );
            return hold;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_HOLD_H
