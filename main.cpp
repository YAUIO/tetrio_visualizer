#include <iostream>
#include "Parse.h"

int main() {
    auto ttr = parseTtr("/home/yudek/CLionProjects/TETR.IO_Visulizer/test.ttrm");

    std::cout << ttr.forcestyle;

    return 0;
}
