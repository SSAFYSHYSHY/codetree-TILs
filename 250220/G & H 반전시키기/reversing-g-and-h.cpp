#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string s, target;
    
    cin >> n >> s >> target;

    int count = 0;
    
    for (int i = 0; i < n; i++) {
        if (s[i] != target[i]) {
            count++;
            // 연속된 동일한 불일치 구간을 한 번에 처리
            while (i + 1 < n && s[i + 1] != target[i + 1]) {
                i++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
