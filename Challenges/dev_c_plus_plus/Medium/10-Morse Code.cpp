#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea un programa que sea capaz de transformar texto natural a código
 * morse y viceversa.
 * - Debe detectar automáticamente de qué tipo se trata y realizar
 *   la conversión.
 * - En morse se soporta raya "—", punto ".", un espacio " " entre letras
 *   o símbolos y dos espacios entre palabras "  ".
 * - El alfabeto morse soportado será el mostrado en
 *   https://es.wikipedia.org/wiki/Código_morse.
 */

string repeatSimbols (string caracter, int repetitions){
    string repeat(repetitions, caracter[0]);

    return repeat;
}

void toUpperCase(string &value){
    for (int i{}; i < value.length(); i++) {
        value[i] = toupper(value[i]);
    }
}

void toLowerCase (string &value){
    for (int i = 0; i < value.length(); i ++) {
        value[i] = tolower(value[i]);
    }
}

map<char, string> morseCode(){
    const string NOTFOUND = "#";
    const string POINT = ".";
    const string BAR = "-";
    map<char, string> mp;

    // Letters
    mp['A'] = POINT + BAR;
    mp['B'] = BAR + repeatSimbols(POINT, 3);
    mp['C'] = BAR + POINT + BAR + POINT;
    mp['D'] = BAR + repeatSimbols(POINT, 2);
    mp['E'] = POINT;
    mp['F'] = repeatSimbols(POINT, 2) + BAR + POINT;
    mp['G'] = repeatSimbols(BAR, 2) + POINT;
    mp['H'] = repeatSimbols(POINT, 4);
    mp['I'] = repeatSimbols(POINT, 2);
    mp['J'] = POINT + repeatSimbols(BAR, 3);
    mp['K'] = BAR + POINT + BAR;
    mp['L'] = POINT + BAR + "..";
    mp['M'] = repeatSimbols(BAR, 2);
    mp['N'] = BAR + POINT;
    mp['O'] = repeatSimbols(BAR, 3);
    mp['P'] = POINT + repeatSimbols(BAR, 2) + POINT;
    mp['Q'] = repeatSimbols(BAR, 2) + POINT + BAR;
    mp['R'] = POINT + BAR + POINT;
    mp['S'] = repeatSimbols(POINT, 3);
    mp['T'] = BAR;
    mp['U'] = repeatSimbols(POINT, 2) + BAR;
    mp['V'] = repeatSimbols(POINT, 3) + BAR;
    mp['W'] = POINT + repeatSimbols(BAR, 2);
    mp['X'] = BAR + repeatSimbols(POINT, 2) + BAR;
    mp['Y'] = BAR + POINT + "--";
    mp['Z'] = repeatSimbols(BAR, 2) + repeatSimbols(POINT, 2);

    //Numbers
    mp['1'] = POINT + repeatSimbols(BAR, 4);
    mp['2'] = repeatSimbols(POINT, 2) + repeatSimbols(BAR, 3);
    mp['3'] = repeatSimbols(POINT, 3) + repeatSimbols(BAR, 2);
    mp['4'] = repeatSimbols(POINT, 4) + BAR;
    mp['5'] = repeatSimbols(POINT, 5);
    mp['6'] = BAR + repeatSimbols(POINT, 4);
    mp['7'] = repeatSimbols(BAR, 2) + repeatSimbols(POINT, 3);
    mp['8'] = repeatSimbols(BAR, 3) + repeatSimbols(POINT, 2);
    mp['9'] = repeatSimbols(BAR, 4) + POINT;
    mp['0'] = repeatSimbols(BAR, 5);


    //Special Simbols
    mp['.'] = ".-.-.-";
    mp[','] = repeatSimbols(BAR, 2) + repeatSimbols(POINT, 2) + repeatSimbols(BAR, 2);
    mp['?'] = repeatSimbols(POINT, 2) + repeatSimbols(BAR, 2) + repeatSimbols(POINT, 2);
    mp['/'] = BAR + repeatSimbols(POINT, 2) + BAR + POINT;

    // Unsupported Characters
    mp[';'] = NOTFOUND;
    mp['<'] = NOTFOUND;
    mp['>'] = NOTFOUND;
    mp['['] = NOTFOUND;
    mp[']'] = NOTFOUND;
    mp['{'] = NOTFOUND;
    mp['}'] = NOTFOUND;
    mp['#'] = NOTFOUND;
    mp['`'] = NOTFOUND;
    mp['$'] = NOTFOUND;
    mp['^'] = NOTFOUND;
    mp['%'] = NOTFOUND;
    mp['*'] = NOTFOUND;
    mp['~'] = NOTFOUND;


    return mp;
}

pair<string, string> convertTextToMorseCode(string text){
    const string ERROR = "Error in input. Cannot translate the highlighted characters :(";
    map<char, string> morse = morseCode();
    map<char, string>::iterator it;

    toUpperCase(text);
    string aux = "", message = "";
    pair<string, string> result;


    int countErrors = 0;

    for (char e: text) {
        if (e == ' ') {aux += " / "; continue;}

        if (morse.count(e) > 0) { // Si es mayor a cero significa que hay una coincidencia.
            if (morse[e] == "#") {countErrors++;}

            aux += morse[e] + " ";
        }   
    }

    if (countErrors > 0) {
        message = ERROR + "\nNumber of non-recognizable characters: " + to_string(countErrors) + "\n";
    } 

    result = make_pair(aux, message);
    return result;
}

bool validateMorseCode (string value) {    
    bool flag = false;

    for (int i{}; i < value.length(); i++) {
        if (value[i] == ' ') {continue;}

        if (value[i] == '.'  || value[i] == '-' || value[i] == '/') {
            flag = true;
        }
        else {
            flag = false; break;
        }
    }

    return flag;
}

string convertMorseCodeToText(string value){
    value = value + " ";
    string result = "";

    if (validateMorseCode(value)) {
        
        map<char, string> mp = morseCode();
        string aux = "";

        for (char e: value) {
            if (e == '/') {
               result += " ";
               continue;     
            }


            if (e != ' '){
                aux += e;
            }
            else {
                for (auto it = mp.begin(); it != mp.end(); it++) {
                    if (aux == it->second) {
                        result += it->first;
                        break;
                    }
                }

                aux = "";
            }
        }

        toLowerCase(result);
        return result;
    }

    return result;

}

void printMorseCodeAndText (string value){
    if (validateMorseCode(value)) {
        cout << "The Morse Code in text is: " << convertMorseCodeToText(value) << endl;
        return;
    }

    pair<string, string> morseCode = convertTextToMorseCode(value);
    cout << endl << "[ " << morseCode.second << " ]" << endl << endl;
    cout << "The text in Morse Code is: " <<morseCode.first << endl;
}

int main (){
    system("cls");

    string value = "";
    cout << "Enter the Morse Code or Text: "; getline(cin, value);
    cout << endl << endl;
    printMorseCodeAndText(value);
   
    cout << endl;
    return 0;
}