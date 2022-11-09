//this is where all the magic happens
//class contains everything needed to run a game of tic-tac-toe

#include "board.cpp"
#include "evals.h"

class twoplayer {
    private:
        Board game; //board object

        //MINMAX_A_B
        //THE HEART OF THIS ENTIRE PROGRAM

        //board:            the current board state of the current call
        //depth (d):        how far away from the current boardstate the function is
        //                  starts at 0 when called, recursion adds 1, stop at depth of 2
        //player (p):       this helps decide if the child generator should be playing as X or O
        //                  also important for comparisons
        //eval (e):         objects of class type eval, used to determine value
        //passthresh(PT):   struct pointer, starts with an initialized value thats super low
        //                  gets updated at d=1 by values of nodes at d=2
        //                  value compaired to UT after all d=2 nodes of this d=1 node are checked
        //usethresh(UT):    starts with an initialized value thats super high, gets changed at depth 0 and 1 based on the returned PT

        VP minmax_a_b(string board[], int d, string p, Eval e, int pt, int ut) {
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
            TTT temp; //for transfering the board states
            //its easier to do the calculations for each individual child then move on to the next
            for (int u = 0; u < ref; u++) {
                temp = children(board, p, u); //returns a TTT which holds a board
                compare = minmax_a_b(temp.board, d + 1, o, e, -ut, -pt); //RECURSION CALL
                if (compare.value > pt) { //this is where im not entirely sure if im doing it right
                    pt = compare.value;
                    thing.value = -compare.value;  
                    thing.path = temp;
                }
                if (pt > ut) return thing;
            }
            return thing;
        }

        TTT children(string board[], string p, int u) { 
            int count = -1;
            TTT temp;
            for (int i = 0; i < 9; i++) { //i itterates through board
                if (board[i] == " ") count++; //keeps track of empty strings reached
                if (count == u) temp.board[i] = p; //only changes the uth empty slot each pass
                else temp.board[i] = board[i]; //fills the rest of the board as normal
            }
            return temp;
        }

        int empty(string board[]) { //counts the # of "  " values in the board
            int count = 0;
            for (int i = 0; i < 9; i++) {
                if (board[i] == " ") count++;
            }
            return count;
        }

        VP end(string board[], Eval e, string p) { //generates what minmax_a_b returns
            VP thing;
            for (int i = 0; i < 9; i++) thing.path.board[i] = board[i]; 
            thing.value = e.value(board, p);
            return thing;
        }

        bool turn(string p, Eval e) { //completes one player turn
            VP move;
            TTT temp;
            temp = game.getBoard();
            move = minmax_a_b(temp.board, 0, p, e, -100, 100);
            if (!game.add(move.path.board)) cout << "Error: Invalid move detected" << endl;
            return game.goal();
        }

    public:
        void playRound(Eval max, Eval min) {
            cout << "round start" << endl;
            bool win = false;
            int count = 0;
            while (win == false) {
                cout << "Begin round " << count++ << endl;
                win = turn("X", max);
                if (win || count >= 9) break;
                cout << "Begin round " << count++ << endl;
                win = turn("O", min);
            }
            cout << "Round ended, printing results" << endl;
            game.print();
            game.reset();
        }
};