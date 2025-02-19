#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<string> brackets(N);
    for (int i = 0; i < N; i++) {
        cin >> brackets[i];
    }

    int open = 0, close = 0;
    
    int score = 0;

    for (const string& s : brackets) {
        int balance = 0;
        for (char c : s) {
            if (c == '(') {
                balance++;
            } else if (c == ')') {
                if (balance > 0) { 
                    balance--;
                    score++;
                }
            }
        }
        if (balance > 0) {
            open += balance;
        } else if (balance < 0) {
            close -= balance;
        }
    }

    score += min(open, close);

    cout << score << endl;

    return 0;
}
