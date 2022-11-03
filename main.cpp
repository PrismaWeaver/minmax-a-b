#include "twoplayer.cpp"
#include "evals.h"

void main() {
    twoplayer engine;
    eval1 e1;
    eval2 e2;
    eval3 e3;
    eval4 e4;
    engine.playRound(e1, e2);
    engine.playRound(e1, e3);
    engine.playRound(e1, e4);
    engine.playRound(e2, e3);
    engine.playRound(e2, e4);
    engine.playRound(e3, e4);
    return 0;
}