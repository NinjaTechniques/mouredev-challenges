#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

/*
 * Crea un programa que comprueba si los paréntesis, llaves y corchetes
 * de una expresión están equilibrados.
 * - Equilibrado significa que estos delimitadores se abren y cieran
 *   en orden y de forma correcta.
 * - Paréntesis, llaves y corchetes son igual de prioritarios.
 *   No hay uno más importante que otro.
 * - Expresión balanceada: { [ a * ( c + d ) ] - 5 } -> {[()]}
 * - Expresión no balanceada: { a * ( c + d ) ] - 5 } -> {[]}{
 */

//SOLUTION 1

bool validateCharacters(char value){
    if (!(value == '{' || value == '[' || value == '(')) {
        if (!(value == '}' || value == ']' || value == ')')){
            return false;
        }

        return true;
    }

    return true;
}

bool isBalancedExpression(string expression){
    stack<char> s;
    bool flag = true;

    for (int i = 0; i < expression.length(); i++) {

       if (validateCharacters(expression[i])) {

            if (expression[i] == '}' || expression[i] == ']' || expression[i] == ')') {
                if (i == 0) {flag = false; break;}
                if (s.empty()) {flag = false; break;}
                
                if ((s.top() == '{' && expression[i] == '}') || (s.top() == '[' && expression[i] == ']') || (s.top() == '(' && expression[i] == ')') ) {
                    s.pop();
                }
                else {
                    flag = false; 
                    break;
                }

            }
            else {
                s.push(expression[i]);
            }
       }

    }

    if (flag) {
        if (s.empty()) {flag = true;}
        else {flag = false;}
    }

    return flag;
}


//SOLUTION 2

bool isBalancedExpression_(string expression){
    map<char, int> mp;
    bool flag = true;

    for (char e: expression) {
       if (validateCharacters(e)) {
            if (e == '{' || e == '[' || e == '(') {
                mp[e]++;
            }
            else {
                if (e == ')') {
                    if (mp[e - 1] == 0) {
                        flag = false; 
                        break;
                    }   

                    mp[e - 1]--;  
                }
                else if (e == '}' || e == ']') {
                    if (mp[e - 2] == 0) {
                        flag = false; 
                        break;
                    }

                    mp[e - 2]--;
                }
            }
       }
    }
    
    for (pair<char, int> it: mp) {
        if (it.second != 0) {
            flag = false;
            break;
        }
    }

    return flag;

}


int main (){
    system("cls");

    string expression = "";
    cout << "Enter the expression: "; getline(cin, expression);
    cout << endl;

    cout << "Is it a balanced expression? : " << isBalancedExpression_(expression) << endl;

    cout << endl;
    return 0;
}