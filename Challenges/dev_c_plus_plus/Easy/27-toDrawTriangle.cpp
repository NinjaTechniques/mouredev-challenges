#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea un programa que dibuje un cuadrado o un triángulo con asteriscos "*".
 * - Indicaremos el tamaño del lado y si la figura a dibujar es una u otra.
 * - EXTRA: ¿Eres capaz de dibujar más figuras?
 */

enum Figure {
    SQUARE,
    EQUILATERAL_TRIANGLE,
    RECTANGLE
};

void toDrawSquare(int side) {
    for (int i = 0; i < side; i++) {
        for (int j = 0; j < side; j++) {
            if (i == 0 || i == (side - 1)) {
                cout << "* ";
                continue;
            }

            if (j == 0 || j == (side - 1)){
                cout << "* "; continue;
            }

            cout << "  ";
        }
        cout << endl;
    }
 
}

void toDrawEquilateralTriangle(int side){
    int decrease = side + 1; // Valor original (-)
    int increase = side; // (+)

    for (int i = 1; i <= side; i++) {

        if (i != side) {
             for (int j = 1; j <= increase; j++) {
                if (j == (decrease - 1) || j == increase) {
                    cout << "* "; continue;
                }

                cout << "  ";
            }

            increase++; decrease--; 
        }
        else {

            for (int j = 1; j <= increase; j++) {
                if (j % 2 != 0) {
                    cout << "* "; continue;
                }

                cout << "  ";
            }

        }

        cout << endl;
    }
}

void toDrawRectangle (int weidth, int height){

    for (int i = 1; i <= height; i++) {
        for (int j = 1; j <= weidth; j++) {
            if (i == 1 || i == height) {
                cout << "* "; continue;
            }

            if (j == 1 || j == weidth) {
                cout << "* "; continue;
            }

            cout << "  ";
        }
        cout << endl;
    }
}

void toDrawFigures(Figure figure){ 
    int side = 0;
    int width = 0, height = 0;

    if (figure == SQUARE || figure == EQUILATERAL_TRIANGLE) {
        cout << "Enter the side: "; cin >> side;
        cout << endl;
    }

    if (figure == RECTANGLE) {
        cout << "Enter the width: "; cin >> width;
        cout << "Enter the height: "; cin >> height;
        cout << endl;
    }   


    switch (figure)
    {
    case SQUARE: toDrawSquare(side); break;

    case EQUILATERAL_TRIANGLE: toDrawEquilateralTriangle(side); break;

    case RECTANGLE: toDrawRectangle(width, height); break;
    
    default: cout << "This figure is not supported :("; break;
    }
}

void menu(int &option){
    cout << "=== What figure do you want to draw? ===\n";
    cout << "[1]: Square\n";
    cout << "[2]: Equilateral Triangle\n";
    cout << "[3]: Ractangle\n";
    cout << "[4]: Exit";

    cout << "\n\nOPTION => "; cin >> option;
}

void interfaceUI (){
    int option = 0;
    char answer = 'y';

    while(true) {
        system("cls");
        menu(option); cout << "\n";
        if (option == 4) {break;}

        cout << endl;
        if (option == 1) { toDrawFigures(SQUARE); }
        if (option == 2) { toDrawFigures(EQUILATERAL_TRIANGLE); }
        if (option == 3) { toDrawFigures(RECTANGLE); }

        cout << endl;
        cout << "Continue? [Yes: y; No: n]: "; cin >> answer;
        if (tolower(answer) == 'n') { break; }
    }

}

int main (){
    system("cls");
    interfaceUI();

    cout << endl;
    return 0;
}