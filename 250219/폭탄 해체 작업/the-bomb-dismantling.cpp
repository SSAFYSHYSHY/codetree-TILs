#include <iostream>
#include <algorithm>
#include <tuple>
#include <queue>

#define MAX_N 10000
#define MAX_T 10000

using namespace std;

// 변수 선언
int n;
pair<int, int> bombs[MAX_N];

int GetTimeLimit(int bomb_idx) {
    int time_limit;
    tie(time_limit, ignore) = bombs[bomb_idx];

    return time_limit;
}

int GetScore(int bomb_idx) {
    int score;
    tie(ignore, score) = bombs[bomb_idx];
    
    return score;
}

int main() {
    // 입력:
    cin >> n;
    for(int i = 0; i < n; i++) {
        int score, time_limit;
        cin >> score >> time_limit;
        bombs[i] = make_pair(time_limit, score);
    }

    sort(bombs, bombs + n);

    priority_queue<int> pq;
    int bomb_idx = n - 1;
    int ans = 0;

    for(int t = MAX_T; t >= 1; t--) {
        while(bomb_idx >= 0 && GetTimeLimit(bomb_idx) >= t) {
            pq.push(GetScore(bomb_idx));
            bomb_idx--;
        }

        if(!pq.empty()) {
            ans += pq.top();
            pq.pop();
        }
    }

    cout << ans;
    return 0;
}
