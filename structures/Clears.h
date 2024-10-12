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
        try{
        auto clears = Clears(
                to_int(json["singles"]),
                to_int(json["doubles"]),
                to_int(json["triples"]),
                to_int(json["quads"]),
                to_int(json["pentas"]),
                to_int(json["realtspins"]),
                to_int(json["minitspins"]),
                to_int(json["minitpinsingles"]),
                to_int(json["tspinsingles"]),
                to_int(json["minitspindoubles"]),
                to_int(json["tspindoubles"]),
                to_int(json["tspintriples"]),
                to_int(json["tspinquads"]),
                to_int(json["tspinpentas"]),
                to_int(json["allclear"])
        );
        return clears;
        }catch(std::exception & e){
            return Clears();
        }
    }
};


#endif //TETR_IO_VISULIZER_CLEARS_H
