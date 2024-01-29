#include <iostream>
#include <string>
#include <algorithm>

#define MAX_LEN 1000

using namespace std;

int dp[MAX_LEN + 1][MAX_LEN + 1];
string str1, str2;
int str1_len, str2_len;

void Initialize() {
    dp[1][1] = (str1[1] == str2[1]);
    for(int i = 2; i <= str1_len; i++){
        if(str1[i] == str2[1])
            dp[i][1] = 1;
        else
            dp[i][1] = dp[i-1][1];
    }
    
    for(int j = 2; j <= str2_len; j++){
        if(str1[1] == str2[j])
            dp[1][j] = 1;
        else
            dp[1][j] = dp[1][j-1];
    }
}

int main() {
    cin >> str1 >> str2;

    str1_len = (int) str1.size();
    str2_len = (int) str2.size();

    str1 = "#" + str1;
    str2 = "#" + str2;

    Initialize();

    for(int i = 2; i <= str1_len; i++){
        for(int j = 2; j <= str2_len; j++){
            if(str1[i] == str2[j])
                dp[i][j] = dp[i-1][j-1] + 1;

            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    cout << dp[str1_len][str2_len];

    return 0;
}