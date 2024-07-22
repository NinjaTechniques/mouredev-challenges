#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)
#define fori(i, n) for(int i=0; i<n; i++)

/*
 * Crea una función que reciba dos array, un booleano y retorne un array.
 * - Si el booleano es verdadero buscará y retornará los elementos comunes
 *   de los dos array.
 * - Si el booleano es falso buscará y retornará los elementos no comunes
 *   de los dos array.
 * - No se pueden utilizar operaciones del lenguaje que
 *   lo resuelvan directamente.
 */

template<typename T>
T generateRandomValues (T min, T max){

    static random_device rd;
    static default_random_engine ng(rd());

    T randomValue;

    if constexpr  (is_same_v<T, int> || is_same_v<T, char>) {
        static uniform_int_distribution<T> dis(min, max);
        randomValue = dis(ng);
    }
    else if constexpr (is_same_v<T, double> || is_same_v<T, float> ) {
        static uniform_real_distribution<T> dis(min, max);
        randomValue = dis(ng);
    }

    
    return randomValue;
}


enum typeOfData {
    INT,
    DOUBLE,
    FLOAT,
    CHAR
};

template<typename T>
vector<T> createArray (int size, typeOfData type){
    vector<T> array;

    if constexpr (is_same_v<T, char>) {

        char ascii  = 'a';
        int value = 0;

        fori(i, size) {
            
            while(true) {
                value = generateRandomValues<int>(65, 122);

                if ( !(value >= 91 && value <= 96) ) {
                    break;
                }
            }

            ascii = (char)value;
            array.push_back(ascii);
        }
    }


    if (type == typeOfData::INT || type == typeOfData::DOUBLE || type == typeOfData::FLOAT) {
        T max = 0;
        T min = 0; 
        T value = 0;
        
        cout << "Enter the max and min value: " << endl;
        cout << "MIN: "; cin >> min;
        cout << "MAX: "; cin >> max;
        cout << endl;

        fori(i, size) {
            value = generateRandomValues<T>(min, max);
            array.push_back(value);
        }
        
    }


    return array;
}

template<typename T>
vector<T> commonValues (vector<T>  array1, vector<T> array2){
    vector<T> array;
    T value1, value2;

    sort(array1.begin(), array1.end());
    sort(array2.begin(), array2.end());

    fori (i, array1.size()) {
        value1 = array1[i];
        fori(j, array2.size()) {
            value2 = array2[j];

            if (value1 == value2) {
                array.push_back(value1);
                array2.erase(array2.begin() + j);
                break;
            }
        }
    }

    return array;
}

template<typename T>
vector<T> differentValues(vector<T>  array1, vector<T> array2){
    vector<T>  array;
    T value1, value2;

    vector<T> aux = commonValues<T>(array1, array2);
    bool flag1, flag2;

    fori(i, array1.size()){
        flag1 = true;
        flag2 = true;

        value1 = array1[i];
        value2 = array2[i];

        fori(j, aux.size()) {
            
            if (value1 == aux[j]) {
                flag1 = false;
            }   

            if (value2 == aux[j]) {
                flag2 = false;
            }
        }

        if (flag1) {
            array.push_back(value1);   
        }
        
        if (flag2){
            array.push_back(value2);   
        }
    }

    return array;
}

template<typename T>
vector<T> sets(vector<T> array1, vector<T> array2, bool flag){
    vector<T> array;

    if (flag) {
        array = commonValues<T>(array1, array2);
    }
    else {
        array = differentValues<T>(array1, array2);
    }

    return array;
}


template<typename T>
void printArray(vector<T> array) {
    fori(i, array.size()){
        cout << array[i] << " ";
    }
}

int main (){
    system("cls");
    srand(time(NULL));
    
    vector<char> array1 = createArray<char>(10, typeOfData::CHAR);
    vector<char> array2 = createArray<char>(10, typeOfData::CHAR);
    vector<char> result = sets<char>(array1, array2, true);

    cout << "ARRAY 1: ";
    printArray<char>(array1);
    cout << endl << endl;
    
    cout << "ARRAY 2: ";
    printArray<char>(array2);
    cout << endl << endl;

    cout << "RESULT: ";
    printArray<char>(result);
    cout << endl;
    

    cout << endl;
    return 0;
}