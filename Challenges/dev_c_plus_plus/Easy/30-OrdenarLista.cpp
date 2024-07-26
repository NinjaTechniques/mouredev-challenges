#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define fastio ios::sync_with_stdio(false);cin.tie(0)
#define fori(i, n) for(int i = 0; i < n; i++)

int generateRandomValues(int min, int max){
    random_device randomDevice;
    default_random_engine defaultRandomEngine(randomDevice());
    uniform_int_distribution<int> uniformIntDistribution(min, max);

    int randomValue = uniformIntDistribution(defaultRandomEngine);

    
    return randomValue;
}

// ! Free Memory
int* createList (int length, int min, int max) {
    int *list = new int[length];
    int randomValue = 0;

    for (int i{}; i  < length; i++) {
        randomValue = generateRandomValues(min, max);
        list[i] = randomValue;
    }

    return list;
}

enum typeOrdering {
    ASCENDING,
    DESCENDING
};

void swap(int* a, int* b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

void fisherYatesShuffle(int* &list, int length) {
    int randomIndex = 0;

    for (int i = (length - 1); i > 0; i--) {
        randomIndex = generateRandomValues(0, i);
        swap(&list[i], &list[randomIndex]);
    }
}

/*QUICKSORT: Advanced Ordering*/

int partition(int* list, int left, int right) {
    int i = left, j = left;
    int pivot = list[right];

    for(int k = left; k < right; k++){
        if (list[j] <= pivot && list[i] > pivot) {
            swap(&list[i], &list[j]);
            i++; j++;
            continue;
        }

        if (list[j] > pivot) { j++; continue;}
        if (list[j] <= pivot) { i++; j++; continue; }
    }

    if (list[i] > pivot) {
        swap(&list[i], &list[right]);
        return i;
    }
    
    return j; // Last position
}

void quickSort(int* list, int left, int right) {
    if (left < right) {
        int pivot = partition(list, left, right);
        quickSort(list, left, pivot - 1);
        quickSort(list, pivot + 1, right);
    }
}

void quickSort(int* list, int length) {
    quickSort(list, 0, length - 1);
}


/*MERGESORT: Advanced Ordering*/

void merge(int* list, int *left, int *right, int length){
    int mid = (length + 1) / 2;
    int lengthLeft = mid;
    int lengthRight = (length - mid);

    int i = 0, j = 0, k = 0;

    while (i < lengthLeft && j < lengthRight){
        if (left[i] < right[j]){
            list[k] = left[i];
            i++; 
        }
        else {
            list[k] = right[j];
            j++; 
        }

        k++;
    }

    while (i < lengthLeft) { list[k] = left[i]; i++; k++; }
    while (j < lengthRight) { list[k] = right[j]; j++; k++; }
}

void mergeSort (int* list, int length){
    if (length > 1) {
        int mid = (length + 1) / 2;

        int * left = new int[mid]; 
        int * right = new int[length - mid];

        for (int i = 0; i < mid; i++) { left[i] = list[i]; }
        for (int i = mid; i < length; i++) { right[i - mid] = list[i]; }

        mergeSort(left, mid);
        mergeSort(right, (length - mid));
        merge(list, left, right, length);

        delete[] left;
        delete[] right;
    }
}



void reverseList(int* &list, int length){
    int i = 0;
    int j = length - 1;

    for (int k = 1; k <= (length / 2); k++) {
        swap(&list[i], &list[j]);
        i++; j--;
    }
}

// ! Free Memory
int* listSorting(int* list, int length, typeOrdering type) {
 

    //quickSort(list, length);
    mergeSort(list, length);

    if (type == ASCENDING) {
        return list;
    }

    if (type == DESCENDING) {
        reverseList(list, length);
    }

    return list;
}

void printList (int* list, int length){
    fori (i, length) {
        cout << list[i] << " ";
    }
    cout << endl;
}


int main (){
    system("cls"); 

    int length = 0;
    cout << "Enter length of the list: "; cin >> length;
    cout << endl;
    int* list = createList(length, 1, 500);


    cout << "List: " << endl;
    printList(list, length);
    
    cout << "\nOrdered List: " << endl;
    fisherYatesShuffle(list, length); // Optimization
    list = listSorting(list, length, ASCENDING);
    printList(list, length);
    

    cout << endl;
    delete[] list;
    return 0;
}

