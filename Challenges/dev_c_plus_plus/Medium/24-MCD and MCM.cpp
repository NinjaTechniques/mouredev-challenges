#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)
#define fori(i, n) for(int i = 0; i < n; i++)

/*
 * Crea dos funciones, una que calcule el máximo común divisor (MCD) y otra
 * que calcule el mínimo común múltiplo (mcm) de dos números enteros.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
 */

//Euclides Algorithm
int MCD(int a, int b){
    if (b == 0) {
        return a;
    }

    return MCD(b, (a % b));
}

int MCM (int a, int b){
    return (a * b) / MCD(a, b);
}


int main (){
    system("cls");

    int a, b;
    cout << "Enter number a: "; cin >> a;
    cout << "Enter number b: "; cin >> b;
    cout << endl;

    cout << "The MCD of " << a << " and " << b << " is: " << MCD(a, b) << endl;
    cout << "The MCM of " << a << " and " << b << " is: " << MCM(a, b) << endl;

    cout << endl;
    return 0;
}
