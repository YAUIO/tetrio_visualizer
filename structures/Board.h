//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_BOARD_H
#define TETR_IO_VISULIZER_BOARD_H


class Board {
public:
    std::string id;
    std::string username;
    bool active;
    bool success;
};



#endif //TETR_IO_VISULIZER_BOARD_H
