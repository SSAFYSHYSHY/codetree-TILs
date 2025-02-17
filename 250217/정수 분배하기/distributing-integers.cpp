#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> arr;

bool isValid(int K) {
    int count = 0;
    for (int num : arr) {
        count += num / K; // 해당 정수에서 몇 개를 만들 수 있는지
    }
    return count >= M;
}

int binarySearch() {
    int left = 1, right = *max_element(arr.begin(), arr.end());
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (isValid(mid)) { // M개 이상 만들 수 있음 → K 키우기
            result = mid;
            left = mid + 1;
        }
        else { // M개를 만들 수 없음 → K 줄이기
            right = mid - 1;
        }
    }

    return result;
}

int main() {
    cin >> N >> M;
    arr.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    cout << binarySearch() << endl;
}
