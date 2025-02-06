#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, ans = 21e8;
int arr[51][51];
bool visited[51] = { false, };

vector<pair<int, int>> v, v1 , cus;

void Input() {
    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == 2) {
                v.push_back({ i, j });
            }
            else if(arr[i][j] == 1) {
                cus.push_back({ i, j });
            }
        }
    }
}

int Calc() {
    int total_sum = 0;
    for (int i = 0; i < cus.size(); i++) {
        int x = cus[i].first;
        int y = cus[i].second;
        int sum = 0, num = 21e8;

        for (int j = 0; j < v1.size(); j++) {
            int cx = v1[j].first;
            int cy = v1[j].second;

            sum = abs(cx - x) + abs(cy - y);

            num = min(num, sum);
        }

        total_sum += num;
    }

    return total_sum;
}

void Back(int index, int count) {
    if (count == m) {
        ans = min(ans, Calc());
        return;
    }

    for (int i = index; i < v.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            v1.push_back(v[i]);
            Back(i + 1, count + 1);
            v1.pop_back();
            visited[i] = false;
        }
    }
}

int main() {
    Input();
    Back(0, 0);
    cout << ans;

    return 0;
}