#include <iostream>
#include <string>
#include <algorithm>

#define MAX_LEN 1000

using namespace std;

int dp[MAX_LEN + 1][MAX_LEN + 1];
string str1, str2;
int str1_len, str2_len;

void Initialize() {
    dp[0][0] = 0;

    for(int i = 1; i <= str1_len; i++)
        dp[i][0] = i;

    for(int j = 1; j <= str2_len; j++)
        dp[0][j] = j;
}

int main() {
    cin >> str1 >> str2;

    str1_len = (int) str1.size();
    str2_len = (int) str2.size();

    str1 = "#" + str1;
    str2 = "#" + str2;

    Initialize();

    for(int i = 1; i <= str1_len; i++){
        for(int j = 1; j <= str2_len; j++){
            if(str1[i] == str2[j])
                dp[i][j] = dp[i-1][j-1];

            else
                dp[i][j] = min(min(dp[i-1][j-1], dp[i-1][j]), dp[i][j-1]) + 1;
        }
    }

    cout << dp[str1_len][str2_len];

    return 0;
}