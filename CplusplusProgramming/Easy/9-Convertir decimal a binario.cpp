#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string convertDecimaltoBinary (int value, string &aux){

    if ((value / 2) == 0) {
        return to_string(value);
    }
    else {   
        aux += convertDecimaltoBinary(value/2, aux);    
        return to_string(value % 2);
    }
}

string valueOfConvertDecimaltoBinary(int value){
    string aux = "";
    convertDecimaltoBinary((value * 2), aux);

    return aux;
}


int main (){
    system("cls");

    int number = 0;
    cout << "Enter the only one number: "; cin >> number;
    cout << endl;

    cout << "The number in binary is: " << valueOfConvertDecimaltoBinary(number) << endl;

    return 0;
}