//NOTE: empty board slots are TWO spaces "  ", this is just for better formating when printing
#include "vp.h"
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

        bool win(string p) {
            bool success = false;
            for (int i = 0; i < 3; i++) {
                //rows
                if ((game[move][i * 3] == p) && (game[move][(i * 3) + 1] == p) && (game[move][(i * 3) + 2] == p)) {
                    success = true;
                    break;
                }
                //columns
                if ((game[move][i] == p) && (game[move][i + 3] == p) && (game[move][i + 6] == p)) {
                    success = true;
                    break;
                }
            }
            //diagonal
            if ((game[move][0] == p) && (game[move][4] == p) && (game[move][8] == p)) success = true;
            if ((game[move][2] == p) && (game[move][4] == p) && (game[move][6] == p)) success = true;
            return success;
        }

    public:
        Board() {
            reset();
        }

        int getTurn() {return move;}

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

        bool goal() { //evaluates the board based on magic square to determine if there is a winner: 0 no winner, 1 X, 2 O
            bool goal = false;
            if (move >= 5) { //literally cannot win until move == 5, aka player 1 has at least 3 moves
                if (win("X")) goal = true;
                else if (win("O")) goal = true;
            }
            return goal;
        }

        void print() { //print: generates a visual of the current board state
            for (int i = 0; i <= move; i++) {
                cout << UNDERLINE << " " << game[i][0] << " | " << game[i][1] << " | " << game[i][2] << " " << CLOSEUNDERLINE << endl;
                cout << UNDERLINE << " " << game[i][3] << " | " << game[i][4] << " | " << game[i][5] << " " << CLOSEUNDERLINE << endl;
                cout << " " << game[i][6] << " | " << game[i][7] << " | " << game[i][8] << endl;
                cout << endl;
            }
        }
};