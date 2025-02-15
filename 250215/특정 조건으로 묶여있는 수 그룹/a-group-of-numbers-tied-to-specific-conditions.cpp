#include <iostream>
#include <algorithm>

#define MAX_N 50000

using namespace std;

// 변수 선언
int arr[MAX_N + 1];
int L[MAX_N + 1], R[MAX_N + 1];
int n, k;

int main() {
    cin >> n >> k;
    for(int i = 1; i <= n; i++)
        cin >> arr[i];

    sort(arr + 1, arr + n + 1);

    int max_num = 0;
    int i = 1;
    for(int j = 1; j <= n; j++) {
        while(i + 1 <= j && arr[j] - arr[i] > k)
            i++;
        
        max_num = max(max_num, j - i + 1);

        L[j] = max_num;
    }

    max_num = 0;
    int j = n;
    for(int i = n; i >= 1; i--) {
        while(j - 1 >= i && arr[j] - arr[i] > k)
            j--;
        
        max_num = max(max_num, j - i + 1);

        R[i] = max_num;
    }

    int ans = L[n];
    for(int i = 1; i < n; i++)
        ans = max(ans, L[i] + R[i + 1]);

    cout << ans;
    return 0;
}
