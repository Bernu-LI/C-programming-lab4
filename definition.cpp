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


template <class T>
void merge(vector <T*>& array, int l, int mid, int r) {
    vector <T*> auxiliary_array(r - l);
    int it1 = 0;
    int it2 = 0;
    while (l + it1 < mid and mid + it2 < r) {
        if (array[l + it1] <= array[mid + it2]) {
            auxiliary_array.push_back(array[l + it1]);
            it1++;
        }
        else {
            auxiliary_array.push_back(array[mid + it2]);
            it2++;
        }
    }
    while (l + it1 < mid) {
        auxiliary_array.push_back(array[l + it1]);
        it1++;
    }
    while (mid + it2 < r) {
        auxiliary_array.push_back(array[mid + it2]);
        it2++;
    } 
    for (int i = 0; i < r - l; i++) {
        array[l + i] = auxiliary_array[i];
    }
}

template <class T>
void mergeSort(vector <T*>& array, size_t l, size_t r) {
    if (l + 1 < r) {
        size_t mid = (l + r) / 2;
        mergeSort(array, l, mid);
        mergeSort(array, mid, r);
        merge(array, l, mid, r);
    }
}

void sortFigures() {

}