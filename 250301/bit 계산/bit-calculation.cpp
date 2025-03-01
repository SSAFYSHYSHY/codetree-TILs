#include <iostream>
#include <string>

using namespace std;

int main() {
    int q;
    cin >> q;
    int a = 0;

    for (int i = 0; i < q; i++) {
        string s;
        int num;

        cin >> s;
        if (s == "clear") {
            a = 0;
        } else {
            cin >> num;
            if (s == "add") {
                a |= (1 << num);
            } else if (s == "delete") {
                a &= ~(1 << num);
            } else if (s == "toggle") {
                a ^= (1 << num);
            } else if (s == "print") {
                cout << ((a >> num) & 1) << "\n";
            }
        }
    }

    return 0;
}
