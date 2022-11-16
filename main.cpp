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
    Eval1 first;
    Eval2 second;
    Eval4 fourth;
    Eval *e1 = &first, *e2 = &second, *e4 = &fourth;
    cout << "Eval1 vs Eval1" << endl;
    engine.playRound(e1, e1);
    cout << "Eval2 vs Eval2" << endl;
    engine.playRound(e2, e2);
    cout << "Eval4 vs Eval4" << endl;
    engine.playRound(e4, e4);
    cout << "Eval1 vs Eval2" << endl;
    engine.playRound(e1, e2);
    cout << "Eval2 vs Eval1" << endl;
    engine.playRound(e2, e1);
    cout << "Eval1 vs Eval4" << endl;
    engine.playRound(e1, e4);
    cout << "Eval4 vs Eval1" << endl;
    engine.playRound(e4, e1);
    cout << "Eval2 vs Eval4" << endl;
    engine.playRound(e2, e4);
    cout << "Eval4 vs Eval2" << endl;
    engine.playRound(e4, e2);
    delete e1, e2, e4;
    return 0;
}