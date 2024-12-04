#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring> // memset 사용

using namespace std;

int arr[21][21], copy_arr[21][21];
int n, ans = 0;
vector<int> v;

void Move(int num) {
    memset(copy_arr, 0, sizeof(copy_arr));

    for (int i = 0; i < n; i++) {
        vector<int> temp, merge;

        if (num == 1 || num == 2) { // 위 또는 아래
            for (int j = (num == 1) ? 0 : n - 1; (num == 1) ? (j < n) : (j >= 0); (num == 1) ? j++ : j--) {
                if (arr[j][i] != 0) temp.push_back(arr[j][i]);
            }
        }
        else { // 왼쪽 또는 오른쪽
            for (int j = (num == 4) ? 0 : n - 1; (num == 4) ? (j < n) : (j >= 0); (num == 4) ? j++ : j--) {
                if (arr[i][j] != 0) temp.push_back(arr[i][j]);
            }
        }

        for (size_t k = 0; k < temp.size(); k++) {
            if (k + 1 < temp.size() && temp[k] == temp[k + 1]) {
                merge.push_back(temp[k] * 2);
                k++;
            }
            else {
                merge.push_back(temp[k]);
            }
        }

        for (size_t k = 0; k < merge.size(); k++) {
            if (num == 1) copy_arr[k][i] = merge[k];
            else if (num == 2) copy_arr[n - k - 1][i] = merge[k];
            else if (num == 3) copy_arr[i][n - k - 1] = merge[k];
            else if (num == 4) copy_arr[i][k] = merge[k];
        }
    }
}

int Simul() {
    memcpy(arr, copy_arr, sizeof(copy_arr)); // 기존 배열 덮어쓰기
    int maxi = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            maxi = max(maxi, arr[i][j]);
    return maxi;
}

void Back(int now) {
    if (now == 5) { // 이동 제한
        ans = max(ans, Simul());
        return;
    }
    for (int i = 1; i <= 4; i++) { // 4 방향 시도
        v.push_back(i);
        memcpy(copy_arr, arr, sizeof(arr)); // 현재 상태 복사
        Move(i);
        Back(now + 1);
        v.pop_back();
        memcpy(arr, copy_arr, sizeof(copy_arr)); // 상태 복원
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    Back(0);
    cout << ans << "\n";
    return 0;
}