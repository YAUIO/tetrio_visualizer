#include <iostream>
#include "objects.h"
#include "Ttr.h"
#include <fmt/core.h>
#include <fmt/ranges.h>

#include "SFML/Graphics.hpp"

int main(int argc, char* argv[]) {
    /*if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1;
    }
    std::string path = argv[1];*/
    std::string path = "/home/yudek/Documents/CLionProjects/tetrio_visualizer/test.ttrm";
    auto ttr = Ttr::parseTtr(path);

    fmt::println("PARSED");

    auto window = sf::RenderWindow(sf::VideoMode(1280,720), "HDPR");
    window.setFramerateLimit(240);
    sf::Event event;

    auto a = Objects::getField(ttr);

    /*while (window.isOpen()) {
        window.clear(sf::Color::Black);

        while (window.pollEvent(event)) {
            if(event.type == sf::Event::Closed) {
                window.close();
            }
        }
        window.display();
    }*/

    return 0;
}
