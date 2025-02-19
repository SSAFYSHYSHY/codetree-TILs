#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;

    if (n < 5 && n % 2 != 0) {
        cout << -1;
        return 0;
    }

    int a = n / 5;
    int b = n % 5;

    while (b % 2 != 0 && a > 0) {  // 2원으로 해결할 수 없으면 5원을 줄여본다
        a--;
        b += 5;
    }

    if (b % 2 == 0) {
        cout << a + (b / 2);
    } else {
        cout << -1;
    }

    return 0;
}
