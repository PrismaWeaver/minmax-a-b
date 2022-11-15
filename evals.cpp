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
    int p1, p2;
    p1 = p2 = 0;

    //rows
    for(int i = 0; i < 3; i++){
        string line = (board[i*3], board[i*3 + 1], board[i*3 + 2]);
        if(line == (p, p, " ") || line == (p, " ", p) || line == (" ", p, p)) p1++;
        else if (line == (p, " ", " ") || line == (" "," ", p) || line == (" ", p, " ")) p2++;
    }

    //columns
    for(int i = 0; i < 3; i++){
        string line = (board[i], board[i + 3], board[i + 6]);
        if(line == (p, p, " ") || line == (p, " ", p) || line == (" ", p, p)) p1++;
        else if (line == (p, " ", " ") || line == (" "," ", p) || line == (" ", p, " ")) p2++;
    }

    //diagnol
    string diagnol1 = (board[0], board[4], board[8]);
    string diagnol2 = (board[2], board[4], board[6]);
    
    if(diagnol1 == (p, p, " ") || diagnol1 == (p, " ", p) || diagnol1 == (" ", p, p)) p1++;
    else if (diagnol1 == (p, " ", " ") || diagnol1 == (" "," ", p) || diagnol1 == (" ", p, " ")) p2++;

    if(diagnol2 == (p, p, " ") || diagnol2 == (p, " ", p) || diagnol2 == (" ", p, p)) p1++;
    else if (diagnol2 == (p, " ", " ") || diagnol2 == (" "," ", p) || diagnol2 == (" ", p, " ")) p2++;

    
    return (3*p1+p2);

};

// int Eval3::getNum(string board[], string p) {} //kuda's eval

int Eval4::getNum(string board[], string p) { //Twee's Eval
    int b[9], value = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == p) b[i] = 4; //square has player's piece
        else if (board[i] == " ") b[i] = 1; //square is blank
        else b[i] = 0; //square has opponent's piece
    }
    //multiplies the lines such that lines that have the opponent's piece result in 0 and lines with player piece are valued 4, 16, 64 for amount in line
    for (int u = 0; u < 3; u++) {
        value += b[3 * u] * b[(3 * u) + 1] * b[(3 * u) + 2];
        value += b[u] * b[u + 3] * b[u + 6];
    }
    value += b[0] * b[4] * b[8];
    value += b[2] * b[4] * b[6];
    return value;
}