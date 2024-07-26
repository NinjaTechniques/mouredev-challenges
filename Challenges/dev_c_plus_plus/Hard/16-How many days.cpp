#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea una función que calcule y retorne cuántos días hay entre dos cadenas
 * de texto que representen fechas.
 * - Una cadena de texto que representa una fecha tiene el formato "dd/MM/yyyy".
 * - La función recibirá dos String y retornará un Int.
 * - La diferencia en días será absoluta (no importa el orden de las fechas).
 * - Si una de las dos cadenas de texto no representa una fecha correcta se
 *   lanzará una excepción.
 */

//#include <exception>
class DateExeption: public exception {
private:
    bool incorrectDateFormat;

public:
    DateExeption() {}
    DateExeption(bool incorrectDateFormat) : incorrectDateFormat(incorrectDateFormat) { }

    //Sobreescritura del metodo What de la clase Exception
    const char* what() const throw() {
        //Esta función devuelve un puntero a una cadena de caracteres que describe el error

        if (incorrectDateFormat == false) {
            return "Date format error! :(";
        }

        return "";
    }

};


// * VALIDACIONES DE LAS FECHAS

bool isLeapYear(int year){
    //Verificamos si el year es bisiesto

    if (year % 4 == 0) {
        if (year % 100 == 0) {
            if (year % 400 == 0) {
                return true;
            }
            return false;
        }
        return true;
    }

    return false;
}

int getDay (string date) {
    string aux = "";

    for (int i = 0; i < date.length(); i++) {

        if (date[i] == '/') {
            break;
        }

        aux += date[i];
    }

    return stoi(aux);
}

int getMonth(string date) { 
    string aux = "";
    int count = 0;

    for (int i = 0; i < date.length(); i++) {
        if (date[i] == '/'){
            count++;
            if (count == 2) {break;}

            continue;
        }

        if (count == 1) {
            aux += date[i];
        }

    }

    return stoi(aux);

}

int getYear(string date){

    string aux = "";
    int count = 0;

    for (int i = 0; i < date.length(); i++) {
        if (date[i] == '/'){
            count++;
            continue;
        }

        if (count == 2) {
            aux += date[i];
        }

    }

    return stoi(aux);

}

int* arrayDate (string date1, string date2){
    int day1 = getDay(date1);
    int month1 = getMonth(date1);
    int year1 = getYear(date1);

    int day2 = getDay(date2);
    int month2 = getMonth(date2);
    int year2 = getYear(date2); 

    int* array = new int[6];
    array[0] = day1;
    array[1] = day2;
    array[2] = month1;
    array[3] = month2;
    array[4] = year1;
    array[5] = year2;

    return array;
}

bool isValidDate (string date){
    int day = getDay(date);
    int month = getMonth(date);
    int year = getYear(date);
    bool flag = false;

    auto validateMonthsOf30Days = [day, month] () -> bool {
        if(month == 4 || month == 6 || month == 9 || month == 11) {
            if (day >= 1 && day <= 30) {
                return true;
            }

            return false;
        }

        return false;
    };

    bool validateMonthOf31Days = [] (int day_, int month_) -> bool {
        if(month_ == 1 || month_ == 3 || month_ == 5 || month_ == 7 || month_ == 8 || month_ == 10 || month_ == 12) {
            if (day_ >= 1 && day_ <= 31) {
                return true;
            }

            return false;
        }

        return false;

    }(day, month);

    auto validateMonthOf28Days = [&day, month, year] () -> bool {
        if (month == 2) {
            if (isLeapYear(year)) {
                if (!(day >= 1 && day <= 29)) {
                    return false;
                }

                return true;
            }
            else {
                if (!(day >= 1 && day <= 28)) {
                    return false;
                }

                return true;
            }
        }
       
        return false;
    };

   
   //Validando fecha con las lambdas
   if (validateMonthsOf30Days()) {
        flag = 1;
   }
   else if (validateMonthOf31Days) {
        flag = 1;
   }
   else if (validateMonthOf28Days()) {
        flag = 1;
   }
   else {
        flag = 0;
   }

    return flag;
}

int validateMajorDate(string date1, string date2){
    const int DATE1 = 1;
    const int DATE2 = 2;

    int* date = arrayDate(date1, date2);

    if (date[5] != date[4]) {
        if (date[5] > date[4]){
            return DATE2;
        }
        else {
            return DATE1;
        }
    }

    if (date[3] != date[2]) {
        if (date[3] > date[2]){
            return DATE2;
        }
        else {
            return DATE1;
        }
    }

    if (date[1] != date[0]) {
        if (date[1] > date[0]){
            return DATE2;
        }
        else {
            return DATE1;
        }
    }

    return DATE2;
}


