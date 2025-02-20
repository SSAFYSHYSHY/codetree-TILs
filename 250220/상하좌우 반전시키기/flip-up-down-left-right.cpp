#include <iostream>

using namespace std;

int n;
int arr[101][101];

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    // 오른쪽 아래에서 왼쪽 위로 올라오면서 체크
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (arr[i][j] == 0) { // 현재 위치가 0이면
                ans++; // 반전 횟수 증가
                // (0,0) ~ (i,j)까지 모든 값 반전
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        arr[x][y] ^= 1; // XOR 연산을 통해 0 <-> 1 반전
                    }
                }
            }
        }
    }

    cout << ans;
}
