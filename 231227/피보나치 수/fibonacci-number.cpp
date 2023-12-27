#include <iostream>

using namespace std;

int n;
int arr[46];

void Initial(){
    for(int i = 0 ; i<= 46 ; i++) {
        arr[i] = -1;
    }
}

int Calc(int n) {
    if(arr[n] != -1) {
        return arr[n];
    }

    if(n == 1 || n == 2) {
        return arr[n ] =1;
    }

    return arr[n] = Calc(n-1) + Calc(n-2);
}

int main(){
    cin >> n;

    Initial();

    cout << Calc(n);
}