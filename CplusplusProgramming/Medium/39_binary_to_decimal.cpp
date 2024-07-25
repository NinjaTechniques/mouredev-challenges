#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea un programa se encargue de transformar un número binario
 * a decimal sin utilizar funciones propias del lenguaje que
 * lo hagan directamente.
 */

string toReverse (string value){
    string newValue = "";

    for (int i = value.length() - 1; i  >= 0; i--) {
        newValue += value[i];
    }

    return newValue;
}


int convertBinaryToDecimal (string binary) {
    const int BASE = 2;
    int power = 0, result = 0;
    binary = toReverse(binary);
    
    //For basado en rangos o ForEach
    for (char element: binary) {
        if (element == '1'){
          result += pow(BASE, power);
        }
        power++;
    }

    return result;
}

void showInterface (){
    string binary = "";
    cout << "Enter a binary(2) number: "; getline(cin, binary);
    cout << "The number in decimal(10) is: " << convertBinaryToDecimal(binary) << endl << endl;
}

int main (){
    system("cls"); 
    showInterface(); 

    cout << endl;
    return 0;
}   