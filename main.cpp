#include <iostream>
#include "Utils.h"
#include "Ttr.h"
int main(int argc, char* argv[]) {
    /*if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1;
    }
    std::string path = argv[1];*/
    std::string path = "/home/yudek/CLionProjects/TETR.IO_Visulizer/test.ttrm";
    auto ttr = Ttr::parseTtr(path);
    std::ofstream a_file ( "example.txt" );
    return 0;
}
