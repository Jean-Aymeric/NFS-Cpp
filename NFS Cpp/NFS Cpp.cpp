#include <iostream>
#include "A.h"
#include "Point3D.h"

int main() {
    Point3D a("A", 10, 11, 12);
    Point3D b;
    Point3D c("C", 1, 2, 3);
    Point3D d(a);
    Point3D e = a;
    A a1;

    ++e;
    e++;
    --b;
    b--;
    cout << a << "\n";
    cout << b << "\n";
    cout << c << "\n";
    cout << d << "\n";
    cout << e << "\n";
    cout << c + a << "\n";
    cout << ((a + c) <= (b - e)) << "\n";

    for (Point3D i; i <= Point3D(10, 10, 10); i++) {
        cout << i << "\n";
    }
}
