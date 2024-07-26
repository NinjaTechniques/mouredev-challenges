#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int generateRandomValues (int min, int max){
    static random_device rd;
    static default_random_engine eng(rd());
    static uniform_int_distribution<int> dis(min, max);

    int randomValue = dis(eng);
    return randomValue;
}

// * validaciones para que el juego tenga diferente entre "x" e "o" en 1 o 0.

pair<bool, char> validateMatrix(char **matrix, int rows, int cols){
    pair<bool, char> result;

    int count1 = 0; // 0
    int count2 = 0; // X
    char character;

    for (int i{}; i < rows; i++) {
        for (int j{}; j < cols; j++) {
            character = matrix[i][j];

            if(character == ' ') {continue;}

            if (character == 'o') {
                count1++;
            }
            else if (character == 'x') {
                count2++;
            }
        }
    }

    if (count1 > count2) {
        if ((count1 - count2) > 1) {
            result = {false, 'o'};
            return result;
        }
        
        result = {true, 'o'};
    }
    else if (count2 > count1){
        if ((count2 - count1) > 1) {
            result = {false, 'x'};
            return result;
        }

        result = {true, 'x'};
    }
    else {
        result = {true, ' '};
    }
  
    
    return result;
}

void reassignArray(char **&matrix, int rows, int cols, char character){

    pair<bool, char> result;
    char change, value;


    if (character == 'o') {
        change = 'x';
    }
    else {
        change = 'o';
    }

    for (int i = 0; i < rows; i++) {
        for(int j = 0; j< cols; j++) {
            value = matrix[i][j];
            if (value == character) {
                matrix[i][j] = change;

                result = validateMatrix(matrix, rows, cols);
            }

            if (result.first) {break;}
        }

        if (result.first) {break;}
    }
}

// ! Don't forget of DELETE matrix 
char **createMatrix (int rows, int cols) {

    char ** array = new char* [rows];

    //Reservar espacio en memoria para las columnas
    for (int i = 0; i < rows; i ++) {
        array[i] = new char[cols];
    }

    int randomValue = 0;

    for (int i{}; i < rows; i++) {
        for (int j{}; j < cols; j++) {
            randomValue = generateRandomValues(1, 2);

            if (randomValue == 1) {
                array[i][j] = 'o';
                continue;
            }
            
            if (randomValue == 2){
                array[i][j] = 'x';
            }
        }
    }

    pair<bool, char> result = validateMatrix(array, rows, cols);

    if (!result.first) {
        reassignArray(array, rows, cols, result.second);
    }

    return array;
}

char **createMatrixDefault (int rows, int cols){
    char **array = new char *[rows];

    for (int i{}; i < rows; i++) {
        array[i] = new char[cols];
    }

    array[0][0] = 'o';
    array[0][1] = 'o';
    array[0][2] = 'x';

    array[1][0] = 'x';
    array[1][1] = 'o';
    array[1][2] = ' ';

    array[2][0] = 'x';
    array[2][1] = 'x';
    array[2][2] = 'o';

    return array;

}

void drawMatrix (char **matrix, int rows, int cols){
    const char VERTICAL_BAR = (char)186;
    const char HORIZONTAL_BAR = (char)205;
    int i = 0, j = 0; // Contadores para la Matrix

    //Sumamos para dar espacio de dibujo al tablero
    rows += 2;
    cols += 2;

    cout << "TRES EN RAYA GAME :)" << endl;

    cout << endl;
    for (int m = 0; m < rows; m++) {
        if (m % 2 == 0) {
            for (int n = 0; n < cols; n++) {
                if (n % 2 == 0) {
                    cout << matrix[i][j];
                    j++;

                    continue;
                }

                cout << VERTICAL_BAR;
            }

            i++; j = 0;
            cout << endl;
            continue;
        }

        for (int n = 0; n < cols; n++) {
            cout << HORIZONTAL_BAR;
        }

        cout << endl;
    }
    cout << endl;

}



// * Verificar horizontal, vertical y diagonal para saber quien gano.

char ** transposedMatrix (char** matrix, int rows, int cols){
    char** array = new char *[rows];

    for(int i{}; i < rows; i++) {
        array[i] = new char[cols];
    }


    for(int i{}; i < rows; i++) {
       for(int j{}; j < cols; j++) {
            array[i][j] = matrix[j][i];
        }  
    }  
    
    return array;
}

pair<bool, char> checkRows(char** matrix, int rows, int cols) {
    char character, value;
    pair<bool, char> result;
    bool flag = true;

    for (int i = 0; i < rows; i++) {
        flag = true;
        character = matrix[i][0];

        if (character != ' ') {
            
            for (int j = 0; j < cols; j++) {
                value = matrix[i][j];

                if (value != character) {
                    flag = false;
                    break;
                }
            }

            if (flag) {break;}
        }
    }

    result = {flag, character};

    return result;
} 

pair<bool, char> checkColumns(char** matrix, int rows, int cols){

    bool flag = 1;
    char** array = transposedMatrix(matrix, rows, cols);
    pair<bool, char> result = checkRows(array, rows, cols);

    if (!result.first) {
        flag = 0;
    }

    //Liberar memoria del nuevo array creado
    for(int i{}; i < rows; i++) {
        delete[] array[i];
    }

    delete[] array;


    return {flag, result.second};
}

bool checkDiagonal(char** matrix, int rows, int cols, pair<int, int> position){

    // La "position" indica de donde tomare el primer caracter partiendo de la fila 0, 
    // desde la columna de inicio(0) o desde la columna final (2)

    char character =  matrix[position.first][position.second];
    int i = position.first, j = position.second;

    bool flag = 1;
    bool isZero = 1;
    if (position.second > 0) { isZero = 0; }


    while(isZero && i != (rows - 1)) {
        
        i++; j++;

        if (matrix[i][j] != character) {
            flag = 0;
            break;
        }     
    }

    while (!isZero && j != 0){
        
        i++; j--;

        if (matrix[i][j] != character) {
            flag = 0;
            break;
        }

    }

    return flag;

}

char whoWillWin(char **matrix, int rows, int cols){
    char winner = '=';
    bool flag = false;
    pair<bool, char> result;
    pair<int, int> value;

    result = checkRows(matrix, rows, cols);
    if (result.first) {
        winner = result.second;
        flag = true;
    }
    if (flag) {return winner;}


    result = checkColumns(matrix, rows, cols);
    if (result.first) {
        winner = result.second;
        flag = 1; 
    }
    if (flag) {return winner;}


    value = {0, 0}; // start position with row 0
    if (checkDiagonal(matrix, rows, cols, value)) {
        winner = matrix[value.first][value.second];
        return winner;
    }
    value = {0, cols -1}; // end position with row 0

    if (checkDiagonal(matrix, rows, cols, value)) {
        winner = matrix[value.first][value.second];
        return winner;
    }


    return winner;
}

int main (){
    system("cls");
    srand(time(NULL));

    int rows = 3;
    int cols = 3;

    char **matrix = createMatrix(rows, cols);
    drawMatrix(matrix, rows, cols);
    std::cout << endl;
    
    char result = whoWillWin(matrix, rows, cols);
    std::cout << "The winner is: [" << result << "]" << endl << endl;
    
    // Free Memory
    for (int i{}; i < rows; i++) {
        delete[] matrix[i];
    }

    delete[] matrix;

    return 0;
}

