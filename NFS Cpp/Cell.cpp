#include "Cell.h"

Cell::~Cell() {}

Cell::Cell() : Cell(rand() % 256, rand() % 256, rand() % 256) {}

Cell::Cell(int red, int green, int blue) : red(red), green(green), blue(blue), nbReproductions(3) {}

Cell::Cell(const Cell& other) : Cell(other.red, other.green, other.blue) {
    this->nbReproductions = other.nbReproductions;
}

int Cell::getRed() {
    return this->red;
}

void Cell::setRed(const int y) {
    this->red = red;
}

int Cell::getGreen() {
    return this->green;
}

void Cell::setGreen(const int x) {
    this->green = green;
}

int Cell::getBlue() {
    return this->blue;
}

void Cell::setBlue(const int z) {
    this->blue = blue;
}

int Cell::getNbReproductions() {
    return this->nbReproductions;
}

void Cell::setNbReproductions(const int nbReproductions) {
    this->nbReproductions = nbReproductions;
    //if (nbReproductions <= 0) {
    //    this->die();
    //}
}

Cell& Cell::operator--() {
    this->setNbReproductions(this->getNbReproductions() - 1);
    return *this;
}

Cell Cell::operator--(int) {
    Cell temp = *this;
    --* this;
    return temp;
}

void Cell::die() {
    this->~Cell();
}

bool Cell::isViable() {
    int temp = this->getRed() + this->getGreen() + this->getBlue();
//    return (temp % 2 == 0) && (this->getNbReproductions() > 0);
    return (temp > 192) && (temp < 576) && (this->getNbReproductions() > 0);
}

ostream& operator<<(ostream& os, const Cell& cell) {
    os << cell.nbReproductions << "," << cell.red << "," << cell.green << "," << cell.blue << ",";
    return os;
}

Cell operator+(Cell left, Cell right) {
    Cell newCell((left.getGreen() + right.getBlue() + 256) % 256,
                 (left.getBlue() + right.getRed() + 256) % 256,
                 (left.getRed() + right.getGreen() + 256) % 256);
    return newCell;
}
