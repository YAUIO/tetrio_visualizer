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
#include <iostream>
#include <exception>
#include <nlohmann/json.hpp>
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
        try {
            auto json = parseJson(path);
            auto ttr = Ttr();

            ttr._id = to_string(nullable_handle(json, "_id"));
            ttr.endcontext = Player::getEndcontext(nullable_handle(json, "endcontext"));
            ttr.gametype = to_string(nullable_handle(json, "gametype"));
            ttr.ismulti = to_bool(nullable_handle(json, "isMulti"));
            ttr.mt = to_longlong(nullable_handle(json, "mt"));
            ttr.shortid = to_string(nullable_handle(json, "shortid"));
            ttr.ts = to_string(nullable_handle(json, "ts"));
            ttr.verified = to_bool(nullable_handle(json, "verified"));
            ttr.data = Data::getData(nullable_handle(json, "data"));
            ttr.back = to_string(nullable_handle(json, "back"));
            ttr.forcestyle = to_string(nullable_handle(json, "forcestyle"));

            return ttr;
        } catch (std::exception &e) {
            return {};
        }
    }
};


#endif //TETR_IO_VISULIZER_TTR_H
