//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include "../Utils.h"
#include <iostream>

#ifndef TETR_IO_VISULIZER_CONTROLLING_H
#define TETR_IO_VISULIZER_CONTROLLING_H

class Controlling {
public:
    int ldas;
    int ldasiter;
    bool lshift;
    int rdas;
    int rdasiter;
    bool rshift;
    int lastshift;
    bool softdrop;

    static Controlling getControlling(nlohmann::json const &json) {
        try{
        auto controlling = Controlling(
                to_int(json["ldas"]),
                to_int(json["ldasiter"]),
                to_bool(json["lshift"]),
                to_int(json["rdas"]),
                to_int(json["rdasiter"]),
                to_bool(json["rshift"]),
                to_int(json["lastshift"]),
                to_bool(json["softdrop"])
        );

        return controlling;
        }catch(std::exception & e){
            return Controlling();
        }
    }
};


#endif //TETR_IO_VISULIZER_CONTROLLING_H
