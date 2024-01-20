#include <iostream>
#include <algorithm>
#include <climits>

#define MAX_NUM 50

using namespace std;

// 변수 선언
int n, m;
int arr[MAX_NUM][MAX_NUM];

int dp[MAX_NUM][MAX_NUM];

void Initialize() {

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            dp[i][j] = INT_MIN;
    

    dp[0][0] = 1;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> arr[i][j];

    Initialize();

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) {

            for(int k = 0; k < i; k++)
                for(int l = 0; l < j; l++) {

                    if(dp[k][l] == INT_MIN)
                        continue;


                    if(arr[k][l] < arr[i][j])
                        dp[i][j] = max(dp[i][j], dp[k][l] + 1);
                }
        }

    int ans = INT_MIN;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ans = max(ans, dp[i][j]);
    
    cout << ans;
    return 0;
}