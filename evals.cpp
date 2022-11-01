//this is where each of the eval functions will be stored
//each should be of the same base class type, but impliment different methods
#include "evals.h"

class eval1 : public eval {//calculate # of open lines that player has their mark in, subtract opponent win lines from player win lines, return this as the value
    public:
        int value(string board[], string p) {
            int max = getNum(board, p), min;
            if (p == "X") min = getNum(board, "O");
            else min = getNum(board, "X");
            return max - min;
        }
    private:
        int getNum(string board[], string p) { //there is probably a better way of doing this honestly
            int value = 0;
            //rows
            if ((board[0] == "  " || board[0] == p) && (board[1] == "  " || board[1] == p) && (board[2] == "  " || board[2] == p)) value++;
            if ((board[3] == "  " || board[3] == p) && (board[4] == "  " || board[4] == p) && (board[5] == "  " || board[5] == p)) value++;
            if ((board[6] == "  " || board[6] == p) && (board[7] == "  " || board[7] == p) && (board[8] == "  " || board[8] == p)) value++;
            //columns
            if ((board[0] == "  " || board[0] == p) && (board[3] == "  " || board[3] == p) && (board[6] == "  " || board[6] == p)) value++;
            if ((board[1] == "  " || board[1] == p) && (board[4] == "  " || board[4] == p) && (board[7] == "  " || board[7] == p)) value++;
            if ((board[2] == "  " || board[2] == p) && (board[5] == "  " || board[5] == p) && (board[8] == "  " || board[8] == p)) value++;
            //diagonal
            if ((board[0] == "  " || board[0] == p) && (board[4] == "  " || board[4] == p) && (board[8] == "  " || board[8] == p)) value++;
            if ((board[2] == "  " || board[2] == p) && (board[4] == "  " || board[4] == p) && (board[6] == "  " || board[6] == p)) value++;
            return value;
        }
};

class eval2 : public eval { //eval 2 (chris)

};

class eval3 : public eval { //eval 3 (kuda)

};

class eval4 : public eval { //eval 4 (twee)

};