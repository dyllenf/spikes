#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H

#include <iostream>

class boardType {
   public:
   
    // constructor
    boardType(std::string);

    // overload the stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const boardType& dt);
 
    private:
        int board[3][3];

};

boardType::boardType(std::string argv) {

    // fill initial board from argv
    // assumes valid array of integers
    int iPos = 0;
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 3; col++) {
            board[row][col] = argv[iPos++] - '0' ;
        }
    }
}

std::ostream& operator<<(std::ostream& os, const boardType& thisBoard) {
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            os << thisBoard.board[r][c] << ' ';
        }
        std::cout << std::endl;
    }
    return os;
}

#endif