#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


/*
 * Escribe un programa que imprima los 50 primeros números de la sucesión
 * de Fibonacci empezando en 0.
 * - La serie Fibonacci se compone por una sucesión de números en
 *   la que el siguiente siempre es la suma de los dos anteriores.
 *   0, 1, 1, 2, 3, 5, 8, 13...
 */

void fibonacciLineal (int n){
    long long a, b, aux;

    for (int i{}; i <= n; i++) { //Recorre inclusive hasta n, porque estamos abarcando el cero.
        if (i == 0) {cout << i << " "; a = i; continue;}
        if (i == 1) {cout << i << " "; b = i; continue;}

        cout << a + b << " ";
        aux = a;
        a = b;
        b += aux;
    }
}

long long fibonacciRecursivo (int n){
    
    if (n == 0) {return 0;}
    if (n == 1) {return 1;}

    return fibonacciRecursivo(n - 1) + fibonacciRecursivo(n - 2);
}

int main (){
    system("cls");
    int n = 0;

    cout << "Enter the value of n for the Fibonacci Sequence: ";
    cin >> n;
    
    fibonacciLineal(n);
    //cout << fibonacciRecursivo(n) << endl;

    cout << endl << endl;
    return 0;
}