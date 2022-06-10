#include "A.h"

A::~A() {}

A::A() : A(10) { }

A::A(const int value) {
    this->setValue(value);
}

A::A(const A& other) : A(other.value) {}


int A::getValue() {
    return this->value;
}

void A::setValue(const int value) {
    this->value = value;
}

A& A::operator++() {
    this->setValue(this->getValue() + 1);
    return *this;
}

ostream& operator<<(ostream& os, const A& a) {
    os << a.value;
    return os;
}

istream& operator>>(istream& is, A& a) {
    is >> a.value;
    return is;
}

A operator+(const A left, const A right) {
    return A(left.value + right.value);
}
