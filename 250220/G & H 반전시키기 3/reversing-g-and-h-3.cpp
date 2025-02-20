#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    cin >> n;
    string s1, s2;
    cin >> s1 >> s2;

    int ans = 0;
    int diff_start = -1;

    for (int i = 0; i < n; i++) {
        // 다를 경우
        if (s1[i] != s2[i]) {
            if (diff_start == -1) {
                diff_start = i;
            }
        }
        // 같을 경우
        else {
            if (diff_start != -1) {
                int length = i - diff_start;
                ans += length / 4;
                if (length % 4 != 0) {
                    ans += 1; 
                }
                diff_start = -1; 
            }
        }
    }

    if (diff_start != -1) {
        int length = n - diff_start;
        ans += length / 4;
        if (length % 4 != 0) {
            ans += 1;
        }
    }

    cout << ans << endl;
    return 0;
}
