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
    cout << "begin testing" << endl;
    twoplayer engine;
    Eval4 first;
    Eval * e4 = &first;
    cout << "testing eval 1" << endl;
    engine.playRound(e4, e4);
    return 0;
}