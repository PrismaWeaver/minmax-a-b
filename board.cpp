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
#include <algorithm>

class Board {
    private:
        string game[9][9]; //an array of board arrays, even indexs are p1's moves odd indexes are p2's
    public:
        Board() {

        }

        bool add(int index, string move) { //add(index, string): puts the value representing either an X or an O into the array at a given position, returns T/F
            bool success = false;
            move = (move);
            if (index > -1 && index < 9) {
                if (move == "X" || move == "O") {

                }
            }
            return success;
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
                for (int u = 0; u < 9; u++) {

                }
            }
        }
};