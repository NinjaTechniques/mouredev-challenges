#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Escribe una función que calcule y retorne el factorial de un número dado
 * de forma recursiva.
 */

int factorial (int value){
    if (value == 1) {
        return 1;
    }

    return value * factorial(value - 1);
}

int main (){
    system("cls");

    int value = 0;
    cout << "Enter the value: "; cin >> value; cout << endl; 

    cout << "Factorial of " << value << " is: " << factorial(value) << endl;
    

    cout << endl;
    return 0;
}