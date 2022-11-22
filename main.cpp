#include "twoplayer.cpp"
#include "evals.h"
#include <chrono>

int main() {
    twoplayer engine [16];
    int counter = 0;
    Eval1 first;
    Eval2 second;
    Eval3 third;
    Eval4 fourth;
    Eval *e [4];
    string p[4] = {"Eval 1", "Eval 2", "Eval 3", "Eval 4"};
    int winCount[4] = {0, 0, 0, 0}, winner = 0;
    int tieCount[4] = {0, 0, 0, 0};
    e[0] = &first;
    e[1] = &second; 
    e[2] = &third;
    e[3] = &fourth;

    int avgTime[4] = {0, 0, 0, 0};
    long long start, end, duration;

    cout << "begin testing" << endl;
    for (int i = 0; i < 4; i++) {
        for (int u = 0; u < 4; u++) {
            cout << "X is " << p[i] << " and O is " << p[u] << endl;

            start = duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();
            winner = engine[counter].playRound(e[i], e[u]);
            end = duration_cast<microseconds>(high_resolution_clock::now().time_since_epoch()).count();

            if(i == 0 || u == 0){
                avgTime[0] += end - start;
            } else if (i == 1 || u == 1){
                avgTime[1] += end - start;
            } else if (i == 2 || u == 2){
                avgTime[2] += end - start;
            } else if(i == 3 || u == 3){
                avgTime[3] += end - start;
            }

           if (winner == 1) {
                cout << "X wins" << endl;
                winCount[i]++;
            } else if (winner == 2) {
                cout << "O wins" << endl;
                winCount[u]++;
            }
            else{
                cout << "tie game " << endl;
                tieCount[i]++;
                tieCount[u]++;
            } 
            cout << endl;
            counter++;
        }
    }

    for (int j = 0; j < 4; j++) {
        cout << endl;
        cout << p[j] << " has won a total of " << winCount[j] << " and tied a total of " << tieCount[j] << " times!" << endl;
        cout << "Minmax-a-b utilizing Eval " << j + 1 << " has an average execution time of " << avgTime[j]/7 << " microseconds." << endl;
    }
    return 0;
}