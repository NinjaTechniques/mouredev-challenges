#include <bits/stdc++.h> 
using namespace std;
#define endl '\n'

int generteRandomValues(int min, int max){
    random_device randomDevice;
    default_random_engine defaultRandomEngine(randomDevice());
    uniform_int_distribution<int> uniformIntDistribution(min, max);

    int randomValue = uniformIntDistribution(defaultRandomEngine);
    return randomValue;
}

//! Free Memory
int* createListOfRandomValues(int length, int min, int max){
    int* array = new int[length];
    int randomValue = 0;
    
    for (int i = 0; i < length; i++){
        randomValue = generteRandomValues(min, max);
        array[i] = randomValue;
    }

    return array;
}


//Advanced ordering

// MERGESORT
void merge(int* list, int* left, int* right, int length){
    int mid = (length + 1) / 2; 
    int lengthLeft = mid;
    int lengthRight = (length - mid);

    int i = 0, j = 0, k = 0;

    while (i < lengthLeft && j < lengthRight) {
        if (left[i] < right[j]) { list[k] = left[i]; i++; }
        else {list[k] = right[j]; j++; }
        k++;
    }

    while (i < lengthLeft){ list[k] = left[i]; i++; k++;}
    while (j < lengthRight){ list[k] = right[j]; j++; k++;}
}
void mergeSort(int *list, int length){
    if (length > 1){
        int mid = (length + 1) / 2;

        int *left = new int[mid];
        int *right = new int[length - mid];

        for (int i{}; i < mid; i++){ left[i] = list[i]; }
        for (int i = mid; i < length; i++){ right[i - mid] = list[i]; }

        mergeSort(left, mid);
        mergeSort(right, (length - mid));
        merge(list, left, right, length);

        delete[] left;
        delete[] right;
    }
}

// QuickSort

void swap (int* a, int* b){
    int aux = *a;
    *a = *b;
    *b = aux;
}

int partition(int* list, int left, int right){
    int pivot = list[right];
    int i = left, j = left;

    for (int k = left; k < right; k++){
        if (list[j] <= pivot && list[i] > pivot){
            swap(&list[i], &list[j]); i++; j++; continue;
        }

        if (list[j] <= pivot) {i++; j++;}
        else { j++; } //list[j] > pivot
    }

    swap(&list[i], &pivot);
    return i;
}

void quickSort (int* list, int left, int right){
    if (left < right){
        int pivot = partition(list, left, right);
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

void quickSort (int* list, int length){
    quickSort(list, 0, (length - 1));
}

// FisherYatesSuffle
void fisherYatesShuffle(int* list, int length){
    int pivot = (length - 1);
    int randomIndex = 0;

    for (int i = pivot; i > 0; i--){
        randomIndex = generteRandomValues(0, i);
        swap(&list[i], &list[randomIndex]);
    }
}

//Bubble Sort: Basic Ordering

void bubbleSort(int* list, int length){
    for (int i = 0; i < length; i++){
        for (int j = i + 1; j < length; j++){
            if (list[i] > list[j]){
                swap(&list[i], &list[j]);
            }
        }
    }
}


int secondLargeValue(int* list, int length){

    if (length > 500){
        fisherYatesShuffle(list, length);

        int ordering = generteRandomValues(1, 2);

        if ( ordering == 1) {
            mergeSort(list, length);
        }
        else{
            quickSort(list, length);
        }
    }
    else {
        bubbleSort(list, length);
    }

    int second = list[length - 1];
    for(int i = (length - 1); i >= 0; i--){
        if (second != list[i]) {
            second = list[i];
            break;
        }
    }

    return second;
}

void printContainer (int* list, int length){
    for (int i = 0; i < length; i++){
        if (i != length - 1) {
            cout << list[i] << ", "; 
            continue;
        }
        cout << list[i];
    }
}


int main (){
    system("cls");

    int length = 0, min = 0, max = 0;
    cout << "Enter the size of the list: "; cin >> length; 
    cout << "Enter minimum random value: "; cin >> min;
    cout << "Enter maximum random value: "; cin >> max; cout << endl; 
    
    int* array = createListOfRandomValues(length, min, max);
    cout << "Second Large Value: " << secondLargeValue(array, length) << endl << endl;
    printContainer(array, length);

    cout << endl << endl;
    delete[] array;
    return 0;
}