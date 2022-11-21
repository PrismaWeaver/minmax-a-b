//this is where all the magic happens
//class contains everything needed to run a game of tic-tac-toe

#include "board.cpp"
#include "evals.h"
#include <chrono>
#include <windows.h>
#include <psapi.h>

using namespace std::chrono;

class twoplayer {
    private:
        Board game; //board object
        int nodeCounter;
        int nodeCountX;
        int nodeCountO;
        int avgXNodes;
        int avgONodes;
        int turnCountX;
        int turnCountO;

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

        VP minmax_a_b(string board[], int d, string p, Eval * e, int pt, int ut) {
            nodeCounter++;
            VP thing, compare;
            //begin step 1, determine if depth is enough
            if (d >= 2) return end(board, e, p);
            //begin step 2, determine if there are any children
            int ref = empty(board);
            if (ref == 0) return end(board, e, p);
            //begin step 3
            //determine opponent
            string o = swap(p);
            TTT temp; //for transfering the board states
            //its easier to do the calculations for each individual child then move on to the next
            for (int u = 0; u < ref; u++) {
                temp = children(board, p, u); //returns a TTT which holds a board
                compare = minmax_a_b(temp.board, d + 1, o, e, -ut, -pt); //RECURSION CALL
                if (-compare.value > pt) { //this is where im not entirely sure if im doing it right
                    pt = -compare.value;
                    thing.value = pt;
                    thing.path = temp;
                }
                if (pt >= ut) return thing;
            }
            return thing;
        }

        TTT children(string board[], string p, int u) { 
            int count = -1;
            TTT temp;
            for (int i = 0; i < 9; i++) { //i itterates through board
                if (board[i] == " ") {
                    count++; //keeps track of empty strings reached
                    if (count == u) temp.board[i] = p; //only changes the uth empty slot each pass
                    else temp.board[i] = " ";
                }
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

        VP end(string board[], Eval * e, string p) { //generates what minmax_a_b returns
            VP thing;
            for (int i = 0; i < 9; i++) thing.path.board[i] = board[i]; 
            thing.value = e->value(board, p);
            return thing;
        }

        bool turn(string p, Eval * e) { //completes one player turn
            nodeCounter = 0;
            TTT temp = game.getBoard();
            VP move = minmax_a_b(temp.board, 0, p, e, -500, 500);

            if (p == "X"){
                nodeCountX += nodeCounter;
            }
            else{
                nodeCountO += nodeCounter;
            }

            if (!game.add(move.path.board)) cout << "Error: Invalid move detected" << endl;
            return game.goal();
        }

        void metaCount() {
            cout << "Player 1 (X) used " << nodeCountX << " nodes total, with an average of " << nodeCountX/turnCountX << " nodes generated per turn." << endl;
            cout << "Player 2 (O) used " << nodeCountO << " nodes total, with an average of " << nodeCountO/turnCountO << " nodes generated per turn." << endl;
        }

        string swap(string p) {
            if (p == "X") p = "O";
            else p = "X";
            return p;
        }

    public:
        int playRound(Eval * max, Eval * min) {
            

            nodeCounter = nodeCountO = nodeCountX = 0;
            turnCountX = turnCountO = 0;
            int winner = 0, count = 0;
            long long start, end;
            bool win = false;
            string p = ""; //doesnt need to be initialized to anything bc swap will set it to X for us
            while (!win && count < 9) {
                p = swap(p);
                if (p == "X") {
                    win = turn(p, max);
                    turnCountX++;
                }
                else {
                    win = turn(p, min);
                    turnCountO++;
                }      
                count++;
            }
            if (win) {
                if (p == "X") winner = 1;
                else winner = 2;
            }
            game.print();
            metaCount();

            PROCESS_MEMORY_COUNTERS_EX memCounter;
            BOOL result = GetProcessMemoryInfo(GetCurrentProcess(),
                                   (PROCESS_MEMORY_COUNTERS*)&memCounter,
                                   sizeof( memCounter ));
            SIZE_T virtualMemUsedByMe = memCounter.PrivateUsage;
            SIZE_T physMemUsedByMe = memCounter.WorkingSetSize;
            
            cout << "Total virtual memory used by game " << virtualMemUsedByMe << endl;
            cout << "Total physical memory used by game " << physMemUsedByMe << endl;

            game.reset();
            return winner;
        }
};