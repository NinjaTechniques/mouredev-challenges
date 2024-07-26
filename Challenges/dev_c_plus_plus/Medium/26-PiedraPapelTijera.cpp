#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int generateRandomValues(int min, int max){
    static random_device rd;
    static default_random_engine eng(rd());
    static uniform_int_distribution<int> dis(min, max);

    int randomValue = dis(eng);
    return randomValue;
}

string convertRandomValueToString(int value){
    const string PAPER = "P", ROCK = "R", SCISSORS = "S";

    if (value == 1) {
        return PAPER;
    }
    else if (value == 2) {
        return ROCK;
    }

    return SCISSORS;
}

//! Free Memory
pair<pair<string, string>*, int> generateGame(int numberOfGames){
    const int MIN = 1, MAX = 3;

    pair<string, string>* game = new pair<string, string>[numberOfGames]; // Arreglo de pairs
    int randomValue1 = 0, randomValue2 = 0;


    for (int i{}; i < numberOfGames; i++) {
        randomValue1 = generateRandomValues(MIN, MAX);
        randomValue2 = generateRandomValues(MIN, MAX);
        
        game[i] = {convertRandomValueToString(randomValue1), convertRandomValueToString(randomValue2)};
    }


    return {game, numberOfGames};
}

pair<pair<string, string>*, int> generateGameDefault(){
    pair<string, string>* game = new pair<string, string>[3];

    game[0] = {"R", "P"};
    game[1] = {"R", "S"};
    game[2] = {"S", "S"};
    
    return {game, 3};
}

bool checkPaper (string value){
    const string PAPER = "P";

    if (value == PAPER) {
        return true;
    }

    return false;
}

bool checkRock (string value){
    const string ROCK = "R";

    if (value == ROCK) {
        return true;
    }

    return false;
}

bool checkScissors (string value){
    const string SCISSORS = "S";

    if (value == SCISSORS) {
        return true;
    }

    return false;
}

void checkGame(int& countPlayer1, int& countPlayer2, string player1, string player2){

    if (checkRock(player1) && checkPaper(player2)) {
       countPlayer2++; return;
    }
    else if (checkPaper(player1) && checkRock(player2)){
        countPlayer1++; return;
    }


    if (checkRock(player1) && checkScissors(player2)){
        countPlayer1++; return;
    }
    else if (checkScissors(player1) && checkRock(player2)){
        countPlayer2++; return; 
    }


    if (checkPaper(player1) && checkScissors(player2)){
        countPlayer2++; return;
    }
    else if (checkScissors(player1) && checkPaper(player2)){
        countPlayer1++; return;
    }
    else {
        countPlayer1++; countPlayer2++; return; //Empate
    }

    return;
}

string whoIsWinner (pair<pair<string, string>*, int> game){
    int countPlayer1 = 0, countPlayer2 = 0;
    string winner = "none", player1 = "", player2 = "";

    int length = game.second;

    for (int i = 0; i < length; i++) {
        // 1: Acceder al arreglo (Game). 
        // 2: Acceder al primer elemento del pair<string <-- , string>
        // 3: Verificar si ese string coincide con Paper, Rock o Scissors.

        player1 = game.first[i].first;
        player2 = game.first[i].second;
      
        checkGame(countPlayer1, countPlayer2, player1, player2);   
    }


    if (countPlayer1 == countPlayer2) {
        winner = "Tie";
        return winner;
    }
    else if (countPlayer1 > countPlayer2){
        winner = "Player 1";
        return winner;
    }
    else {
        winner = "Player 2";
        return winner;
    }

    return winner;
}

void printGame(pair<pair<string, string>*, int> game){
    int length = game.second;

    for (int i = 0; i < length; i++) {
        cout << "[" << game.first[i].first << "," << game.first[i].second << "]  ";
    }

    cout << endl << endl;
}


int main (){
    system("cls");
    srand(time(NULL));

    pair<pair<string, string>*, int> game = generateGame(3);
    printGame(game);

    cout << "The winner is: " << whoIsWinner(game);


    cout << endl;
    delete[] game.first;
    return 0;
}
