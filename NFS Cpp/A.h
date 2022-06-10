#pragma once
using namespace std;
#include <iostream>
#include <string>

class A {
    private:
    int value;

    public:
    ~A();    // Destructeur
    A();     // Constructeur par défaut
    A(const int value); // Constructeur paramétré
    A(const A& other);  // Constructeur par recopie

    int getValue();
    void setValue(const int value);

    friend ostream& operator<<(ostream& os, const A& a);
    friend istream& operator>>(istream& is, A& a);

    A& operator++();
    
    friend A operator+(const A left, const A right);
};

