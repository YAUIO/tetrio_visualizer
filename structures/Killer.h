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

#ifndef TETR_IO_VISULIZER_KILLER_H
#define TETR_IO_VISULIZER_KILLER_H


class Killer {
public:
    std::string gameid;
    std::string name;
    std::string type;

    static Killer getKiller(nlohmann::json const &json) {
        try{
        auto killer = Killer(
                to_string(json["gameid"]),
                to_string(json["name"]),
                to_string(json["type"])
        );
        return killer;
        }catch(std::exception & e){
            return Killer();
        }
    }
};

#endif //TETR_IO_VISULIZER_KILLER_H
