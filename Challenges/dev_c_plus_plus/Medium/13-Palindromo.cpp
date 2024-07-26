#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Escribe una función que reciba un texto y retorne verdadero o
 * falso (Boolean) según sean o no palíndromos.
 * 
 * Un Palíndromo es una palabra o expresión que es igual si se lee
* de izquierda a derecha que de derecha a izquierda.
 * NO se tienen en cuenta los espacios, signos de puntuación y tildes.
 * Ejemplo: Ana lleva al oso la avellana.
 */

void toLowerCase(string &value){
    for (int i = 0; i < value.length(); i++) {
        value[i] = tolower(value[i]);
    }
}

void clearWord(string &word){
    string aux = "";

    for (int i = 0; i < word.length(); i++) {
        if (((int)word[i] >= 32 && (int)word[i] <= 47) || ((int)word[i] >= 58 && (int)word[i] <= 64) || ((int)word[i] >= 91 && (int)word[i] <= 96)) {
            continue;
        }

        aux += word[i];
    }

    word = aux;
}

bool isPalindrome(string word){
    bool flag = true;
    int half = word.length() / 2;

    toLowerCase(word);
    clearWord(word);

    for (int i = 0; i < half; i++) {
        if (word[i] != word[word.length() - 1 - i]) {
            flag = false;
            break;
        }
    }

    return flag;
}

int main (){
    system("cls");

    string word = "";
    cout << "Enter a word or phase: "; getline(cin, word);
    cout << endl;

    cout << "Is it Polindrome? : " << isPalindrome(word) << endl;


    cout << endl;
    return 0;
}