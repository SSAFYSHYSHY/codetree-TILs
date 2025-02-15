#include <iostream>

#define MAX_NUM 100000

using namespace std;

// 변수 선언
int n, m;
int A[MAX_NUM + 1], B[MAX_NUM + 1];
int L[MAX_NUM + 2], R[MAX_NUM + 2];

int main() {
    // 입력:
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> A[i];
    for(int j = 1; j <= m; j++)
        cin >> B[j];
     
    for(int i = 1, j = 1; j <= m; j++) {
        while(i <= n && A[i] != B[j]) i++;
        L[j] = i;
        if(i <= n) i++;
    }

    for(int i = n, j = m; j >= 1; j--) {
        while(i >= 1 && A[i] != B[j]) i--;
        R[j] = i;
        if(i >= 1) i--;
    }

    L[0] = 0;
    R[m + 1] = n + 1;
    
    int ans = 0;
    for(int j = 1; j <= m; j++)
        if(L[j - 1] < R[j + 1]) ans++;
    
    cout << ans;
    return 0;
}
