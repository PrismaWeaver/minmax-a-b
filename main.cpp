#include "twoplayer.cpp"
#include "evals.h"

/*int main() {
    twoplayer engine;
    Eval1 e1;
    Eval2 e2;
    Eval3 e3;
    Eval4 e4;
    engine.playRound(e1, e2);
    engine.playRound(e1, e3);
    engine.playRound(e1, e4);
    engine.playRound(e2, e3);
    engine.playRound(e2, e4);
    engine.playRound(e3, e4);
    return 0;
}*/

int main() {
    twoplayer engine;
    Eval1 first;
    Eval2 second;
    Eval3 third;
    //Eval4 fourth;
    Eval *e [3];
    string p[3] = {"Eval 1", "Eval 2", "Eval 3"};
    int winCount[4] = {0 , 0, 0, 0}, winner = 0;
    e[0] = &first;
    e[1] = &second; 
    e[2] = &third;
    //e[2] = &fourth;
    cout << "begin testing" << endl;
    for (int i = 0; i < 3; i++) {
        for (int u = 0; u < 3; u++) {
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
    for (int j = 0; j < 3; j++) {
        cout << endl;
        cout << p[j] << " has won a total of " << winCount[j] << " times!" << endl;
    }
    return 0;
}