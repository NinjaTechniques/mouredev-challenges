#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea un programa que cuente cuantas veces se repite cada palabra
 * y que muestre el recuento final de todas ellas.
 * - Los signos de puntuación no forman parte de la palabra.
 * - Una palabra es la misma aunque aparezca en mayúsculas y minúsculas.
 * - No se pueden utilizar funciones propias del lenguaje que
 *   lo resuelvan automáticamente.
 */

void toLowerCase (string &value){ 
    int ascii = 0;

    for (int i{}; i < value.length(); i++) {
        ascii = value[i];
        if (!((ascii >= 33 && ascii <= 47) || (ascii >= 58 && ascii <= 63))) {
            value[i] = tolower(value[i]);
        }
        else {
            value[i] = ' ';
        }
    }
}


map<string, int> repetitions2(string value) {
    toLowerCase(value);

    map<string, int> m;
    stringstream ss(value);
    string aux;

    //StringStream extrae cada palabra y lo carga en aux
    while(ss >> aux) {
        map<string, int>::iterator it = m.find(aux);

        if (it != m.end()) {
            it->second++;
        }
        else {
            m[aux] = 1;
        }
    }

    return m;
}

map<string, int> repetitions(string value){
    map<string, int> mp;
    string aux = "";
    int ascii = 0, count = 0;  

    toLowerCase(value); // Se altera y se pone en minuscula la copia (paso por valor) de "value"

    for (char e: value) {
       ascii = int(e);
       count++;

       if (ascii != 32){
            if (!((ascii >= 33 && ascii <= 47) || (ascii >= 58 && ascii <= 63))) {
                aux += e;
            }
       }
       
        if (ascii == 32 || count == value.length()) {
            //Si encuentra el valor devuelve un iterador key-value, sino devuelve un iterador del final(end) del map.
            //auto it = mp.find(aux); 
            map<string, int>::iterator it = mp.find(aux);

            if (it != mp.end()) { // Verificamos si el iterador no es el final del map
                it->second++;
            }
            else {
                mp[aux] = 1;
            }

            aux = "";
        }     

    }

    return mp;

}

void printRepetitions(string value){
    map<string, int> mp = repetitions2(value);

    /*
    Recorrer el map usando iteradores
    for (map<string, int>::iterator it = mp.begin(); it != mp.end(); it++) {
        cout << it->first << " : " << it->second << endl;
    }
    */
    
    //Recorrer map con For basado en rangos
    for (pair<const string, int> &it: mp) {
        cout << it.first << " : " << it.second << endl;
    }
    
}

int main (){
    system("cls");

    string text = "";
    cout << "Enter a text: "; getline(cin, text);
    cout << endl;

    printRepetitions(text);

    cout << endl;
    return 0;
}