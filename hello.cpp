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


int main() {

    mostOccurringElement();
}