//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
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
};

#endif //TETR_IO_VISULIZER_INTDATA_H
