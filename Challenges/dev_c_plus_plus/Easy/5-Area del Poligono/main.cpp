#include "header.hpp"
#include "IPolygon.hpp"
#include "square.cpp"
#include "triangle.cpp"
#include "rectangle.cpp"

/*
 * Crea una única función (importante que sólo sea una) que sea capaz
 * de calcular y retornar el área de un polígono.
 * - La función recibirá por parámetro sólo UN polígono a la vez.
 * - Los polígonos soportados serán Triángulo, Cuadrado y Rectángulo.
 * - Imprime el cálculo del área de un polígono de cada tipo.
 */

double area (IPolygon& polygon){
    polygon.printArea();

    return polygon.area();
}

int main (){
    system("cls");

    Square square(6.0);  
    Triangle triangle(4.0, 10.0);  
    Rectangle rectangle(8.0, 20.0);

    area(square);
    area(triangle);
    area(rectangle);
    
    cout << endl << endl;
    return 0;
}