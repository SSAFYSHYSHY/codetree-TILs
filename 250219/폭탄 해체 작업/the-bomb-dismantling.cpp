#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Bomb {
    int score, time_limit;
};

// 정렬 기준: 시간 제한이 긴 순으로 정렬 (내림차순)
bool cmp(const Bomb &a, const Bomb &b) {
    return a.time_limit > b.time_limit;
}

int maxBombScore(int n, vector<Bomb>& bombs) {
    // 제한 시간이 긴 순서로 정렬
    sort(bombs.begin(), bombs.end(), cmp);

    priority_queue<int, vector<int>, greater<int>> pq;  // 최소 힙 (점수가 낮은 것 우선 삭제)
    int totalScore = 0;
    int currentTime = 0;

    for (const Bomb &bomb : bombs) {
        if (currentTime < bomb.time_limit) {
            // 아직 시간 내에 해체 가능하면 추가
            pq.push(bomb.score);
            totalScore += bomb.score;
            currentTime++;
        } else if (!pq.empty() && pq.top() < bomb.score) {
            // 점수가 더 높은 폭탄을 해체하기 위해 낮은 점수의 폭탄 제거
            totalScore += bomb.score - pq.top();
            pq.pop();
            pq.push(bomb.score);
        }
    }

    return totalScore;
}

int main() {
    int n;
    cin >> n;

    vector<Bomb> bombs(n);
    for (int i = 0; i < n; i++) {
        cin >> bombs[i].score >> bombs[i].time_limit;
    }

    cout << maxBombScore(n, bombs) << endl;
    return 0;
}
