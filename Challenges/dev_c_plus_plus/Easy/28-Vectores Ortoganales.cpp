#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int generateRandomValue(int min, int max){
    static random_device rd;
    static default_random_engine eng(rd());
    static uniform_int_distribution<int> dis(min, max);

    int randomValue = dis(eng);
    return randomValue;
}


vector<int> createVector(int size, int min, int max){
    vector<int> v(size);
    int value = 0;

    for (int i = 0; i < size; i++) {
        value = generateRandomValue(min, max);
        v[i] = value;
    }

    return v;
}

pair<vector<int>, vector<int>> createVectorDefault(){
    vector<int> u;
    vector<int> v;

    u.push_back(1);
    u.push_back(2);

    v.push_back(-2);
    v.push_back(1);

    return {u, v};
}

void printVector(vector<int> v){
    cout << "[";
    for (int i = 0; i < v.size(); i++) {
        if (i != v.size() - 1) {
            cout << v[i] << ";"; continue;
        }
        cout << v[i];
    }
    cout << "]";
}

bool validateSizeVector(vector<int> u, vector<int> v){
    if (u.size() != v.size()) { return false; }
    return true;
}

bool isOrthogonalVector(vector<int> u, vector<int> v) {
    bool isOrthogonal = false;
    int result = 0;

    for (int i = 0; i < u.size(); i++) {
        result += (u[i] * v[i]);
    }

    if (result == 0) {
        isOrthogonal = true;
        return isOrthogonal;
    }

    return isOrthogonal;
}

int main (){
    system("cls");
    srand(time(NULL));
    //pair<vector<int>, vector<int>> result = createVectorDefault();
   
    vector<int> u = createVector(2, -5, 5);
    vector<int> v = createVector(3, -5, 5);

    printVector(u); cout << "  "; printVector(v);

    if (!validateSizeVector(u, v)) {
        cout << endl << "UpS :( The vectors have different sizes" << endl;
    }
    else {
        cout << endl << "Is it a orthogonal vector? : " << isOrthogonalVector(u, v) << endl;
    }

    cout << endl;
    return 0;
}