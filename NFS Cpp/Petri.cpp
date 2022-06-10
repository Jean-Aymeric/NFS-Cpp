#include "Petri.h"

Petri::~Petri() {}

Petri::Petri() {
    for (int i = 0; i < 5; i++) {
        Cell temp;
        this->cells.push_back(Cell());
    }
}

void Petri::live() {
    vector<Cell> babyCells;
    for (unsigned int i = 0; i < this->cells.size() - 2; i++) {
        Cell* parent1 = &(this->cells.at(i));
        for (unsigned int j = i + 1; (j < this->cells.size() - 1) && parent1->isViable(); j++) {
            Cell* parent2 = &(this->cells.at(j));
            if (parent2->isViable()) {
                babyCells.push_back(*parent2 + *parent1);
                (*parent1)--;
                (*parent2)--;
            }
        }
    }

    for (Cell cell : this->cells) {
        if (!cell.isViable()) {
            babyCells.push_back(cell);
        }
    }

    for (Cell cell : babyCells) {
        if (cell.isViable()) {
            this->cells.push_back(cell);
        }
    }
}

ostream& operator<<(ostream& os, const Petri& petri) {
    os << petri.cells.size() << "\n";
    //for (Cell cell : petri.cells) {
    //    os << "\t" << cell << "\n";
    //}
    return os;
}
