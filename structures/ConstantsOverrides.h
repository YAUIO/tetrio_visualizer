//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>

#ifndef TETR_IO_VISULIZER_CONSTANTS_OVERRIDES_H
#define TETR_IO_VISULIZER_CONSTANTS_OVERRIDES_H


class Constants_overrides {
public:

    static Constants_overrides getConstants_overrides(nlohmann::json const &json) {
        try{
        auto constants_overrides = Constants_overrides();
        return constants_overrides;
        }catch(std::exception & e){
            return Constants_overrides();
        }
    }
};


#endif //TETR_IO_VISULIZER_CONSTANTS_OVERRIDES_H
