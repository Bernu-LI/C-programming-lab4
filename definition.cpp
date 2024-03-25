#include "description.h"

#include <cmath>
#include <iostream>

Point::Point(double x, double y) {
    this->x = x;
    this->y = y;
}

Vector2D::Vector2D(Point p1_, Point p2_): p1(p1_), p2(p2_) {}


EquilateralTriangle::EquilateralTriangle(Point p1, Point p2): Vector2D(p1, p2) {}

double EquilateralTriangle::square() {
    return pow(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)), 2) * sqrt(3) / 2;
}

double EquilateralTriangle::perimeter() {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)) * 3;
}

void EquilateralTriangle::draw() {
    std::cout << "Equilateral triangle with coordinates (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << ")\n";
}

const char *EquilateralTriangle::classname() {
    return "Equilateral triangle";
}

unsigned int EquilateralTriangle::size() {
    return sizeof(EquilateralTriangle);
}

double EquilateralTriangle::mass() const {
    return m;
}

Vector2D EquilateralTriangle::position() {
    return {p1, p2};
}

bool EquilateralTriangle::operator==(const IPhysObject &ob) const {
    return (this->mass() == ob.mass());
}

bool EquilateralTriangle::operator<(const IPhysObject &ob) const {
    return (this->mass() < ob.mass());
}


Hexagon::Hexagon(Point p1_, Point p2_): Vector2D(p1_, p2_) {}

double Hexagon::square() {
    return pow(sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)), 2) * sqrt(3) / 2 * 6;
}

double Hexagon::perimeter() {
    return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2)) * 6;
}

void Hexagon::draw() {
    std::cout << "Hexagon with coordinates (" << p1.x << ", " << p1.y << "), (" << p2.x << ", " << p2.y << ")\n";
}

const char *Hexagon::classname() {
    return "Hexagon";
}

unsigned int Hexagon::size() {
    return sizeof(Hexagon);
}

double Hexagon::mass() const {
    return m;
}

Vector2D Hexagon::position() {
    return {p1, p2};
}

bool Hexagon::operator==(const IPhysObject &ob) const {
    return (this->mass() == ob.mass());
}

bool Hexagon::operator<(const IPhysObject &ob) const {
    return (this->mass() < ob.mass());
}


void merge(vector <EquilateralTriangle*>& array, size_t l, size_t mid, size_t r) {
    vector <EquilateralTriangle*> auxiliary_array(r - l);
    int it1 = 0;
    int it2 = 0;
    while (l + it1 < mid and mid + it2 < r) {
        if (array[l + it1]->mass() <= array[mid + it2]->mass()) {
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
void mergeSort(vector <EquilateralTriangle*>& array, size_t l, size_t r) {
    if (l + 1 == r) {
        return;
    }
    size_t mid = (l + r) / 2;
    mergeSort(array, l, mid);
    mergeSort(array, mid, r);
    merge(array, l, mid, r);
}

void merge(vector <Hexagon*>& array, size_t l, size_t mid, size_t r) {
    vector <Hexagon*> auxiliary_array(r - l);
    int it1 = 0;
    int it2 = 0;
    while (l + it1 < mid and mid + it2 < r) {
        if (array[l + it1]->mass() <= array[mid + it2]->mass()) {
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

void mergeSort(vector <Hexagon*>& array, size_t l, size_t r) {
    if (l + 1 == r) {
        return;
    }
    size_t mid = (l + r) / 2;
    mergeSort(array, l, mid);
    mergeSort(array, mid, r);
    merge(array, l, mid, r);
}

