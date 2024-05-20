//
// Created by shira on 5/20/2024.
//
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include "Player.h"
#include "Data.h"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_TTR_H
#define TETR_IO_VISULIZER_TTR_H


class Ttr {
public:
    std::string _id;
    std::vector<Player> endcontext;
    std::string gametype;
    bool ismulti;
    long mt;
    std::string shortid;
    std::string ts;
    bool verified;
    std::vector<Data> data;
    std::string back;
    std::string forcestyle;
};


#endif //TETR_IO_VISULIZER_TTR_H
