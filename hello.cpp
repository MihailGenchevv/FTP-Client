#include <iostream>


using namespace  std;


const int MAX_SIZE = 10000;

int mostOccurringElement() {
    int n;
    cin >> n;

    int arr[MAX_SIZE];


    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    const int OFFSET = 1000;

    int hist[3000] = {};
    int biggest = arr[0] + OFFSET;
    for (int i = 0; i < n; ++i) {
        hist[arr[i] + OFFSET]++;
        if (biggest < arr[i] + OFFSET) {
            biggest = arr[i] + OFFSET;
        }
    }

    for (int i = 0; i <= biggest; ++i) {
        if (hist[i] != 0  ){
            cout << i - OFFSET << ":" << hist[i] << endl;
        }

    }

    return 1;
}



int reverseArray() {
    int n;
    cin >> n;

    int arr[MAX_SIZE];


    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }


    for (int i = 0; i < n / 2; ++i) {
        swap(arr[i], arr[n-i-1]);
    }

    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    return 1;
}


int mergeSortedArrays(){
    int n1, n2;
    cin >> n1;
    int arr1[MAX_SIZE], arr2[MAX_SIZE], result[MAX_SIZE];
    for (int i = 0; i < n1; ++i) {
        cin >> arr1[i];
    }
    cin >> n2;
    for (int i = 0; i < n2; ++i) {
        cin >> arr2[i];
    }

    int i = 0;
    int j = 0;
    int k = 0;

    while (i < n1 and j < n2){
        if (arr1[i] < arr2[j]){
            result[k] = arr1[i];
            i++;
        } else {
            result[k] = arr2[j];
            j++;
        }
        k++;

    }

    while( i < n1) {
        result[k++] = arr1[i++];
    }

    while (j < n2) {
        result[k++] = arr2[j++];
    }

    for (int i = 0; i < n1 + n2; i++) {
        cout << result[i] << " ";
    }
    return 1;
}


int numberToBinary() {
    int k;

    cin >> k;

    int arr[MAX_SIZE];

    int s = 0;
    while (k != 0) {
        arr[s] = k % 2;
        k = k / 2;
        s++;
    }


    for (int i = 0; i < s/2; ++i) {
        swap(arr[i], arr[s-i-1]);
    }

    for (int i = 0; i < s; i++ ){
        cout << arr[i] << " ";
    }

    return 1;
}


void generateAllSubsequenceOfArray(){

    int n;

    int arr[MAX_SIZE];

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    for (int k = 1;  k  <= n; k++ ){
        for (int j = 0; j + k <= n; j++){
            for (int i = j; i < j + k; i++){
                cout << arr[i] << " ";
            }
            cout << endl;
        }

    }
}

void swapInts(int& a, int& b) {
    int c = a;
    a = b;
    b = c;
}


void selectionSort(int arr[], const int n) {

    for (int i =0; i < n; i++){
        int minEl = arr[i],
            minElIdx = i;
        for (int j = i + 1; j < n; j ++){
            if (minEl > arr[j]){
                minEl = arr[j];
                minElIdx = j;
            }
        }
        swapInts(arr[i], arr[minElIdx]);
    }
}

void bubbleSort(int arr[] , int n) {
    for (int i = 0 ; i < n; i++ ){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+ 1]){
                swapInts(arr[j], arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int n ){

    for (int i = 0; i < n; i++ ){
        int j = i;
        while( j > 0 and arr[j] <= arr[j - 1]) {
            swapInts(arr[j], arr[j-1]);
            j--;
        }
    }
}

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}
int main() {
    int a = 5,
        b = 10;

    swapInts(a, b );
    cout << "a: " << a << " b: " << b << endl;

    const int N = 10;

    int arr[N] = {1,2,-1,7,11,20,9,14,-4,13};

    bubbleSort(arr, N);
    printArray(arr, N);






}