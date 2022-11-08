#ifndef BOARD_TYPE_H
#define BOARD_TYPE_H

#include <iostream>
#include <vector>

class boardType {
   public:
   
    // constructor
    boardType(std::string);
    void findZero();
    void potentialMoves();
    void isSolvable(); // function to determine if initial state is solvable

    // overload the stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const boardType& dt);
 
    private:
        int board[3][3];
        int zeroRow;
        int zeroCol;

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

void boardType::isSolvable(){

    // count number of inversions, if even then is solvable, if odd then not
    int initialBoard[9];
    int counter = 0;
    for(int i=0; i < 3; i++){ // converting board to 1D array to bypass checking 2D array
        for(int j=0; j < 3; j++){
            initialBoard[counter] = board[i][j];
            counter++;
        }
    }
    
    // for loop to count number of inversions
    std::cout << "hello";


}

void boardType::findZero(){
    // Goes through 2d array to find the Zero
    for (int r=0; r < 3; r++)
    {
        for (int c=0; c < 3; c++)
        {
            if (board[r][c] == 0)
            {
                this->zeroRow = r;
                this->zeroCol = c;
            }
        }
    }
}

void boardType::potentialMoves(){
    // check if each swap is "in bounds"
    // swap zero with row above, col to right and left, and row below

    this->findZero();
    if (this->zeroRow - 1 >= 0)
    {
        std::cout << "Valid swap, (" << zeroRow - 1 << "," << zeroCol << ")->(" << zeroRow << "," << zeroCol << ")" << std::endl;
    }
    if (this->zeroRow + 1 <= 2)
    {
        std::cout << "Valid swap, (" << zeroRow + 1 << "," << zeroCol << ")->(" << zeroRow << "," << zeroCol << ")" << std::endl;
    }
    if (this->zeroCol - 1 >= 0)
    {
        std::cout << "Valid swap, (" << zeroCol - 1 << "," << zeroRow << ")->(" << zeroRow << "," << zeroCol << ")" << std::endl;
    }
    if (this->zeroCol + 1 <= 2)
    {
        std::cout << "Valid swap, (" << zeroCol + 1 << "," << zeroRow << ")->(" << zeroRow << "," << zeroCol << ")" << std::endl;
    }

}
#endif