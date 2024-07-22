#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

bool isLeapYear(int year){
    if (year % 4 == 0) {
        if (year % 100 == 0) {
           if (year % 400 == 0){
                return true;
           }
           return false;
        }
        return true;
    }

    return false;
}

void printLeapYears(int year){
    const int QUANTITY_YEARS = 30;
    int count = 0;

    while (count != QUANTITY_YEARS){
        if (isLeapYear(year)) {
            count++;
            cout << "[" << count << "]: " << year << endl;
        }
        year++; 
    }
}


int main (){
    system("cls");
    int year = 0;
    cout << "Enter only one year: "; cin >> year;
    cout << endl << endl;
    printLeapYears(year);

    cout << endl << endl;
    return 0;
}