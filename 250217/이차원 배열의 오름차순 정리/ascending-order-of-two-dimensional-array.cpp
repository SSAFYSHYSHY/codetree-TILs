#include <iostream>
using namespace std;

int N, K;

bool isValid(int x) {
    int count = 0;
    for (int i = 1; i <= N; i++) {
        count += min(N, x / i);
    }
    return count >= K;
}

int binarySearch() {
    int left = 1, right = N * N;
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isValid(mid)) { // mid 값이 K번째 숫자 이상일 경우
            result = mid;   // 가능한 답이므로 저장
            right = mid - 1;
        }
        else {
            left = mid + 1;
        }
    }
    return result;
}

int main() {
    cin >> N >> K;
    cout << binarySearch() << endl;
}
