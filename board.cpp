//NOTE: empty board slots are TWO spaces "  ", this is just for better formating when printing
#include "vp.h"
#include "array.h"
#include <iostream>
#define UNDERLINE "\033[4m"
#define CLOSEUNDERLINE "\033[0m"
using std::cout;
using std::endl;

class Board { //used to keep track of the game state
    private:
        string game[10][9];  //an array of board arrays, even indexs are p1's moves odd indexes are p2's
        int move;           //holds which board is currently being analyzed

        int changeDetect (string board[]) { //used to ensure that the move made in add() is legal
            int changes = 0;
            for (int i = 0; i < 9; i++) {
                if (game[move][i] != board[i]) {
                    if (game[move][i] == " ") changes++; //checks to ensure move is legal
                    else return -1; //if move is illegal
                }
            }
            return changes;
        }

        array count(string p) { //scans board for specified string p, and fills the int array with their indexes 
            int count = 0;
            array index;
            TTT temp = magic();
            for (int i = 0; i < 9; i++) {
                if (temp.board[i] == p) index.index[count++] = i;
            }
            return index;
        }

        bool win(array index, string p) { //uses 3 nested for loops to check for a winning status
            bool success = false;
            int add = 0, size;
            if (p == "X") size = (move + 1) / 2;
            else size = move / 2;
            for (int i = 0; i < size - 2; i++) {
                for (int u = i + 1; u < size - 1; u++) {
                    for (int q = u + 1; q < size; q++) {
                        add = index.index[i] + index.index[u] + index.index[q];
                        if (add == 12) return true;
                    }
                }
            }
            return success;
        }

    public:
        Board() {
            reset();
        }

        TTT getBoard() { //used by minmax-a-b to get current board-state by passing an array by reference
            TTT board;
            for (int i = 0; i < 9; i++) {
                board.board[i] = game[move][i];
            }
            return board;
        }

        bool add(string board[]) { //adds the contents of the array to game if they are valid (meaning only one move has been made between it and the previous board state)
            bool success = false;
            if (changeDetect(board) == 1) {
                move++;
                for (int i = 0; i < 9; i++) {
                    game[move][i] = board[i];
                }
                success = true;
            }
            return success;
        }

        void reset() { //reset: cleans the board, setting every value to empty, void
            for (int i = 0; i < 9; i++) {
                for (int u = 0; u < 9; u++) {
                    game[i][u] = " ";
                }
            }
            move = 0;
        }

        TTT magic() { //changes arangement of board-state indexes to align with their magic square values
            // {0, 1, 2, 3, 4, 5, 6, 7, 8} becomes {1, 6, 5, 8, 4, 0, 3, 2, 7}
            TTT temp;
            temp.board[0] = game[move][5];
            temp.board[1] = game[move][0];
            temp.board[2] = game[move][7];
            temp.board[3] = game[move][6];
            temp.board[4] = game[move][4];
            temp.board[5] = game[move][2];
            temp.board[6] = game[move][1];
            temp.board[7] = game[move][8];
            temp.board[8] = game[move][3];
            return temp;
        }

        bool goal() { //evaluates the board based on magic square to determine if there is a winner: 0 no winner, 1 X, 2 O
            bool goal = false;
            if (move >= 5) { //literally cannot win until move == 4, aka player 1 has at least 3 moves
                array xIndex, oIndex;
                xIndex = count("X");
                oIndex = count("O");
                if (win(xIndex, "X")) goal = true;
                else if (move >= 6) { //ensure p2 has at least 3 moves
                    if (win(oIndex, "O")) goal = true;
                }
            }
            return goal;
        }

        void print() { //print: generates a visual of the current board state
            for (int i = 0; i < 10; i++) {
                cout << UNDERLINE << " " << game[i][0] << " | " << game[i][1] << " | " << game[i][2] << " " << CLOSEUNDERLINE << endl;
                cout << UNDERLINE << " " << game[i][3] << " | " << game[i][4] << " | " << game[i][5] << " " << CLOSEUNDERLINE << endl;
                cout << " " << game[i][6] << " | " << game[i][7] << " | " << game[i][8] << endl;
            }
        }
};