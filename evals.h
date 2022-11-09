//this contains the basic c template of the eval class
//contains a method with a peram of the board class type
#ifndef EVAL_H
#define EVAL_H
#include <string>
using std::string;

class Eval {
    public:
        virtual int value(string board[], string p) = 0;
};

class Eval1: public Eval{
    public:
        int value(string board[], string p);
    private:
        int getNum(string board[], string p);
};

class Eval2: public Eval{
    public:
        int value(string board[], string p);
    private: 
        int getNum(string board[], string p);
};

class Eval3: public Eval{
    public:
        int value(string board[], string p);
    private:
        int getNum(string board[], string p);
};

class Eval4: public Eval{
    public:
        int value(string board[], string p);
    private:
        int getNum(string board[], string p);
};

#endif /*EVAL_H*/