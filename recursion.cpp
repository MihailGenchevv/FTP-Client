#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>


using namespace std;

int countDigits(int a){
    if ( a == 0) {
        return 0;
    }
    return 1 + countDigits(a / 10);
}

void printArray(int arr[], int n ){
    for (int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

void reverseArray(int arr[], int n) {
    int j = n-1;
    for (int i = 0; i < n / 2; i++, j--){
        swap(arr[i], arr[j]);
    }

}
/* Find the right-most number in a given array, that is bigger than the mean of it's two neighbours.
   Do it recursively.
*/

int findRightMost(int arr[], int n, int pos) {
    if (pos == 0) {
        return -1;
    }
    double mean = double(arr[pos-1] + arr[pos+1]) / 2;
    if ((double)arr[pos] > mean) {
        return pos;
    } else {
        return findRightMost(arr, n, pos-1);
    }

}

int findRightMostIterative(const int arr[], int n) {
    for (int i = n-2; i > 0; i--) {
        double mean = double(arr[i-1] + arr[i+1]) / 2;
        if ( (double)arr[i] > mean ){
            return i;
        }
    }
    return -1;
}



void numToArray(int n ) {
    int arr[20];
    int idx = 0;
    while(n != 0) {
        arr[idx] = n % 10;
        n = n / 10;
        idx++;
    }

    reverseArray(arr, idx);
    printArray(arr, idx);
}



int main() {
    srand(time(nullptr));

    vector<int> v;
    const int N = 20;
    int arr[N];
    for (int i = 0; i < N; i++){
        int num = rand() % 100 + 0;
        v.push_back(num);
        arr[i] = num;
    }

    for (int num : v){
        cout << num << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    sort(v.begin(), v.end());
    sort(arr, arr + N);

    for (int num : v){
        cout << num << " ";
    }
    cout << endl;
    for (int i = 0; i < N; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    int M = 20;
    numToArray(M);


    int arrRightMost[7] = {1, 2, 3, 4, 5, 6, 6};

    cout << findRightMostIterative(arrRightMost, 7);
    cout << endl;
    cout << findRightMost(arrRightMost, 7, 5);


}