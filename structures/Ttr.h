//
// Created by shira on 5/20/2024.
//
#pragma once
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

    static Ttr parseTtr(std::string const &path) {
        auto json = parseJson(path);
        auto ttr = Ttr();

        ttr._id = to_string(json["_id"]);
        ttr.endcontext = Player::getEndcontext(json["endcontext"]);
        ttr.gametype = to_string(json["gametype"]);
        ttr.ismulti = to_bool(json["isMulti"]);
        ttr.mt = to_longlong(json["mt"]);
        ttr.shortid = to_string(json["shortid"]);
        ttr.ts = to_string(json["ts"]);
        ttr.verified = to_bool(json["verified"]);
        ttr.data = Data::getData(json["data"]);
        ttr.back = to_string(json["back"]);
        ttr.forcestyle = to_string(json["forcestyle"]);

        return ttr;
    }
};


#endif //TETR_IO_VISULIZER_TTR_H
