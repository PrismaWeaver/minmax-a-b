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

int Eval3::getNum(string board[], string p) { //eval 3 (kuda)
  int scores[10] = {8, 3, 4, 1, 5,
                    9, 6, 7, 2}; // Stores the values for the magic squares
  int indexCounterP = 0;
  int indexCounterOpp = 0;
  int indexCounterBlank = 0;
  int indexCounterFW = 0;
  int indexP[5];
  int indexOpp[5];
  int futureWin[30];
  int indexBlank[10] = {12, 12, 12, 12, 12, 12, 12, 12, 12, 12};
  int potWin;
  int indexCounter = 0;
  string oppSign;

  if(p == "X"){
    oppSign = "O";
  }
  else{
    oppSign = "X";
  }

  // Populate index arrays for each state a square can be in
  for (int i = 0; i < 10; i++) {
    if (board[i] == p) {
      indexP[indexCounterP] = i;
      indexCounterP++;
    } else if (board[i] == oppSign) {
      indexOpp[indexCounterOpp] = i;
      indexCounterOpp++;
    } else {
      indexBlank[indexCounterBlank] = i;
      indexCounterBlank++;
    }
  }

  // check for winner
  for (int i = 0; i < indexCounterP; i++) {
    for (int j = i + 1; j < indexCounterP; j++) {
      potWin = 15 - (scores[indexP[i]] + scores[indexP[j]]);
      for (int z = 0; z < indexCounterBlank; z++) {
        if (potWin == scores[indexBlank[z]]) {
          return indexBlank[z];
        }
      }
    }
  }

  // recursive call
  for (int i = 0; i < indexCounterOpp; i++) {
    for (int j = i + 1; j < indexCounterOpp; j++) {
      potWin = 15 - (scores[indexOpp[i]] + scores[indexOpp[j]]);
      for (int z = 0; z < indexCounterBlank; z++) {
        if (potWin == scores[indexBlank[z]]) {
               return indexBlank[z];
        }
      }
    }
  }

  // Find index that has highest potWin
  for (int i = 0; i < indexCounterP; i++) {
    potWin = 15 - (scores[indexP[i]]);
    for (int j = 0; j < indexCounterBlank; j++) {
      for (int z = j + 1; z < indexCounterBlank; z++) {
        if (potWin == scores[indexBlank[j]] + scores[indexBlank[z]]) {
          futureWin[indexCounterFW] = indexBlank[j];
          futureWin[indexCounterFW + 1] = indexBlank[z];
          indexCounterFW = indexCounterFW + 2;
        }
      }
    }
  }

  int max_count = 0;
  for (int i = 0; i < indexCounterFW; i++) {
    int count = 1;
    for (int j = i + 1; j < indexCounterFW; j++)
      if (futureWin[i] == futureWin[j])
        count++;
    if (count > max_count)
      max_count = count;
  }

  for (int i = 0; i < indexCounterFW; i++) {
    int count = 1;
    for (int j = i + 1; j < indexCounterFW; j++)
      if (futureWin[i] == futureWin[j])
        count++;
    if (count == max_count) {
        return indexBlank[i];
    }
  }

  if (indexCounterBlank == 10 || indexCounterBlank == 9) {
    for (int i = 1; i < indexCounterBlank; i++) {
      if (indexBlank[i] == 0 || indexBlank[i] == 2 || indexBlank[i] == 6 ||
          indexBlank[i] == 8) {
            return indexBlank[i];
      }
    }
  }
}

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
