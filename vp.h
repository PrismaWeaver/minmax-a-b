#ifndef VP_H
#define VP_H

#include <string>
using std::string;

struct VP {
    int value;          //VALUE: an int that holds the respective value of a node
    string path[9];   //PATH: holds the parent position array, added to board class array if value is high enough
};

#endif /*VP_H*/