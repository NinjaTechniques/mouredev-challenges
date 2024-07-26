#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

class FileExeption: public exception {
private:
    bool isValid;

public:
    FileExeption() { }
    FileExeption(bool isValid) : isValid(isValid) { }

    //Override -> sobreescribir el metodo what de la clase superior exception
    const char* what() const throw() {
        if (!this->isValid) {
            return "Math Operation ERROR!";
        }
            
        return "";
    }
};

template<class T>
class DivisionExeption: public exception{
private:
    T denominator;

public:
    DivisionExeption () { }
    DivisionExeption (T denominator) { 
        this->denominator = denominator;
    }

    const char* what() const throw(){
        if (this->denominator == 0) {
            return "You can't divide by zero";
        }

        return "";
    }
};


bool isValidOperation(string character){
    if (character != "+" || character != "-" || character != "*" || character != "/") {
        return false;
    }
    
    return true;
}


vector<string> readFile(string path){
    //#include <fstream>
    vector<string> operations;

    ifstream file(path);

    if (!file.is_open()) {
        cout << "File couldn't be opened : " << path << endl;
        return operations;
    }

    string line = "";
    while (file >> line){ // Mientras pueda leer.
        operations.push_back(line);
    }

    file.close();

    return operations;
}


template<typename T>
T addition (T a, T b){return a + b;}

template<typename T>
T subtraction (T a, T b){return a - b;}

template<typename T>
T multiplication (T a, T b){return a * b;}

template<typename T>
T division (T a, T b){ return a / b; }


template<typename T>
T doMathCalculations (vector<string> file){
    T result = 0;
    T number = 0;
    int operation = 0, count = 0;
    
    for (string e: file) { 
        count++;
        if (e == "+") {operation = 1; continue;}
        if (e == "-") {operation = 2; continue;}
        if (e == "*") {operation = 3; continue;}
        if (e == "/") {operation = 4; continue;}

        try {
            number = stoi(e);
        }
        catch(const exception& error){
            system("cls");
            throw FileExeption(isValidOperation(e));
            cout << "ERROR MESSAGE: " << error.what() << endl;
            break;
        }


        if (operation == 1 || count == 1) {
            result = addition(result, number);
        }
        else if (operation == 2){
            result = subtraction(result, number);
        }
        else if (operation == 3){
            result = multiplication(result, number);
        }
        else {
            try {

                result = division(result, number);

                if (number == 0) {
                    throw DivisionExeption<T>(number);
                }

            } 
            catch(const exception &e) {
                system("cls");
                cout << "ERROR MESSAGE: " << e.what() << endl;
                break;
            }  
        }
    }

    return result;
}


int main (){
    system("cls");

    string path = "Challenge21.txt"; //Debe estar en la misma carpeta
    vector<string> file = readFile(path);

    cout << "The result is: " << doMathCalculations<double>(file) << endl;

    cout << endl;
    return 0;
}