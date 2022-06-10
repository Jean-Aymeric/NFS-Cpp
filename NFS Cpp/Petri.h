#pragma once
using namespace std;
#include <vector>
#include "Cell.h"
#include <string>
#include <iostream>

class Petri {
    private:
    vector<Cell> cells;

    public:
    ~Petri();
    Petri();
    void live();
    friend ostream& operator<<(ostream& os, const Petri& point);
};

