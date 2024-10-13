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

#ifndef TETR_IO_VISULIZER_CLEARS_H
#define TETR_IO_VISULIZER_CLEARS_H


class Clears {
public:
    int singles;
    int doubles;
    int triples;
    int quads;
    int pentas;
    int realtspins;
    int minitspins;
    int minitspinsingles;
    int tspinsingles;
    int minitspindoubles;
    int tspindoubles;
    int tspintriples;
    int tspinquads;
    int tspinpentas;
    int allclear;

    static Clears getClears(nlohmann::json const &json) {
        try {
            auto clears = Clears(
                to_int(nullable_handle(json,"singles")),
                to_int(nullable_handle(json,"doubles")),
                to_int(nullable_handle(json,"triples")),
                to_int(nullable_handle(json,"quads")),
                to_int(nullable_handle(json,"pentas")),
                to_int(nullable_handle(json,"realtspins")),
                to_int(nullable_handle(json,"minitspins")),
                to_int(nullable_handle(json,"minitpinsingles")),
                to_int(nullable_handle(json,"tspinsingles")),
                to_int(nullable_handle(json,"minitspindoubles")),
                to_int(nullable_handle(json,"tspindoubles")),
                to_int(nullable_handle(json,"tspintriples")),
                to_int(nullable_handle(json,"tspinquads")),
                to_int(nullable_handle(json,"tspinpentas")),
                to_int(nullable_handle(json,"allclear"))
            );
            return clears;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_CLEARS_H
