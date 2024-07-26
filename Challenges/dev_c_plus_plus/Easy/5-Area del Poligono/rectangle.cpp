#include "header.hpp"
#include "IPolygon.hpp"

class Rectangle: public IPolygon {
private:
    double width;
    double lenght;

public:
    Rectangle () { }
    Rectangle (double width, double lenght): width(width), lenght(lenght) { }

    double area(){ return this->width * this->lenght; }

    void printArea() {cout << "The area of the rectangle is: " << this->area() << endl; }

};