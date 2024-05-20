//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#include "../Utils.cpp"
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

    IntData getIntData(nlohmann::json const &json) {
        auto intData = IntData(
                to_int(json["iid"]),
                to_string(json["type"]),
                to_int(json["amt"]),
                to_int(json["ackiid"]),
                to_int(json["x"]),
                to_int(json["y"]),
                to_int(json["size"]),
                to_string(json["username"])
        );
        return intData;
    }
};

#endif //TETR_IO_VISULIZER_INTDATA_H
