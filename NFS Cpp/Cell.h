#pragma once
using namespace std;
#include <string>
#include <iostream>
class Cell {
    private:
    int red;
    int green;
    int blue;
    int nbReproductions;
    void setNbReproductions(const int nbReproductions);

    public:
    ~Cell();
    Cell();
    Cell(int red, int green, int blue);
    Cell(const Cell& other);
    int getRed();
    void setRed(const int red);
    int getGreen();
    void setGreen(const int green);
    int getBlue();
    void setBlue(const int blue);
    int getNbReproductions();
    friend ostream& operator<<(ostream& os, const Cell& cell);
    Cell& operator--();
    Cell operator--(int);
    friend Cell operator+(const Cell left, const Cell right);
    void die();
    bool isViable();
};

