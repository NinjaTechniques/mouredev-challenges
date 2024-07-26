#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea un programa que invierta el orden de una cadena de texto
 * sin usar funciones propias del lenguaje que lo hagan de forma automática.
 * - Si le pasamos "Hola mundo" nos retornaría "odnum aloH"
 */

string reverse (string value){
    string aux = "";
    for (int i = value.size() - 1; i >= 0; i--) {
        aux += value[i];
    }

    return aux;
}

string recursiveReverse (string value, string aux, int count){
    if (count > value.size()) {
        return aux;    
    }

    aux += value[value.size() - count];
    count++;
    return recursiveReverse(value, aux, count);
}

string recursiveReverse (string value) {
    string aux = "";
    int count = 0;

    return recursiveReverse(value, aux, count);
}

int main (){
    system("cls");

    string text = "";
    cout << "Enter a text: "; getline(cin, text);
    cout << endl;

    cout << "Reverse: " << reverse(text) << endl;
    cout << "Recursive reverse: " << recursiveReverse(text);

    cout << endl;
    return 0;   
}