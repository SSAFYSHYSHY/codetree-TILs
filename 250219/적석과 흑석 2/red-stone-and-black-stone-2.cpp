#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int C, N;
    cin >> C >> N;

    vector<int> red(C); // 빨간 돌 (T값)
    vector<pair<int, int>> black(N); // 검은 돌 (A, B)

    for (int i = 0; i < C; i++) {
        cin >> red[i];
    }

    for (int i = 0; i < N; i++) {
        cin >> black[i].first >> black[i].second;
    }

    // 빨간 돌 오름차순 정렬
    sort(red.begin(), red.end());
    // 검은 돌 B 기준 오름차순 정렬
    sort(black.begin(), black.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });

    int count = 0; // 매칭된 쌍의 개수
    int j = 0; // 검은 돌 인덱스

    for (int i = 0; i < C; i++) {
        while (j < N && black[j].second < red[i]) {
            j++; // 빨간 돌을 포함할 수 없는 검은 돌 건너뜀
        }

        if (j < N && black[j].first <= red[i] && red[i] <= black[j].second) {
            count++; // 매칭 성공
            j++; // 해당 검은 돌 사용했으므로 다음 검은 돌로 이동
        }
    }

    cout << count << endl;
    return 0;
}
