#include "header.hpp"
#include "IPolygon.hpp"

class Triangle: public IPolygon {
private:
    double base;
    double height;

public:
    Triangle() {}
   
   Triangle(double base, double height){
        this->base = base;
        this->height = height;
    }

    double area() { return (this->base * this->height) / 2; }

    void printArea() {cout << "The area of the triangle is: " << this->area() << endl; }
};