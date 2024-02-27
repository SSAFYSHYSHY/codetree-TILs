#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int n, m, offset[3], cnt;
string a[1005], b[1005];

void backtracking(int curr, int last) {
    if (curr == 3) {

        unordered_set<string> all;

        unordered_set<string> arr;
        for (int j = 0; j < n; j++) {
            string temp = "";
            for (int i = 0; i < 3; i++) {
                temp += a[j][offset[i]];
            }
            arr.insert(temp);
            all.insert(temp);
        }


        unordered_set<string> arr2;
        for (int j = 0; j < n; j++) {
            string temp = "";
            for (int i = 0; i < 3; i++) {
                temp += b[j][offset[i]];
            }
            arr2.insert(temp);
            all.insert(temp);
        }

        if (arr.size() + arr2.size() == all.size()) 
            cnt++;

        return;
    }

    for (int i = last + 1; i < m; i++) {
        offset[curr] = i;
        backtracking(curr + 1, i);
    }

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++) 
        cin >> a[i];
    for (int i = 0; i < n; i++) 
        cin >> b[i];

    backtracking(0, -1);

    cout << cnt;

    return 0;
}