/*
 * ¡La Tierra Media está en guerra! En ella lucharán razas leales
 * a Sauron contra otras bondadosas que no quieren que el mal reine
 * sobre sus tierras.
 * Cada raza tiene asociado un "valor" entre 1 y 5:
 * - Razas bondadosas: Pelosos (1), Sureños buenos (2), Enanos (3),
 *   Númenóreanos (4), Elfos (5)
 * - Razas malvadas: Sureños malos (2), Orcos (2), Goblins (2),
 *   Huargos (3), Trolls (5)
 * Crea un programa que calcule el resultado de la batalla entre
 * los 2 tipos de ejércitos:
 * - El resultado puede ser que gane el bien, el mal, o exista un empate.
 *   Dependiendo de la suma del valor del ejército y el número de integrantes.
 * - Cada ejército puede estar compuesto por un número de integrantes variable
 *   de cada raza.
 * - Tienes total libertad para modelar los datos del ejercicio.
 * Ej: 1 Peloso pierde contra 1 Orco
 *     2 Pelosos empatan contra 1 Orco
 *     3 Pelosos ganan a 1 Orco
 */

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

string kindRace (int value) { //Raza de bondadosos (Ejercito de Bondadosas)
    map<int, string> mp;

    mp[1] = "Pelosos";
    mp[2] = "Surenos buenos";
    mp[3] = "Enanos";
    mp[4] = "N" + to_string(char(163)) +  "menoreanos";
    mp[5] = "Elfos";

    return mp[value];
}

string evilRace (int value){ //Razas malvadas (Ejercito de Sauron)
    map<int, string> mp;

    mp[1] = "Surenos malos";
    mp[2] = "Orcos";
    mp[3] = "Goblins";
    mp[4] = "Huargos";
    mp[5] = "Trolls";

    return mp[value];
}

int generateRandomNumbers (int min, int max){
    random_device rd;
    default_random_engine engine(rd());
    uniform_int_distribution<int> distribution(min, max);

    int randomValue = distribution(engine);
    return randomValue;
}

int warScore (int race, int members){ //Puntuacion de la guerra
    return race + members;
}

void showResults (){
    int value = generateRandomNumbers(1, 5); //Raza
    int members = generateRandomNumbers(1, 20);
    int armyKindness = warScore(value, members); //Ejercito de bondadosos

    cout << "Kind Race: \n";
    cout << "   -> " << kindRace(value) << ": " << members << "\n\n"; 

    value = generateRandomNumbers(1, 5); //Raza
    members = generateRandomNumbers(1, 20);
    int sauronArmy = warScore(value, members); //Ejercito de Sauron

    cout << "Evil Race: \n";
    cout << "   -> " << evilRace(value) << ": " << members << "\n\n"; 

    cout << armyKindness << " vs. " << sauronArmy << endl;
    if(armyKindness < sauronArmy) {
        cout << "Sauron has won the war!";
    }
    else if (armyKindness > sauronArmy)  {
        cout << "Kinds have won the war!";
    }
    else {
        cout << "The war ended in a tie!";
    }
}


int main (){
    system("cls");
    showResults();

    cout << endl;
    return 0;
}