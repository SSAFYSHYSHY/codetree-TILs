#include <iostream>
using namespace std;

int main() {
    string a, b;
    cin >> a >> b;

    int n = a.length(), m = b.length();
    bool is_pos[25][25] = {false}; 

    a = " " + a;
    b = " " + b;

    is_pos[0][0] = true; 

    for(int j = 0; j < m; j++) {
        for(int i = 0; i < n; i++) {
            if(!is_pos[i][j]) continue;

            if(j != m - 1 && b[j + 2] == '*') {
                is_pos[i][j + 2] = true;

                for(int curi = i + 1; curi <= n; curi++) {
                    if(b[j + 1] != '.' && a[curi] != b[j + 1]) break;
                    is_pos[curi][j + 2] = true;
                }
            }
            else if(b[j + 1] == '.') {
                is_pos[i + 1][j + 1] = true;
            }
            else {
                if(a[i + 1] == b[j + 1]) is_pos[i + 1][j + 1] = true;
            }
        }
    }

    if(!is_pos[n][m]) cout << "true";
    else cout << "false";

    return 0;
}