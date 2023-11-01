// Board Class: Handles game state

//* TODO: Add ship class to board
//* TODO: Rotation support


// Libararies
#include <iostream>

// Env Vars
const int BOARD_SIZE = 10;


class Board
{
    public:
        // Constructor
        Board();

        /** Prints the board.
            @param: none
            @return: none
        */
        void printBoard();

        /** Sets a char onto board
            @param: x
            @param: y
            @param: c
            @return: none
        */
        void setBoard(int x, int y, char c);

        /** Gets a char from board
            @param: x
            @param: y
            @return: char
        */
        char getBoard(int x, int y);

        /** Erase the board
            @param: none
            @return: none
        */
        void eraseBoard();

    // Private variables
    private:
        char board[BOARD_SIZE][BOARD_SIZE];
    
};


Board::Board()
{
    // Initialize board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board[i][j] = ' ';
        }
    }
}


void Board::printBoard()
{
    // Basic, content of board only (no legend)
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE; j++)
        {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

void Board::setBoard(int x, int y, char c)
{
    //* Will need to update char to ship later on

    // Set board
    board[x][y] = c;
}

void Board::eraseBoard()
{
    // Erase board
    for (int i = 0; i < BOARD_SIZE; i++)
    {
        for (int j = 0; j < BOARD_SIZE ; j++)
        {
            board[i][j] = ' ';
        }
    }
}
