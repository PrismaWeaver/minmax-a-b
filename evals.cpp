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
    int p1, p2, p3;
    p1 = p2 = p3 = 0;

    //rows
    for(int i = 0; i < 3; i++){
        string line = (board[i*3], board[i*3 + 1], board[i*3 + 2]);
        if(line == (p, p, p)) p3++;
        if(line == (p, p, " ") || line == (p, " ", p) || line == (" ", p, p)) p2++;
        else if (line == (p, " ", " ") || line == (" "," ", p) || line == (" ", p, " ")) p1++;
    }

    //columns
    for(int i = 0; i < 3; i++){
        string line = (board[i], board[i + 3], board[i + 6]);
        if(line == (p, p, p)) p3++;
        if(line == (p, p, " ") || line == (p, " ", p) || line == (" ", p, p)) p2++;
        else if (line == (p, " ", " ") || line == (" "," ", p) || line == (" ", p, " ")) p1++;
    }

    //diagnol
    string diagnol1 = (board[0], board[4], board[8]);
    string diagnol2 = (board[2], board[4], board[6]);
    
    if(diagnol1 == (p, p, p)) p3++;
    if(diagnol1 == (p, p, " ") || diagnol1 == (p, " ", p) || diagnol1 == (" ", p, p)) p2++;
    else if (diagnol1 == (p, " ", " ") || diagnol1 == (" "," ", p) || diagnol1 == (" ", p, " ")) p1++;

    if(diagnol2 == (p, p, p)) p3++;
    if(diagnol2 == (p, p, " ") || diagnol2 == (p, " ", p) || diagnol2 == (" ", p, p)) p2++;
    else if (diagnol2 == (p, " ", " ") || diagnol2 == (" "," ", p) || diagnol2 == (" ", p, " ")) p1++;

    
    return (50*p3 + 3*p2 + p1);
};

int Eval3::getNum(string board[], string p) { //eval 3 (kuda)
  int scores[9] = {8, 3, 4, 1, 5, 9, 6, 7, 2}; // Stores the values for the magic squares
  int indexCounterP = 0; // Stores the number of indexes the player has for indexP array
  int indexCounterBlank = 0; // Stores the number of indexes the player has for indexBlank array
  int indexCounterFW = 0; // Stores the number of indexes the player has for futureWin array
  int indexP[5]; // Stores indexes of player
  int futureWin[30]; //Stores possible indexes of future win spaces
  int indexBlank[9]; //Stores blank indexes
  int potWin; // Used to calculate potential win states after using magic squares 
  int maxCounter = 1;

  // Populates the indexP, indexOpp and indexBlank arrays which will be used for calculating magic squares later
  for (int i = 0; i < 9; i++) {
    if (board[i] == p) { 
      indexP[indexCounterP++] = i; // assigns the board index to an index array named indexP if the index is populated with your symbol
    } else if (board[i] == " ") {
      indexBlank[indexCounterBlank++] = i; //assigns the board index to an index array named indexBlank if the index is populated blank
  }
  }

    // Checks if in current winning state and assings 100 if value is winning state
  for (int i = 0; i < indexCounterP; i++) { //Loops through all indexP values in combos of 3
    for (int j = i + 1; j < indexCounterP; j++) {
      for (int z = j + 1; z < indexCounterP; z++) {
        if (scores[indexP[i]] + scores[indexP[j]] + scores[indexP[z]] == 15) { // If one of them adds up to 15 we have a winner
          return 100;
        }
      }
    }
  }

  // Checks if there is a winner on the next move and assigns it the value of 50.
  for (int i = 0; i < indexCounterP; i++) { // first for runs through all values that are assigned to indexP.
    for (int j = i + 1; j < indexCounterP; j++) { 
      potWin = 15 - (scores[indexP[i]] + scores[indexP[j]]); // potWin is calculated by takeing the first p value and comparing its magic square value to another value in p. We then sutract that value from 15. This value is the magic square score for the final index.
      for (int z = 0; z < indexCounterBlank; z++) { // runs through all blank indexes and searches for if the potWin magic square value is located here.
        if (potWin == scores[indexBlank[z]]) { // if found return 50
          return 50; 
        }
      }
    }
  }

  // Runs through the indexP array comparing the magic squares values to all possible combinations of 2 indexBlank values.
  for (int i = 0; i < indexCounterP; i++) { 
    potWin = 15 - (scores[indexP[i]]); // calculates the remaining magic squares value needed to win after we subtract our p index's magic sqaures value from 15.
    for (int j = 0; j < indexCounterBlank; j++) { 
      for (int z = j + 1; z < indexCounterBlank; z++) { 
        if (potWin == scores[indexBlank[j]] + scores[indexBlank[z]]) { // if there is a potential winning combination
          futureWin[indexCounterFW] = indexBlank[j]; // adds the 2 indexes to futureWin array
          futureWin[indexCounterFW + 1] = indexBlank[z];
          indexCounterFW = indexCounterFW + 2; // incriments the size of indexCounterFW by 2 so we know the next point to load in our array next time through
        }
      }
    }
  }

 // Finds the highest number of occurrences of a index
  int max_count = 0; // initializes counter for our highest counted value
  for (int i = 0; i < indexCounterFW; i++) { // runs through the size of futureWin array
    int count = 1; 
    for (int j = i + 1; j < indexCounterFW; j++)
      if (futureWin[i] == futureWin[j]) // compares the two values to see if they are equal
        count++; 
    if (count > max_count) // if count is ever bigger than max, count is our new max
      max_count = count;
  }

  // Goes through futureWin and finds how many indexes occure the same amount of times as the max 
  for (int i = 0; i < indexCounterFW; i++) { // runs through futureWin
    int count = 1;
    for (int j = i + 1; j < indexCounterFW; j++) //grabs the rest of the values to compare to the first one at a time
      if (futureWin[i] == futureWin[j]) // if both values are the same increase our count by 1
        count++;
    if (count == max_count) {
        maxCounter++;
    }
  }

  return maxCounter; 
}

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