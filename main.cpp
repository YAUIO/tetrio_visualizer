#include <iostream>
#include "Parse.h"
int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Usage: " << argv[0] << " <argument>" << std::endl;
        return 1;
    }
    std::string path = argv[1];
    auto ttr = parseTtr(path);

    return 0;
}
