#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, t, f_x, f_y, s_x, s_y;
int arr[51][51];
int new_arr[51][51];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void Input() {
    cin >> n >> m >> t;

    bool flag = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];

            if (arr[i][j] == -1 && !flag) {
                f_x = i;
                f_y = j;
                flag = true;
            }
            else if (arr[i][j] == -1 && flag) {
                s_x = i;
                s_y = j;
            }
        }
    }
}

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Calc(int x, int y) {
    int cnt = 0, sum = 0;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (InRange(nx, ny) && arr[nx][ny] >= 0) {  // 🔥 `arr[nx][ny] > 0` → `>= 0`
            new_arr[nx][ny] += arr[x][y] / 5;
            sum += arr[x][y] / 5;
        }
    }

    new_arr[x][y] += arr[x][y] - sum;  // 🔥 `new_arr[x][y] =` → `+=`로 수정
}

void Spread() {
    memset(new_arr, 0, sizeof(new_arr));  // 🔥 배열 초기화

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > 0) {
                Calc(i, j);
            }
            else if (arr[i][j] == -1) {
                new_arr[i][j] = -1;
            }
        }
    }

    memcpy(arr, new_arr, sizeof(arr));  // 🔥 배열 복사 최적화
}

void Rotate_anti() {
    int temp = arr[0][0];

    for (int i = 0; i < m - 1; i++) arr[0][i] = arr[0][i + 1];
    for (int i = 0; i < f_x; i++) arr[i][m - 1] = arr[i + 1][m - 1];
    for (int i = m - 1; i > 0; i--) arr[f_x][i] = arr[f_x][i - 1];
    for (int i = f_x - 1; i > 0; i--) arr[i][0] = arr[i - 1][0];  // 🔥 `i > 1` → `i > 0`

    arr[1][0] = temp;
    arr[f_x][f_y] = -1;
    arr[f_x][f_y + 1] = 0;
}

void Rotate_non() {
    int temp = arr[n - 1][0];

    for (int i = 0; i < m - 1; i++) arr[n - 1][i] = arr[n - 1][i + 1];
    for (int i = n - 1; i > s_x; i--) arr[i][m - 1] = arr[i - 1][m - 1];  // 🔥 `>= s_x` → `> s_x`
    for (int i = m - 1; i > 0; i--) arr[s_x][i] = arr[s_x][i - 1];
    for (int i = s_x; i < n - 1; i++) arr[i][0] = arr[i + 1][0];

    arr[n - 2][0] = temp;
    arr[s_x][s_y] = -1;
    arr[s_x][s_y + 1] = 0;
}

int main() {
    Input();

    for (int i = 0; i < t; i++) {
        Spread();
        Rotate_anti();
        Rotate_non();
    }

    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] > 0) {
                ans += arr[i][j];
            }
        }
    }

    cout << ans;
}
