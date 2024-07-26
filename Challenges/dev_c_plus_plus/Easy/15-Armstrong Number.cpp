#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Escribe una función que calcule si un número dado es un número de Armstrong
 * (o también llamado narcisista).
 * Si no conoces qué es un número de Armstrong, debes buscar información
 * al respecto.
 * https://mathworld.wolfram.com/NarcissisticNumber.html
 */

int numberSize(int number){

    int count = 0;

    while (number != 0) {
        count++;
        number /= 10;
    }

    return count;
}

bool isNumberGreaterThanZero(int number){
    if (number < 0) {
        return false;
    }

    return true;
}

bool isArmstrongNumber (int number){
    if (isNumberGreaterThanZero(number)) {
        int size = numberSize(number);
        int aux = number, aux2 = number, sum = 0;
        
        for (int i = 0; i < size; i++) {
            aux = aux2 % 10; // Encontramos cada digito individualmente
            sum += pow(aux, size); // Elevamos el cada valor individual a la potencia (size)
            aux2 /= 10; // Reducimos el valor original
        }

        if (sum == number) {
            return true;
        }

        return false;
    }

    return false;
}


int main (){
    system("cls");

    int number = 0;
    cout << "Enter only one number: "; cin >> number; cout << endl;
    cout << "Is it a Armstrong Number? : " << isArmstrongNumber(number) << endl;

    cout << endl;
    return 0;
}