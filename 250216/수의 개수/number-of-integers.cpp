#include <iostream>
#include <algorithm>

using namespace std;

int n, m, mid;
int arr[100001];  // 입력 배열

// 입력을 받는 함수
void Input() {
    cin >> n >> m;  // n: 배열 크기, m: 찾을 숫자의 개수

    for (int i = 0; i < n; i++) {
        cin >> arr[i];  // 배열 입력
    }

    sort(arr, arr + n); // 이진 탐색을 위해 배열을 정렬
}

int main() {
    Input(); // 입력 받기 및 정렬

    // m개의 target 값에 대해 각각 탐색 수행
    for (int i = 0; i < m; i++) {
        int left = 0, right = n - 1, target = 0;
        int lower_bound = n;  // target의 첫 번째 위치 저장 변수 (초기값: n)
        int upper_bound = n;  // target을 초과하는 첫 번째 위치 저장 변수 (초기값: 0)
        cin >> target; // 찾고자 하는 값 입력

        // Lower Bound 탐색 (target이 처음 등장하는 위치)
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] >= target) { // target 이상이면 왼쪽 범위로 이동
                right = mid - 1;
                lower_bound = min(lower_bound, mid); // 더 작은 index 갱신
            }
            else { // target보다 작으면 오른쪽 범위 탐색
                left = mid + 1;
            }
        }

        // Upper Bound 탐색 (target보다 큰 첫 번째 위치)
        left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;

            if (arr[mid] > target) { // target보다 크다면 오른쪽 범위로 이동
                right = mid - 1;
                upper_bound = min(upper_bound, mid); // 더 작은 index 갱신
            }
            else { // target 이하이면 왼쪽 범위 탐색
                left = mid + 1;
            }
        }

        // target의 개수를 출력 (upper_bound - lower_bound)
        cout << abs(upper_bound - lower_bound) << "\n";
    }
}
