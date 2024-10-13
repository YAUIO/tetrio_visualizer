//
// Created by yudek on 10/13/24.
//
#pragma once
#include <SFML/Graphics.hpp>
#include <fmt/ranges.h>

#include "BoardV.h"
#include "Ttr.h"

struct Objects {
    static sf::RectangleShape getRect (sf::Color const& color) {
        auto rect = sf::RectangleShape(sf::Vector2f(15,15));
        rect.setFillColor(color);
        return rect;
    }

    static sf::RectangleShape getRect (sf::Color const& color, float const & x, float const & y) {
        auto rect = sf::RectangleShape(sf::Vector2f(15,15));
        rect.setFillColor(color);
        rect.setPosition(x,y);
        return rect;
    }

    static std::vector<sf::RectangleShape> getField (Ttr const& ttr) {

        //data[0].replays[0].events[0].data.game.board

        for (auto const& boardV : ttr.data[0].replays[0].events[1].data.game.board) {
            fmt::println("{}",boardV.row);
        }

        fmt::println("{}",ttr.data[0].replays.size());

        for(Data const& data : ttr.data) {
            for (Replays const& replays : data.replays) {
                for(tEvent const& events : replays.events) {
                    for (auto const& boardV : events.data.game.board) {
                        fmt::println("{}",boardV.row);
                    }
                    fmt::println("\n--------\n");
                }
            }
        }

        return {};
    }
};
