#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long


ll convertSecondsToMilliseconds(int seconds){
    const ll BASE = 1000;
    return (ll)seconds * BASE;
}

void sleepTime(int time){
    ll newTime = convertSecondsToMilliseconds(time);
    std::this_thread::sleep_for(chrono::milliseconds(newTime));
}


template<typename T>
T sum (T a, T b){ return a + b; }

template<typename T>
void printSum(T a, T b, int waitTime){
    T result = sum<T>(a, b); 

    sleepTime(waitTime);
    cout << "The sum of " << a << " + " << b << " is: " << result << endl;
}

void testThreads (){
    int time;

     //se crean dos hilos de ejecución
    time = 10;
    thread t1(printSum<int>, 9, 5, time); // Se ejecuta despues por el tiempo de espera 10 seg

    time = 5;
    thread t2(printSum<int>, 4, 2, time); // Se ejecuta primero por el tiempo de espera 5 seg

    //se ejecutan los hilos con las funciones join
    //JOIN: se utiliza para esperar a que un hilo termine antes de continuar con la ejecución del programa principal.
    t1.join();
    t2.join();
}


void listOfThreads (int quantityOperations){
    //#include <thread>
    vector<thread> threads;

    int a = 0, b = 0, waitTime = 0;

    for (int i{}; i < quantityOperations; i++) {
        system("cls");
        cout << "Enter the number a: "; cin >> a;
        cout << "Enter the number b: "; cin >> b;
        cout << "Enter the wait time: "; cin >> waitTime;

        threads.push_back(thread(printSum<int>, a, b, waitTime));
    }

    //Unir todos los hilos
    for (auto &thread_: threads) {
        thread_.join();
    }

}


int main (){
    system("cls");

    //testThreads();
    int quantityOperations = 0;
    cout << "What is the quantity operations: "; cin >> quantityOperations;
    listOfThreads(quantityOperations);

    cout << endl << endl;
    return 0;
}

