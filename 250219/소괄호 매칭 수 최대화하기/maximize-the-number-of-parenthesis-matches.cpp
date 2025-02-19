#include <iostream>
#include <string>
#include <tuple>
#include <algorithm>

#define MAX_N 100000
#define MAX_S 500000

using namespace std;

int n;
char s_arr[MAX_S];
pair<int, int> brackets[MAX_N];

long long ans;

bool cmp(pair<int, int> b1, pair<int, int> b2) {
    int open1, closed1;
    tie(open1, closed1) = b1;
    int open2, closed2;
    tie(open2, closed2) = b2;
    return (long long)open1 * closed2 > (long long)open2 * closed1;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> s_arr;
        string s = s_arr;
        int open = 0, closed = 0; 
        for (int j = 0; j < (int)s.size(); j++) {
            if (s[j] == '(')
                open++;
            else {
                closed++;

                ans += open;
            }
        }
        brackets[i] = make_pair(open, closed);
    }

    sort(brackets, brackets + n, cmp);

    int open_sum = 0;
    for (int i = 0; i < n; i++) {
        int open, closed;
        tie(open, closed) = brackets[i];
        ans += (long long)open_sum * closed;

        open_sum += open;
    }

    cout << ans;
    return 0;
}
