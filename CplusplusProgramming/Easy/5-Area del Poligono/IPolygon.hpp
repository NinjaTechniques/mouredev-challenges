// Define abstract class

#ifndef IPOLIGON_HPP
#define IPOLIGON_HPP

class IPolygon {
public:
    //Definiendo la firma de los metodos
    virtual double area() = 0; // Funcion virtual pura
    virtual void printArea() = 0; // Funcion virtual pura
    
    virtual ~IPolygon() { }
};


#endif // IPOLYGON_HPP

