#include <iostream>
using namespace std;

long long N, K;

bool isValid(long long x) {
    long long count = 0;
    for (long long i = 1; i <= N; i++) {
        count += min(N, x / i);
    }
    return count >= K;
}

long long binarySearch() {
    long long left = 1, right = N * N;
    long long result = 0;

    while (left <= right) {
        long long mid = (left + right) / 2;

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
