//this contains the basic c template of the eval class
//contains a method with a peram of the board class type
#ifndef EVAL_H
#define EVAL_H
#include <string>
using std::string;

class eval {
    public:
        int value(string board[], string p);
};

#endif /*EVAL_H*/