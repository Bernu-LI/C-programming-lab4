#include "description.h"

#include <iostream>
#include <cmath>

using namespace std;

EquilateralTriangle::EquilateralTriangle(int sideLength_): sideLength(sideLength_) {}

void EquilateralTriangle::display() {
    cout << "Equilateral triangle with side length " << sideLength << endl;
}

double EquilateralTriangle::area() {
    return pow(sideLength, 2) * pow(3, 0.5) / 4;
}

int EquilateralTriangle::perimeter() {
    return sideLength * 3;
}


Hexagon::Hexagon(int sideLength_): sideLength(sideLength_) {}

void Hexagon::display() {
    cout << "Hexagon with side length " << sideLength << endl;
}

double Hexagon::area() {
    return pow(sideLength, 2) * pow(3, 0.5) / 4 * 6;
}

int Hexagon::perimeter() {
    return sideLength * 6;
}


void merge(vector <IFigure*>& array, size_t l, size_t mid, size_t r) {
    vector <IFigure*> auxiliary_array(r - l);
    int it1 = 0;
    int it2 = 0;
    while (l + it1 < mid and mid + it2 < r) {
        if (array[l + it1]->area() <= array[mid + it2]->area()) {
            auxiliary_array[it1 + it2] = (array[l + it1]);
            it1++;
        }
        else {
            auxiliary_array[it1 + it2] = (array[mid + it2]);
            it2++;
        }
    }
    while (l + it1 < mid) {
        auxiliary_array[it1 + it2] = (array[l + it1]);
        it1++;
    }
    while (mid + it2 < r) {
        auxiliary_array[it1 + it2] = (array[mid + it2]);
        it2++;
    }
    for (int i = 0; i < r - l; i++) {
        array[l + i] = auxiliary_array[i];
    }
}

void mergeSort(vector <IFigure*>& array, size_t l, size_t r) {
    if (l + 1 == r) {
        return;
    }
    size_t mid = (l + r) / 2;
    mergeSort(array, l, mid);
    mergeSort(array, mid, r);
    merge(array, l, mid, r);
}
