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



    sort()
}