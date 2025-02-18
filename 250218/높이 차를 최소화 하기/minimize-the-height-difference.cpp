#include <iostream>
#include <algorithm>
#include <queue>

#define MAX_N 100
#define MAX_H 500

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};

// 변수 선언
int n, m;
int board[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

// bfs를 이용해 이동합니다. visited 배열로 끝까지 도달할 수 있는지 확인합니다.
void bfs(int x, int y, int lo, int hi) {
    queue<pair<int, int>> q;
    q.push({x, y});
    visited[x][y] = true;

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (int dir = 0; dir < 4; dir++) {
            int nx = x + dx[dir];
            int ny = y + dy[dir];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && board[nx][ny] >= lo && board[nx][ny] <= hi && visited[nx][ny] == false) {
                q.push({nx, ny});
                visited[nx][ny] = true;
            }
        }
    }
}

// visited 배열을 초기화합니다.
void clear_visited() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++) visited[i][j] = false;
}

// d 이하로 최대 높이와 최소 높이의 차이가 나는 칸만 갈 수 있을 때,
// 마지막 칸으로 이동할 수 있는지 확인합니다.
bool reachable(int d) {
    // 모든 높이 제한에 대해서, 도달 가능한지 확인합니다.
    for(int lo = 1; lo <= MAX_H; lo++) {
        clear_visited();

        int hi = lo + d;
        // 만약 시작하는 위치의 높이가 lo이상 hi이하라면 dfs로 탐색합니다.
        if(board[0][0] >= lo && board[0][0] <= hi)
            bfs(0, 0, lo, hi);
        // 마지막에 도달할 수 있으면 도달 가능합니다.
        if(visited[n - 1][m - 1]) return true;
    }

    return false;
}

int main() {
    // 입력
    cin >> n >> m;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> board[i][j];

    int lo = 0;                     // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int hi = MAX_H;                 // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    int ans = MAX_H;                // 답을 저장합니다.

    while(lo <= hi) {               // [lo, hi]가 유효한 구간이면 계속 수행합니다.
        int mid = (lo + hi) / 2;    // 가운데 위치를 선택합니다.
        if(reachable(mid)) {        // 결정문제에 대한 답이 Yes라면
            hi = mid - 1;           // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            ans = min(ans, mid);    // 답의 후보들 중 최솟값을 계속 갱신해줍니다.
        }
        else
            lo = mid + 1;           // 결정문제에 대한 답이 No라면 right를 바꿔줍니다.
    }

    // 정답을 출력합니다.
    cout << ans;
    return 0;   
}
