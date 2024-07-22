#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)
#define fori(i, n) for(int i = 0; i < n; i++)

void countFromOneToOneHundred1(int min, int max){
    //Brute Force
    for (int i = min; i <= max; i++){
        cout << i << " ";
    }
}

void countFromOneToOneHundred2 (int min, int max){
    while (max != 0){
        cout << min << " ";

        min++;
        max--;
    }
}

void countFromOneToOneHundred3(int min, int max) {
    cout << min << " ";

    if (min == max) {
        return;
    }

    min++;

    return countFromOneToOneHundred3(min, max);
}


void countFromOneToOneHundred4(int min, int max) {
    do {
        cout << min << " ";
        min++;
        max--;

    }while (max != 0);
}

vector<int> createArrayFromOneToOneHundred(int min, int max){
    vector<int> container;
    
    for (int i = min; i <= max; i++){
        container.push_back(i);
    }

    return container;
}

void countFromOneToOneHundred5(vector<int> container) {
    for(int e: container){
        cout << e << " ";
    }
}


int generateValueInteger (int min, int max){
    return min + rand() % (max + 1);
}

void countFromOneToOneHundred6(int min, int max){ // Por probabilidad en algun momento tiene que hacerlo.
    int aux1 = 0, aux2 = 0;
    bool flag = false;

    while (!flag){
        system("cls");
        flag = true;

        for (int i = min; i <= max; i++) {
            if (i == min) {
                aux1 = generateValueInteger(min, max); 
                cout << aux1 << " ";
                continue;
            }
            

            aux2 = generateValueInteger(min, max);
            if (aux1 >= aux2) {flag = false; break;}

            cout << aux2 << " ";
            aux1 = aux2;
        }

        if (flag) {break;}
    }

}

int main (){
    system("cls"); fastio;
    srand(time(NULL));

    //vector<int> container = createArrayFromOneToOneHundred(1, 100);
    //countFromOneToOneHundred5(container);

    countFromOneToOneHundred6(1, 100);

    cout << endl;
    return 0;
}
