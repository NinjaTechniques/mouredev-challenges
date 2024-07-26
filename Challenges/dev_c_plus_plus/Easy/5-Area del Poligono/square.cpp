#include "header.hpp"
#include "IPolygon.hpp"

class Square: public IPolygon{
private:
    double side;

public:
    Square() { }
    Square(double side){
        this->side = side;
    }

    double area(){ return this->side * this->side; }

    void printArea(){
        cout << "The area of the square is: " << this->area() << endl;
    }

};