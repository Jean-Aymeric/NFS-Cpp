#include <iostream>
#include "A.h"
#include "Point3D.h"
#include "Petri.h"

int main() {
    Petri petri;
    cout << petri << "\n";
    for (int i = 0; i < 100; i++) {
        petri.live();
        cout << i << ":" << petri;
    }
}
