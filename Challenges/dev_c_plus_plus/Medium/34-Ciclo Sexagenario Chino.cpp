#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

map<int, string> chineseAnimals () {
    map<int, string> animals;

    animals[1] = "Rat";
    animals[2] = "Ox";
    animals[3] = "Tiger";
    animals[4] = "Rabbit";
    animals[5] = "Dragon";
    animals[6] = "Snake";
    animals[7] = "Horse";
    animals[8] = "Sheep";
    animals[9] = "Monkey";
    animals[10] = "Rooster";
    animals[11] = "Dog";
    animals[12] = "Pig";

    return animals;
}

map<int, string> chineseElements(){
    map<int, string> elements;

    elements[4] = "Wood";
    elements[6] = "Fire";
    elements[8] = "Earth";
    elements[0] = "Metal";
    elements[2] = "Water";

    return elements;
}

int baseYear(int year){
    const int GENERAL_CYCLE = 60;
    const int SUB_CYCLE = 12;
    const int BASE = 4;

    if (year % SUB_CYCLE != BASE){
        int remainder = (year % SUB_CYCLE); // El restante

        switch (remainder)
        {
        case 0: remainder = 12;  break;
        case 1: remainder = 13;  break;
        case 2: remainder = 14;  break;
        case 3: remainder = 15;  break;
        default: break;
        }

        return year - (remainder - 4);
    }

    return year;
}

pair<string , string> chineseSexagenaryCycle(int year) {
    int baseYear_ = baseYear(year);
    int valueElement = (baseYear_ % 10);

    map<int, string> listAnimals = chineseAnimals();
    string animal = listAnimals[1]; 
    map<int, string> listElements = chineseElements();
    string element = listElements[valueElement];

    pair<int, int> countElements = {1, valueElement};
    int countAnimals = 1;

    if (baseYear_ != year) {
        while (baseYear_ != year){ 
            baseYear_++; 
            countAnimals++; 

            if (countElements.first == 2) { 
                countElements.second += 2; 

                if (countElements.second == 10) { countElements.second = 0; }
                else if (countElements.second == 12){ countElements.second = 2; }
                
                countElements.first = 1;
                continue;
            }
            countElements.first++; 
        }

        element = listElements[countElements.second];
        animal = listAnimals[countAnimals];
    }
    
    return {element, animal};
}

int main () {
    system("cls");

    int year = 0;
    cout << "Enter only one year: "; cin >> year;
    cout << endl << endl;

    pair<string ,string> result = chineseSexagenaryCycle(year);
    cout << "Element: " << result.first << endl;
    cout << "Animal: " << result.second << endl;


    cout << endl << endl;
    return 0;
}