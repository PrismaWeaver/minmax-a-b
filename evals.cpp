//this is where each of the eval functions will be stored
//each should be of the same base class type, but impliment different methods
#include "evals.h"
#include <iostream>
using std::cout;
using std::endl;

 int Eval::value(std::string board[], std::string p) {
    int max = getNum(board, p), min;
    if (p == "X") min = getNum(board, "O");
    else min = getNum(board, "X");
    return max - min;
 }

//calculate # of open lines that player has their mark in, subtract opponent win lines from player win lines, return this as the value
int Eval1::getNum(string board[], string p) { //there is probably a better way of doing this honestly
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

int Eval2::getNum(std::string board[], std::string p) { //eval 2 (chris)
    string q;
    if (p == "X") q = "O";
    else q = "X";

    int p1, p2, q1, q2;
    p1 = p2 = q1 = q2 = 0;

    //rows
    for(int i = 0; i < 3; i++){
        string line = (board[i*3], board[i*3 + 1], board[i*3 + 2]);
        if(line == (p, p, " ") || line == (p, " ", p) || line == (" ", p, p)) p1++;
        else if (line == (q, q, " ") || line == (q," ", q) || line == (" ", q, q)) q1++;
        else if (line == (p, " ", " ") || line == (" "," ", p) || line == (" ", p, " ")) p2++;
        else if (line == (q, " ", " ") || line == (" "," ", q) || line == (" ", q, " ")) q2++;
    }

    //columns
    for(int i = 0; i < 3; i++){
        string line = (board[i], board[i + 3], board[i + 6]);
        if(line == (p, p, " ") || line == (p, " ", p) || line == (" ", p, p)) p1++;
        else if (line == (q, q, " ") || line == (q," ", q) || line == (" ", q, q)) q1++;
        else if (line == (p, " ", " ") || line == (" "," ", p) || line == (" ", p, " ")) p2++;
        else if (line == (q, " ", " ") || line == (" "," ", q) || line == (" ", q, " ")) q2++;
    }

    //diagnol
    string diagnol1 = (board[0], board[4], board[8]);
    string diagnol2 = (board[2], board[4], board[6]);
    
    if(diagnol1 == (p, p, " ") || diagnol1 == (p, " ", p) || diagnol1 == (" ", p, p)) p1++;
    else if (diagnol1 == (q, q, " ") || diagnol1 == (q," ", q) || diagnol1 == (" ", q, q)) q1++;
    else if (diagnol1 == (p, " ", " ") || diagnol1 == (" "," ", p) || diagnol1 == (" ", p, " ")) p2++;
    else if (diagnol1 == (q, " ", " ") || diagnol1 == (" "," ", q) || diagnol1 == (" ", q, " ")) q2++;

    if(diagnol2 == (p, p, " ") || diagnol2 == (p, " ", p) || diagnol2 == (" ", p, p)) p1++;
    else if (diagnol2 == (q, q, " ") || diagnol2 == (q," ", q) || diagnol2 == (" ", q, q)) q1++;
    else if (diagnol2 == (p, " ", " ") || diagnol2 == (" "," ", p) || diagnol2 == (" ", p, " ")) p2++;
    else if (diagnol2 == (q, " ", " ") || diagnol2 == (" "," ", q) || diagnol2 == (" ", q, " ")) q2++;

    
    return (3*p1+p2 - 3*q1+q2);

};

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