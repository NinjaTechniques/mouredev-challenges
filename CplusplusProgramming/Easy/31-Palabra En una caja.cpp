#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

pair<string, pair<int , int>> transformPhrase(string phrase){
    //stringstream inputText (phrase);
    string newPhrase = "", aux = "";
    int maxLength = 0, quantityRows = 0;

    for (char word: phrase) {
        // Test: "Hola soy Leidy\n"
        if (word == ' ' || word == '\n' )  { newPhrase += "\n"; quantityRows++; continue; }
        newPhrase += word;
    }

    newPhrase += "\n";
    
    for (char e: newPhrase) {
        if (e == '\n' && aux.length() > maxLength) {
            maxLength = aux.length();
            aux = "";
            continue;
        }

        aux += e;
    }

    return {newPhrase, {maxLength, quantityRows + 1}};
}


void stringInBox(string phrase){
    pair<string, pair<int, int>> data =  transformPhrase(phrase);
    string newPhrase = data.first;
    int maxLength = data.second.first;
    int quantityRows = (data.second.second + 2);
    int index = 0;
    
   for (int i = 0; i < quantityRows; i++) {
        if (i == 0 || i == (quantityRows - 1)) {
            for (int j = 0; j < maxLength + 1; j++) { cout << "*"; }
        }
        else {
            for (int j = 0; j < maxLength; j++) {
                if (j == 0) { cout << "* "; continue; }
                if (j == (maxLength - 1)){ cout << "*"; continue;}
                    
                if(newPhrase[index] == '\n') { cout << " "; continue; }
                cout << newPhrase[index]; index++;

            }
    
            index++;
        }

        cout << endl;
   }
}


int main (){
    system("cls");
    string phrase = "";
    cout << "Enter a phrase: "; getline(cin, phrase);

    cout << endl << endl;
    stringInBox(phrase);    

    cout << endl << endl;
    return 0;
}