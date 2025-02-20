#include <iostream>

using namespace std;

int n;
int grid[101][101];

int main() {
    cin >> n;
    
    // 입력 받기
    for (int i = 0; i < n; i++) {
        string row;
        cin >> row;
        for (int j = 0; j < n; j++) {
            grid[i][j] = row[j] - '0'; // 문자 '0' 또는 '1'을 정수로 변환
        }
    }

    int cnt = 0;

    // 오른쪽 아래에서 왼쪽 위로 스캔하며 1이 있는 곳을 반전
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 1) { // 현재 위치가 1이면
                cnt++; // 클릭 횟수 증가

                // (0,0) ~ (i,j)까지 모두 반전
                for (int x = 0; x <= i; x++) {
                    for (int y = 0; y <= j; y++) {
                        grid[x][y] ^= 1; // XOR 연산으로 0 <-> 1 변환
                    }
                }
            }
        }
    }

    cout << cnt << endl;
    return 0;
}
