#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

/*
 * Escribe un programa que se encargue de comprobar si un número es o no primo.
 * Hecho esto, imprime los números primos entre 1 y 100.
 */

bool isPrime(int value) {
    bool flag = 1;

    for (int i = 2; i < sqrt(value); i++) {
        if (value % i == 0) {flag = 0; break;}
    }

    return flag;
}

void printPrimerNumbersBetween1And100(){

    for (int i = 2; i <= 1000; i++) {
        if (isPrime(i)) {
            cout << i << " "; 
        }
    }

}


int main (){
    system("cls");
    printPrimerNumbersBetween1And100();

    cout << endl << endl;
    return 0;
}
