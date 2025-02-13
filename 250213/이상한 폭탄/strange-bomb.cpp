#include <iostream>
#include <algorithm>
using namespace std;

int n, K, a[200005], R[200005], last[1000005];

int main() {
    cin >> n >> K;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for (int i = 0; i <= 1000000; i++) {
        last[i] = -1;
    }

    for (int i = n; i >= 1; i--){ 
        R[i] = last[a[i]];
        last[a[i]] = i;
    }

    int ans = -1;
    for (int i = 1; i <= n; i++){
        if (R[i] != -1 && R[i] - i <= K) {
            ans = max(ans, a[i]);
        }
    }

    cout << ans;
    return 0;
}
