#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
// ALT + 124 = |


int generateRandomValues (int min, int max){
    //int random = 1 + rand() % (2 + 1);    

    random_device rd;
    default_random_engine eng(rd());
    uniform_int_distribution<int> dis(min, max);

    int randomValue = dis(eng);
    return randomValue;
}

// ! Delete array of strings -> delete[] instructions
string * createInstructions(int arraySize){
    string* instructions = new string[arraySize]; 


    for (int i{}; i < arraySize; i ++) {
        if (generateRandomValues(1, 2) == 1) {
            instructions[i] = "run";
            continue;
        }
        
        instructions[i] = "jump";
    }

    return instructions;
}

string createTrack(int arraySize){

    string track = "";

    for (int i{}; i < arraySize; i++) {
        if (generateRandomValues(1, 2) == 1) {
            track += "_";
            continue;
        }

        track += "|";
    }

    return track;
}

pair<bool, string> isWinner (string *instructions, string track){
    bool flag = 1;
    pair<bool, string> result;

    for (int i{}; i < track.length(); i++) {
        if (track[i] == '_' && instructions[i] == "jump") {
            flag = 0;
            track[i] = 'x';
        }
        else if (track[i] == '|' && instructions[i] == "run"){
            flag = 0;
            track[i] = '/';
        }
    }

    result = {flag, track};
    return result;
}

void startRace(){
    int arraySize  = generateRandomValues(5, 10);
    string * athleteInstructions = createInstructions(arraySize);
    string track = createTrack(arraySize);
    
    cout << "THE TRACK: " << endl;
    cout << track << endl;
    cout << endl;

    cout << "THE ATHLETE: " << endl;
    
    for (int i = 0; i < arraySize; i++) {
        if (i != arraySize - 1) {
            cout << athleteInstructions[i] << "->";
            continue;
        }

        cout << athleteInstructions[i];
    }

    pair<bool, string> winner = isWinner(athleteInstructions, track);

    cout << endl;
    cout << endl << "THE TRACK AFTER: " << endl;
    cout << winner.second << endl;

    cout << endl << "Did he win the race? : " << winner.first << endl;
    delete[] athleteInstructions; // Liberar memoria de la funcion CreateInstructions
}

int main (){
    system("cls");
    srand(time(NULL));

    startRace();

    cout << endl;
    return 0;
}