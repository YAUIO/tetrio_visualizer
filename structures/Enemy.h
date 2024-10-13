//
// Created by shira on 5/20/2024.
//
#pragma once
#include <string>
#include <vector>
#include "../imports/json.hpp"
#include <fstream>
#include <iostream>
#ifndef TETR_IO_VISULIZER_ENEMY_H
#define TETR_IO_VISULIZER_ENEMY_H

class Enemy {
public:
    static std::vector<Enemy> getEnemy(nlohmann::json const &fulljson) {
        auto enemy = std::vector<Enemy>();
        try {
            nlohmann::json json;
            int i = 0;
            while (i < fulljson.size()) {
                json = fulljson[i];
                enemy.push_back(Enemy());
                i++;
            }
            return enemy;
        } catch (std::exception &e) {
            return enemy;
        }
    }
};

#endif //TETR_IO_VISULIZER_ENEMY_H
