/*
 * Escribe una función que reciba dos palabras (String) y retorne
 * verdadero o falso (Bool) según sean o no anagramas.
 * - Un Anagrama consiste en formar una palabra reordenando TODAS
 *   las letras de otra palabra inicial.
 * - NO hace falta comprobar que ambas palabras existan.
 * - Dos palabras exactamente iguales no son anagrama.
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool anagrama (string word1, string word2){
    bool flag = 1;

    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());

    for(int i {}; i < word1.size(); i++) {
        if (word1[i] != word2[i]) {
            flag = 0;
            break;
        }
    }

    return flag;
}

int main (){
    system("cls");

    string word1, word2;
    cout << "Enter a word: "; cin >> word1;
    cout << "Enter another word: "; cin >> word2;
    
    cout << anagrama(word1, word2) << endl;

    cout << endl;
    return 0;
}