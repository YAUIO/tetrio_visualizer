//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_DATA_H
#define TETR_IO_VISULIZER_DATA_H

class Data {
public:
    std::vector<Board> board;
    int frames;
    std::vector<tEvent> events;
};


#endif //TETR_IO_VISULIZER_DATA_H
