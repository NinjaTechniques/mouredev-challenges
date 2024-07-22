#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea una función que reciba un String de cualquier tipo y se encargue de
 * poner en mayúscula la primera letra de cada palabra.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
 */

string convertTextToPascalCase(string text){
    bool flag = 1;

    for (int i{}; i < text.length(); i ++) {
        if (text[i] == ' ') {
            flag = 1;
            continue;
        }

        if (flag) {
            text[i] = toupper(text[i]);
            flag = 0;
        }
    }

    return text;

}


int main (){
    system("cls");

    string value = "";
    cout << "Enter a string: "; getline(cin, value); cout << endl;
    cout << "String in Pascal Case: " << convertTextToPascalCase(value) << endl;

    cout << endl;
    return 0;
}