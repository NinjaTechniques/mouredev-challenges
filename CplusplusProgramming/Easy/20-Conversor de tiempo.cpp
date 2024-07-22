#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long

// ALT + 124 = |

ll convertDaysToMilliseconds (int days){
    const ll BASE = 86400000;
    return (ll)days * BASE;
}

ll convertHoursToMilliseconds (int hours){
    const ll BASE = 3600000;
    return (ll)hours * BASE;
}

ll convertMinutesToMilliseconds (int minutes){
    const ll BASE = 60000;
    return (ll)minutes * BASE;
}

ll convertSecondsToMilliseconds(int seconds){
    const ll BASE = 1000;
    return (ll)seconds * BASE;
}

bool validateTime(int time){
    if (time <= 0) {
        return false;
    }

    return true;
}

void printTimeConverter (int days, int hours, int minutes, int seconds){

    cout << days << " days in milliseconds: " << convertDaysToMilliseconds(days) << endl;
    cout << hours << " hours in milliseconds: " << convertHoursToMilliseconds(hours) << endl;
    cout << minutes << " minutes in milliseconds: " << convertMinutesToMilliseconds(minutes) << endl;
    cout << seconds << " seconds in milliseconds: " << convertSecondsToMilliseconds(seconds) << endl;
}

int main (){
    system("cls");

    int days = 0, hours = 0, minutes = 0, seconds = 0, step = 1;
    bool isValid = false;

    do {

        if (step == 1) {
            cout << "Number of days: "; cin >> days;
            isValid = validateTime(days);

            if (!isValid) {continue;}
            step++;
        }


        if (step == 2) {
            cout << "Number of hours: "; cin >> hours;
            isValid = validateTime(hours);

            if (!isValid) {continue;}
            step++;
        }
        

        if (step == 3) {
            cout << "Number of minutes: "; cin >> minutes;
            isValid = validateTime(minutes);

            if (!isValid) {continue;}
            step++;
        }
        
        if (step == 4) {
            cout << "Number of seconds: "; cin >> seconds;
            isValid = validateTime(seconds);

            if (!isValid) {continue;}
            step++;
        }

    }while (!isValid);
    
    cout << endl;
    system("cls");
    printTimeConverter(days, hours, minutes, seconds);


    cout << endl << endl;
    return 0;
}