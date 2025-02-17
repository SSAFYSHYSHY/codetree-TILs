#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> points;

bool canPlace(int dist) {
    int count = 1; // 첫 번째 물건 배치
    int last = points[0]; // 첫 번째 물건 위치

    for (int i = 1; i < N; i++) {
        if (points[i] - last >= dist) { // dist 이상 떨어진 곳에 배치 가능하면
            count++;
            last = points[i]; // 마지막 배치 위치 갱신
        }
    }
    return count >= M; // M개 이상 배치 가능하면 true
}

int binarySearch() {
    sort(points.begin(), points.end()); // 좌표 정렬

    int left = 1, right = points[N - 1] - points[0];
    int result = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        
        if (canPlace(mid)) { // mid 거리 이상으로 배치 가능
            result = mid; // 가능한 거리 저장
            left = mid + 1; // 더 큰 거리 시도
        } else {
            right = mid - 1; // 거리 줄이기
        }
    }
    return result;
}

int main() {
    cin >> N >> M;
    points.resize(N);
    
    for (int i = 0; i < N; i++) {
        cin >> points[i];
    }
    
    cout << binarySearch() << endl;
}