// * NUMERO DE DIAS POR MES
map<int, int> daysPerMonth(int year){
    map<int, int> mp; // Month, Days

    if (isLeapYear(year)) {
        mp[2] = 29;
    }
    else{
        mp[2] = 28;
    }

    mp[1] = 31;
    mp[3] = 31;
    mp[4] = 30;
    mp[5] = 31;
    mp[6] = 30;
    mp[7] = 31;
    mp[8] = 31;
    mp[9] = 30;
    mp[10] = 31;
    mp[11] = 30;
    mp[12] = 31;

    return mp;
}

/*
    * Funciones para calcular la diferencia de dias entre 2 fechas
    * El day1 <= day2 y month1 <= month2 y year1 <= year2
    * array[6] = {day1, day2, month1, month2, year1, year2};
*/

int numberOfDaysForEqualsMonthsAndYears(string date1, string date2){
    int* date = arrayDate(date1, date2);

    if (date[2] == date[3] && date[4] == date[5]) {
        return abs(date[0] - date[1]);
    }

    return -1;
}

int numberOfDaysForDifferentMonthsButSameYears(string date1, string date2){
    int* date = arrayDate(date1, date2);

    
    if (date[2] != date[3] && date[4] == date[5]) {
        map<int , int> daysPerMonth_ = daysPerMonth(date[4]);
        int countDays = (daysPerMonth_[date[2]] - date[0]); // Resultante

        for (int i = date[2] + 1; i <= date[3]; i++) {
            if (i != date[3]) {
                countDays += daysPerMonth_[i];
                continue;
            }

            countDays += date[1];
        }

        return abs(countDays);
    }


    return -1;
}

int numberOfDaysForDifferentYears(string date1, string date2){
    int* date = arrayDate(date1, date2);

    if (date[4] != date[5]) {
        map<int, int> daysPerMonth_ = daysPerMonth(date[4]);

        int countDays = daysPerMonth_[date[2]] - date[0];
        int months = date[2];
        int years = date[4];

        while(true) {

            if(months == 12) {
                years++;

                if (isLeapYear(years)) {
                    daysPerMonth_[2] = 29;
                }
                else {
                    daysPerMonth_[2] = 28;
                }

                months = 0;
            }
                
            months++;

            if (years != date[5]) {
                countDays += daysPerMonth_[months];
                continue;
            }
            else {
                if (months != date[3]){
                    countDays += daysPerMonth_[months];
                }
                else {
                   countDays += date[1];
                   break;     
                }
            }
        }

        return abs(countDays);
    }

    return -1;
}

//Generalmente la fecha menor es Date 1 y la mayor es Date 2
int numberOfDaysBetweenTwoDates(string date1, string date2){

    try {

        if(isValidDate(date1) && isValidDate(date2)) {
        
            if (validateMajorDate(date1, date2) == 1) {
                string aux = date2;
                date2 = date1;
                date1 = aux;
            }

            if (numberOfDaysForDifferentYears(date1, date2) != -1) {
                return numberOfDaysForDifferentYears(date1, date2);
            }

            if (numberOfDaysForEqualsMonthsAndYears(date1, date2) != -1) { 
                return numberOfDaysForEqualsMonthsAndYears(date1, date2);
            }
            
            else if (numberOfDaysForDifferentMonthsButSameYears(date1, date2) != -1) { 
                return numberOfDaysForDifferentMonthsButSameYears(date1, date2);
            }

        }

        if (!isValidDate(date1)) {
            throw DateExeption(isValidDate(date1));
        }
        else {
            throw DateExeption(isValidDate(date2));
        }


    }catch(const exception &e){
        system("cls");
        cout << "[MESSAGE] : " << e.what() << endl; 

    }
    
    return -1;
}


int main (){
    system("cls");

    string date1 = "", date2 = "";
    cout << "[DATE FORMAT] -> dd/MM/yyyy" << endl;
    cout << "First date: "; getline(cin, date1);
    cout << "Second date: "; getline(cin, date2); cout << endl;

    system("cls");
    cout << "The number of days between [" << date1 << "] and [" << date2 << "] is: " << numberOfDaysBetweenTwoDates(date1, date2) << endl;
  
    cout << endl;
    return 0;
}