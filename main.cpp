#include "twoplayer.cpp"
#include "evals.h"

int main() {
    twoplayer engine;
    Eval1 first;
    Eval2 second;
    Eval3 third;
    Eval4 fourth;
    Eval *e [4];
    string p[4] = {"Eval 1", "Eval 2", "Eval 3", "Eval 4"};
    int winCount[4] = {0 , 0, 0, 0}, winner = 0;
    e[0] = &first;
    e[1] = &second; 
    e[2] = &third;
    e[3] = &fourth;
    cout << "begin testing" << endl;
    for (int i = 0; i < 4; i++) {
        for (int u = 0; u < 4; u++) {
            cout << "X is " << p[i] << " and O is " << p[u] << endl;
            winner = engine.playRound(e[i], e[u]);
            if (winner == 1) {
                cout << "X wins" << endl;
                winCount[i]++;
            } else if (winner == 2) {
                cout << "O wins" << endl;
                winCount[u]++;
            }
            else cout << "tie game" << endl;
            cout << endl;
        }
    }
    for (int j = 0; j < 4; j++) {
        cout << endl;
        cout << p[j] << " has won a total of " << winCount[j] << " times!" << endl;
    }
    return 0;
}