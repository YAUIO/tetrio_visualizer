#include <iostream>
#include "Utils.h"
#include "Ttr.h"
#include <fmt/core.h>
#include <fmt/ranges.h>

int main(int argc, char* argv[]) {
    /*if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1;
    }
    std::string path = argv[1];*/
    std::string path = "/home/yudek/Documents/CLionProjects/tetrio_visualizer/test.ttrm";
    auto ttr = Ttr::parseTtr(path);

    Replays data = Replays();
    std::vector<BoardV> display = std::vector<BoardV>();
    bool check = false;

    fmt::println("PARSED");

    fmt::println("{}",ttr.data.size());

    return 0;
}
