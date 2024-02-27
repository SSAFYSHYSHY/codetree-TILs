#include <iostream>
#include <unordered_set>
using namespace std;

#define MAX_N 500

int n, m;
int ans;
string A[MAX_N], B[MAX_N];
unordered_set<string> s;

bool TestLocation(int x, int y, int z) {
    s.clear();

    for(int i = 0; i < n; i++) {
        s.insert(A[i].substr(x, 1) + A[i].substr(y, 1) + A[i].substr(z, 1));
    }

    for(int i = 0; i < n; i++) {
        if(s.find(B[i].substr(x, 1) + B[i].substr(y, 1) + B[i].substr(z, 1)) != s.end())
            return false;
    }

    return true;
}

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        cin >> A[i];
    
    for(int i = 0; i < n; i++)
        cin >> B[i];

    for (int i = 0; i < m; i++)
        for (int j = i + 1; j < m; j++)
            for (int k = j + 1; k < m; k++)
                if (TestLocation(i, j, k)) ans++;
    
    cout << ans;
    return 0;
}