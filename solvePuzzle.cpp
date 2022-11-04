// test executions
// solvePuzzle 182043765 
// solvePuzzle 812043765

#include <iostream>

#include "board.h"

int main(int argc, char* argv[]) {
 
    if (argc < 2) {
        std::cout << "Usage: solvePuzzle initalBoard " << std::endl;
        return -1;
    }

    boardType initialBoard(argv[1]);
    boardType goalBoard("123456780");

    std::cout << "initial: " << std::endl;
    std::cout << initialBoard << std::endl;

    std::cout << "goal: " << std::endl;
    std::cout << goalBoard << std::endl;

    return 0;
}
