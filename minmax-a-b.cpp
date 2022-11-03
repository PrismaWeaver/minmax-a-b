//this is where the difficulty happens
//this should probably be a method in twoplayer for simplicity
//but for now bc its such a big portion of this project it has its own file
#include "vp.h"
#include "evals.h"

//board:            the current board state of the current call
//depth (d):        how far away from the current boardstate the function is
//                  starts at 0 when called, recursion adds 1, stop at depth of 2
//player (p):       this helps decide if the child generator should be playing as X or O
//                  also important for comparisons
//eval (e):         objects of class type eval, used to determine value
//passthresh(PT):   struct pointer, starts with an initialized value thats super low
//                  gets updated at d=1 by values of nodes at d=2
//                  value compaired to UT after all d=2 nodes of this d=1 node are checked
//usethresh(UT):    starts with an initialized value thats super low

VP minmax_a_b(string board[], int d, string p, eval e, int pt = -120, int ut = 100) {
    VP thing, compare;
    //begin step 1, determine if depth is enough
    if (d >= 2) return end(board, e, p);
    //begin step 2, determine if there are any children
    int ref = empty(board);
    if (ref == 0) return end(board, e, p);
    //begin step 3
    //determine opponent
    string o;
    if (p == "X") o = "O";
    else o = "X";
    string * temp, container[ref];
    //its easier to do the calculations for each individual child then move on to the next
    for (int u = 0; u <= ref; u++) {
        temp = children(board, p, u); //returns an array pointer
        for (int i = 0; i < 9; i++) container[i] = *(temp + i); //transfer contents of pointer to array
        compare = minmax_a_b(container, d + 1, o, e, -pt, -ut); //RECURSION CALL
        if (compare.value > pt) { //this is where im not entirely sure if im doing it right
            pt = compare.value;
            thing.value = compare.value;
            thing.path = compare.path; 
        }
        if (pt > ut) return thing;
    }
}

string * children(string board[], string p, int u) { //not sure if 2D array will work here
    int count = -1;
    string temp[9];
    for (int i = 0; i < 9; i++) { //i itterates through board
        if (board[i] == "  ") count++; //keeps track of empty strings reached
        if (count == u) temp[i] = p; //only changes the uth empty slot each pass
        else temp[i] = board[i]; //fills the rest of the board as normal
    }
    return temp;
}

int empty(string board[]) {
    int count = 0;
    for (int i = 0; i < 9; i++) {
        if (board[i] == "  ") count++;
    }
    return count;
}

VP end(string board[], eval e, string p) {
    VP thing;
    thing.path = board; //assignment error
    thing.value = e.value(board, p);
    return thing;
}