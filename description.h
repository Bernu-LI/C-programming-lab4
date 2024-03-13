#include <vector>

class IFigure {
public:
    virtual void display() = 0;
    virtual double area() = 0;
    virtual int perimeter() = 0;
};


class EquilateralTriangle : public IFigure {
public:
    explicit EquilateralTriangle(int sideLength_);

    void display() override;
    double area() override;
    int perimeter() override;

private:
    int sideLength = 0;
};


class Hexagon: public IFigure {
public:
    explicit Hexagon(int sideLength_);

    void display() override;
    double area() override;
    int perimeter() override;

private:
    int sideLength = 0;
};


void merge(std::vector <IFigure*>& array, int l, int mid, int r);
void mergeSort(std::vector <IFigure*>& array, size_t l, size_t r);
