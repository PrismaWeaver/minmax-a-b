//contains a class called Board 
//METHODS:


//magic(array pointer): fills the passed array with the values of ttt
//      as they correspond to the magic square (lines add to 12)
//      for use with eval functions & goal method
//      doesnt necessarily need to remain a string array
//goal: checks if the board has reached a terminal state, returning T/F
//winner: this is whats called to check board state, checks if goal reached
//        if goal is reached, this returns who won, X or O
#include "vp.h"
#include <iostream>
using std::cout;
using std::endl;

class Board {
    private:
        string game[9][9];  //an array of board arrays, even indexs are p1's moves odd indexes are p2's
        int move;           //holds which board is currently being analyzed
    public:
        Board() {

        }

        bool add(string *board) { //adds the contents of the array to game if they are valid (meaning only one move has been made between it and the previous board state)

        }

        int changeDetect (string *board) {
            
        }

        void reset() { //reset: cleans the board, setting every value to empty, void
            for (int i = 0; i < 9; i++) {
                for (int u = 0; u < 9; u++) {
                    game[i][u] = " ";
                }
            }
        }

        void print() { //print: generates a visual of the current board state
            for (int i = 0; i < 9; i++) {
                cout << " " << game[i][0] << " | " << game[i][1] << " | " << game[i][2] << endl;
                cout << "----------" << endl;
                cout << " " << game[i][3] << " | " << game[i][4] << " | " << game[i][5] << endl;
                cout << "----------" << endl;
                cout << " " << game[i][6] << " | " << game[i][7] << " | " << game[i][8] << endl;
                cout << endl;
            }
        }
};