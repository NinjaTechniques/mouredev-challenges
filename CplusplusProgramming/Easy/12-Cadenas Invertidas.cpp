#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea una función que reciba dos cadenas como parámetro (str1, str2)
 * e imprima otras dos cadenas como salida (out1, out2).
 * - out1 contendrá todos los caracteres presentes en la str1 pero NO
 *   estén presentes en str2.
 * - out2 contendrá todos los caracteres presentes en la str2 pero NO
 *   estén presentes en str1.
 */

void toLowerCase (string &value){
    for (int i = 0; i < value.length(); i ++) {
        value[i] = tolower(value[i]);
    }
}


string presentAndNotPresentCharacters(string value1, string value2){
    map<char, int> mp;
    string result = "";

    toLowerCase(value1);
    toLowerCase(value2);

    for (char e: value2) {
        if (e == ' ') {continue;}
        mp[e]++;
    }

    for (char e: value1) {
        if (e == ' ') {continue;}

        if(mp.count(e) == 0) {
            result += e;
        }
    }

    return result;

}


int main (){
    system("cls");

    
    string str1, str2;
    cout << "Enter the first string: "; getline(cin, str1);
    cout << "Enter the second string: "; getline(cin, str2);
    cout << endl;
    cout << "Output 1: " << presentAndNotPresentCharacters(str1, str2) << endl;
    cout << "Output 2: " << presentAndNotPresentCharacters(str2, str1) << endl;

    cout << endl;
    return 0;
}