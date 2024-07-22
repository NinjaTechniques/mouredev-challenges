#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


/*
 * Escribe un programa que muestre por consola (con un print) los
 * números de 1 a 100 (ambos incluidos y con un salto de línea entre
 * cada impresión), sustituyendo los siguientes:
 * - Múltiplos de 3 por la palabra "fizz".
 * - Múltiplos de 5 por la palabra "buzz".
 * - Múltiplos de 3 y de 5 a la vez por la palabra "fizzbuzz".
*/

bool isMultipleOfThree(int value){
    return value % 3 == 0;
}

bool isMultipleOfFive(int value){
    return value % 5 == 0;
}

void printNumbersFromOneToOneHundred (){
    const int MIN = 1;
    const int MAX = 100;
    
    for (int i = MIN; i <= MAX; i++){
        if (isMultipleOfThree(i) && isMultipleOfFive(i)) {
            cout << "fizzbuzz" << endl;
            continue;
        }

        if (isMultipleOfThree(i)) {
            cout << "fizz" << endl;
            continue;
        }

        if (isMultipleOfFive(i)) {
            cout << "buzz" << endl;
            continue;
        }

        cout << i << endl;
        
    }

}


int main (){
    system("cls");
    printNumbersFromOneToOneHundred();

    cout << "\n";
    return 0;
}