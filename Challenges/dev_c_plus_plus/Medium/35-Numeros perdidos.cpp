#include <bits/stdc++.h>
using namespace std;
#define endl '\n'

int generateRandomValue(int min, int max){
    random_device randomDevice;
    default_random_engine defaultRandomEngine(randomDevice());
    uniform_int_distribution<int> uniformIntDistribution(min, max);

    int randomValue = uniformIntDistribution(defaultRandomEngine);
    return randomValue;
}


//!Free Memory
int* createArray (int length, int min, int max){
    set<int> st;
    int* array = new int[length];
    int randomValue = 0;
    int index = 0;

    while (st.size() < length){
        randomValue = generateRandomValue(min, max);
        st.insert(randomValue);
    }

    for (auto e: st){
        array[index] = e;
        index++;
    }

    return array;
}

bool isArrayWithoutRepeatElements(int* array, int length){
    set<int> st;

    for (int i{}; i < length; i++) {
        st.insert(array[i]);
    }

    if (st.size() == length) { return true;}
    return false;
}

bool isArraySorting(int* array, int length) {
    bool flag = 0;

    for (int i = 0; i < (length - 1); i++) {
        if (array[i] > array[i + 1]) {
            flag = 1;
            break;
        }
    }

    if (flag) {return false;}
    return true;
}

/*QUICKSORT*/

void swap (int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int* array, int left, int right){
    int pivot = array[right];
    int i = left, j = left;

    for (int k = left; k < right; k++){
        if (array[j] <= pivot && array[i] > pivot){
            swap(&array[i], &array[j]);
            i++; j++;
            continue;
        }

        if (array[j] <= pivot) { i++; j++; continue;}
        j++;
    }   

    swap(&array[i], &pivot);

    return i;
}

void quickSort(int* array, int left, int right){
    if (left < right){
        int pivot = partition(array, left, right);

        quickSort(array, left, pivot - 1);
        quickSort(array, pivot + 1, right);
    }
}

void quickSort(int* array, int length){
    quickSort(array, 0, (length - 1));
}

void fisherYatesShuffle(int* array, int length){
    int pivot = length - 1;
    int randomIndex = 0;

    for (int i = pivot; i > 0; i--){
        randomIndex = generateRandomValue(0, i);
        swap(array[i], array[randomIndex]);
    }
}

vector<int> findLostNumbers (int max, int min, int lost){
    vector<int> v;

    for (int i = 1; i <= lost; i++) {
        min++;
        if (min != max) {
            v.push_back(min);
            continue;
        }
        
        break;
    }

    return v;
}

vector<int> lostNumbers(int* array, int length){
    int min = 0;
    int max = 0;
    int lost = 0;  
    vector<int> v;

    auto elementsLost = [&v] (vector<int> findVector) -> void {
        for (auto e: findVector)  {
            v.push_back(e);
        }
    };

    for (int i = 0; i < (length - 1); i++) {
        min = array[i];
        max = array[i + 1];

        if ((max - min) - 1 != 0) {
            lost = max - min;
            elementsLost(findLostNumbers(max, min, lost));
        }
    }

    return v;
}

void printArray (int* array, int lenght){ 
    for (int i = {}; i < lenght; i++) {
        cout << array[i] << " ";
    }
}

void printVector (vector<int> v){
    cout << "[";
    for(auto e: v) {
        cout << e << ", ";
    }
    cout << "]";
}


int main (){
    system("cls");

    int lenght = 10;
    int* array = createArray(lenght, 1, 20);
    //int array[] = {1,5,4,2,7,10};

    if (isArrayWithoutRepeatElements(array, lenght) == false && isArraySorting(array, lenght) == false) {
        cout << "This array is not correct :( ";
    }
    else {
        vector<int> lostNumbersResult = lostNumbers(array, lenght);
        quickSort(array, lenght);
        cout << "Array: "; 
        printArray(array, lenght);
        cout << endl << endl;

        cout << "Lost Numbers: ";
        printVector(lostNumbersResult);

        lostNumbersResult.clear();
    }

    delete[] array;
    cout << endl << endl;
    return 0;
}