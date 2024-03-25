#ifndef description
#define description

#include <vector>

using namespace std;

class IGeoFig {
public:
    virtual double square() = 0;
    virtual double perimeter() = 0;
};

struct Point {
    Point(double x, double y);
    double x, y;
};

struct Vector2D {
    Vector2D(Point p1, Point p2);
    Point p1, p2;
};

class IPhysObject {
public:
    virtual double mass() const = 0;
    virtual Vector2D position() = 0;
    virtual bool operator == (const IPhysObject& ob) const = 0;
    virtual bool operator < (const IPhysObject& ob) const = 0;
};

class IPrintable {
    virtual void draw() = 0;
};

class IBaseObject {
    virtual const char* classname() = 0;
    virtual unsigned int size() = 0;
};

class EquilateralTriangle : public IGeoFig, Vector2D, public IPhysObject, public IPrintable, public IBaseObject {
public:
    EquilateralTriangle(Point p1, Point p2);
    double square() override;
    double perimeter() override;
    double mass() const override;
    Vector2D position() override;
    bool operator == (const IPhysObject& ob) const override;
    bool operator < (const IPhysObject& ob) const override;
    void draw() override;
    const char* classname() override;
    unsigned int size() override;
private:
    double m{};
};


class Hexagon : public IGeoFig, Vector2D, public IPhysObject, public IPrintable, public IBaseObject {
public:
    Hexagon(Point p1_, Point p2_);
    double square() override;
    double perimeter() override;
    double mass() const override;
    Vector2D position() override;
    bool operator == (const IPhysObject& ob) const override;
    bool operator < (const IPhysObject& ob) const override;
    void draw() override;
    const char* classname() override;
    unsigned int size() override;
private:
    double m{};
};


void merge(vector <EquilateralTriangle*>& array, int l, int mid, int r);
void mergeSort(vector <EquilateralTriangle*>& array, size_t l, size_t r);

void merge(vector <Hexagon*>& array, int l, int mid, int r);
void mergeSort(vector <Hexagon*>& array, size_t l, size_t r);

#endif