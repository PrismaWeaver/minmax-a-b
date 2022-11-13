//this is where each of the eval functions will be stored
//each should be of the same base class type, but impliment different methods
#include "evals.h"
#include <iostream>
using std::cout;
using std::endl;

 int Eval::value(string board[], string p) {
    int max = getNum(board, p), min;
    if (p == "X") min = getNum(board, "O");
    else min = getNum(board, "X");
    return max - min;
 }

//calculate # of open lines that player has their mark in, subtract opponent win lines from player win lines, return this as the value
int Eval1::getNum(string board[], string p) {
    int value = 0;
    for (int i = 0; i < 3; i++) {
        //rows
        if ((board[i * 3] == " " || board[i * 3] == p) && (board[(i * 3) + 1] == " " || board[(i * 3) + 1] == p) && (board[(i * 3) + 2] == " " || board[(i * 3) + 2] == p)) value++;
        //columns
        if ((board[i] == " " || board[i] == p) && (board[i + 3] == " " || board[i + 3] == p) && (board[i + 6] == " " || board[i + 6] == p)) value++;
    }
    //diagonal
    if ((board[0] == " " || board[0] == p) && (board[4] == " " || board[4] == p) && (board[8] == " " || board[8] == p)) value++;
    if ((board[2] == " " || board[2] == p) && (board[4] == " " || board[4] == p) && (board[6] == " " || board[6] == p)) value++;
    return value;
}

// class Eval2 : public Eval { //eval 2 (chris)

// };

// class Eval3 : public Eval { //eval 3 (kuda)

// };

int Eval4::getNum(string board[], string p) { //Twee's Eval
    int p1, p2, p3;
    p1 = p2 = p3 = 0;
    for (int i = 0; i < 3; i++) {
        if (board[i * 3] == p || board[(i * 3) + 1] == p || board[(i * 3) + 2] == p) {
            if (board[i * 3] == p && board[(i * 3) + 1] == p && board[(i * 3) + 2] == p) p3++;
            else if ((board[i * 3] == p && board[(i * 3) + 1] == p && board[(i * 3) + 2] == " ") || (board[i * 3] == p && board[(i * 3) + 1] == " " && board[(i * 3) + 2] == p) || (board[i * 3] == " " && board[(i * 3) + 1] == p && board[(i * 3) + 2] == p)) p2++;
            else if ((board[i * 3] == p && board[(i * 3) + 1] == " " && board[(i * 3) + 2] == " ") || (board[i * 3] == " " && board[(i * 3) + 1] == p && board[(i * 3) + 2] == " ") || (board[i * 3] == " " && board[(i * 3) + 1] == " " && board[(i * 3) + 2] == p)) p1++;
        }
        if (board[i] == p || board[i + 3] == p || board[i + 6] == p) {
            if (board[i] == p && board[i + 3] == p && board[i + 6] == p) p3++;
            else if ((board[i] == p && board[i + 3] == p && board[i + 6] == " ") || (board[i] == p && board[i + 3] == " " && board[i + 6] == p) || (board[i] == " " && board[i + 3] == p && board[i + 6] == p)) p2++;
            else if ((board[i] == p && board[i + 3] == " " && board[i + 6] == " ") || (board[i] == " " && board[i + 3] == p && board[i + 6] == " ") || (board[i] == " " && board[i + 3] == " " && board[i + 6] == p)) p1++;
        }
    }
    if (board[0] == p || board[4] == p || board[8] == p) {
        if (board[0] == p && board[4] == p && board[8] == p) p3++;
        else if ((board[0] == p && board[4] == p && board[8] == " ") || (board[0] == p && board[4] == " " && board[8] == p) || (board[0] == " " && board[4] == p && board[8] == p)) p2++;
        else if ((board[0] == p && board[4] == " " && board[8] == " ") || (board[0] == " " && board[4] == p && board[8] == " ") || (board[0] == p && board[4] == " " && board[8] == " ")) p1++;
    }
    if (board[2] == p || board[4] == p || board[6] == p) {
        if (board[2] == p && board[4] == p && board[6] == p) p3++;
        else if ((board[2] == p && board[4] == p && board[6] == " ") || (board[2] == p && board[4] == " " && board[6] == p) || (board[2] == " " && board[4] == p && board[6] == p)) p2++;
        else if ((board[2] == p && board[4] == " " && board[6] == " ") || (board[2] == " " && board[4] == p && board[6] == " ") || (board[2] == p && board[4] == " " && board[6] == " ")) p1++;
    }
    return 50 * p3 + 5 * p2 + p1;
}