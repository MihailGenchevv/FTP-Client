#include <iostream>
#include <time.h>
#include <stdlib.h>



using namespace std;

const int N = 3;

const char EMPTY = '-';
const char  X = 'X';
const char O = 'O';

char board [N][N];

void printBoard() {
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            cout << board[i][j] << " ";
        }
        cout << endl;
    }

}
void initBoard(){
    for (int i = 0; i < N; i++){
        for (int j = 0; j < N; j++){
            board[i][j] = EMPTY;
        }
    }
}


void inputUserCoordinates(){
    int x, y;
    do {
        cout << "Input valid coordinates: " << endl;
        cin >> x >> y;
    } while ((x >= N or x < 0) or (y >=N or y < 0) or board[x][y] != EMPTY);

    board[x][y]= X;

    printBoard();
}


void generateCoordinates() {
    int x, y;

    do{
        x = rand() % N;
        y = rand() % N;
    } while (board[x][y] != EMPTY);
    cout << "computer chose: " << x << " " << y << endl;
    board[x][y] = O;

    printBoard();
}

char wonOnRowsCols() {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++ ){
            if (board[i][j] != EMPTY) {
                int cnt = 0;
                for (int k = 0; k < N; k++){
                    if (board[i][k] == board[i][j]){
                        cnt++;

                    }
                }
                if (cnt == 3){
                    cout << "row: "<< i<< endl;
                    return board[i][j];
                }

                cnt = 0;
                for (int k = 0; k < N; k++){
                    if (board[k][j] == board[i][j]){
                        cnt++;

                    }
                }
                if (cnt == 3){
                    cout << "col: "<< i<< endl;
                    return board[i][j];
                }
            }
        }
    }
    return 'T';
}
int main(){

    srand(time(nullptr));

    initBoard();
    printBoard();
    while (true){
        inputUserCoordinates();
        generateCoordinates();
    }

}