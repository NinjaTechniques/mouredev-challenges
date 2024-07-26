#include <bits/stdc++.h>
using namespace std;
#define endl '\n'


/*Exception: Cuando el valor de ataque o defensa es menor o igual a cero*/
class PowerExeption: public exception {
private:
    bool incorrectValuePower;

public:
    PowerExeption() {}
    PowerExeption(bool incorrectValuePower) {
        this->incorrectValuePower = incorrectValuePower;
    }

    const char* what() const throw() {

        if (incorrectValuePower == false) {
            return "The value must be between 1-100! :(";
        }

        return "";
    }

};

//Create enumerate with types of pokemon
enum typesOfPokemon {
    AGUA,
    FUEGO, 
    PLANTA, 
    ELECTRICO,
    OTHER
};

map<pair<typesOfPokemon, typesOfPokemon>, double> effectiveness (){
    map<pair<typesOfPokemon, typesOfPokemon>, double> mp;

    mp[{AGUA, AGUA}] = 0.5;
    mp[{AGUA, FUEGO}] = 0.5;
    mp[{AGUA, PLANTA}] = 2.0;
    mp[{AGUA, ELECTRICO}] = 2.0;

    mp[{FUEGO, AGUA}] = 2.0;
    mp[{FUEGO, FUEGO}] = 0.5;
    mp[{FUEGO, PLANTA}] = 0.5;
    mp[{FUEGO, ELECTRICO}] = 1.0;

    mp[{PLANTA, AGUA}] = 0.5;
    mp[{PLANTA, FUEGO}] = 2.0;
    mp[{PLANTA, PLANTA}] = 0.5;
    mp[{PLANTA, ELECTRICO}] = 0.5;

    mp[{ELECTRICO, AGUA}] = 1.0;
    mp[{ELECTRICO, FUEGO}] = 1.0;
    mp[{ELECTRICO, PLANTA}] = 1.0;
    mp[{ELECTRICO, ELECTRICO}] = 0.5;

    return mp;
}


bool validateValueAttackAndDefense (double value){
    if (value <= 0) {
        return false;
    }

    return true;
}

double damageValue (typesOfPokemon pokemonAttack, typesOfPokemon pokemonDefense, 
               double valueAttack, double valueDefense, 
               map<pair<typesOfPokemon, typesOfPokemon>, double> _effectiveness) {

    if (validateValueAttackAndDefense(valueAttack) && validateValueAttackAndDefense(valueDefense)){
        double _damage = 50 * (valueAttack / valueDefense) * _effectiveness[{pokemonAttack, pokemonDefense}]; 
        return _damage;
    }

    PowerExeption(validateValueAttackAndDefense(valueAttack));
    PowerExeption(validateValueAttackAndDefense(valueDefense));
    return 0.0;
}

double damage (typesOfPokemon pokemonAttack, typesOfPokemon pokemonDefense, 
               double valueAttack, double valueDefense) {

    return damageValue(pokemonAttack, pokemonDefense, valueAttack, valueDefense, effectiveness());
}


int main (){
    system("cls");

    cout << "DAMAGE: " << fixed << setprecision(2) <<  damage(PLANTA, ELECTRICO, 36, 98);

    cout << endl << endl;
    return 0;
}