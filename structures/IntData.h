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
#ifndef TETR_IO_VISULIZER_INTDATA_H
#define TETR_IO_VISULIZER_INTDATA_H


class IntData{
public:
    int iid;
    std::string type;
    int amt;
    int ackiid;
    int x;
    int y;
    int size;
    std::string username;

    static IntData getIntData(nlohmann::json const &json) {
        try{
        auto intData = IntData(
                to_int(nullable_handle(json,"iid")),
                to_string(nullable_handle(json,"type")),
                to_int(nullable_handle(json,"amt")),
                to_int(nullable_handle(json,"ackiid")),
                to_int(nullable_handle(json,"x")),
                to_int(nullable_handle(json,"y")),
                to_int(nullable_handle(json,"size")),
                to_string(nullable_handle(json,"username"))
        );
        return intData;
        }catch(std::exception & e){
            return {};
        }
    }
};

#endif //TETR_IO_VISULIZER_INTDATA_H
