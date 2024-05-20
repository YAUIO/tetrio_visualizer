//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_SOURCE_H
#define TETR_IO_VISULIZER_SOURCE_H

class Source {
public:

    Source getSource(nlohmann::json const &json) {
        auto source = Source(); //0 fields
        return source;
    }
};

#endif //TETR_IO_VISULIZER_SOURCE_H
