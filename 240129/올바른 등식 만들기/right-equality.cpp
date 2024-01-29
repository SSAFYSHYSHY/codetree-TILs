#include <iostream>

#define MAX_N 100
#define OFFSET 20
#define MAX_M 40
#define MIN_M 0

using namespace std;

long long dp[MAX_N + 1][MAX_M + 1];

int n, m;

int a[MAX_N + 1];

void Initialize() {

    for(int i = 0; i <= n; i++)
        for(int j = MIN_M; j <= MAX_M; j++)
            dp[i][j] = 0;

    dp[0][0 + OFFSET] = 1;
}

int main() {
    cin >> n >> m;

    m += OFFSET;

    for(int i = 1; i <= n; i++)
        cin >> a[i];

    Initialize();

    for(int i = 1; i <= n; i++) {

        for(int j = MIN_M; j <= MAX_M; j++) {


            if(j + a[i] <= MAX_M)
                dp[i][j] += dp[i - 1][j + a[i]];

            if(j - a[i] >= MIN_M)
                dp[i][j] += dp[i - 1][j - a[i]];
        }
    }


    cout << dp[n][m];
}