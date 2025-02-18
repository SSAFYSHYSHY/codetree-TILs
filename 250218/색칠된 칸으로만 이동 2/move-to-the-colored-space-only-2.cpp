#include <iostream>
#include <queue>

#define MAX_N 100

using namespace std;

const int dy[4] = {-1, 0, 1, 0};
const int dx[4] = {0, -1, 0, 1};

// 변수 선언
int m, n;
int start_x, start_y;
int board[MAX_N][MAX_N];
int colored[MAX_N][MAX_N];
bool visited[MAX_N][MAX_N];

// bfs를 통해 d 이하로 차이 나는 칸만 갈 수 있을 때,
// 갈 수 있는 지점을 전부 구해줍니다.
void bfs(int d) {
    queue<pair<int,int> > q;

    q.push(make_pair(start_x, start_y));
    visited[start_x][start_y] = true;

    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();

        // 인접한 칸 중 갈 수 있는 칸을 찾아
        // 갈 수 있다면 queue에 넣습니다.
        for(int i = 0; i < 4; i++) {
            int next_x = p.first + dx[i], next_y = p.second + dy[i];
            if (next_x >= 0 && next_x < m && next_y >= 0 && next_y < n)
                if (!visited[next_x][next_y] && abs(board[p.first][p.second] - board[next_x][next_y]) <= d) {
                    q.push(make_pair(next_x, next_y));
                    visited[next_x][next_y] = true;
                }
        }
    }
}

// d 이하로 차이 나는 칸만 갈 수 있을 때,
// 모든 색칠된 칸으로 이동할 수 있는지 확인합니다.
bool reachable(int d) {
    // visited 배열을 초기화합니다.
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) visited[i][j] = false;

    bfs(d);

    // 모든 색칠된 칸으로 이동할 수 있는지 확인합니다.
    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            if(colored[i][j] && !visited[i][j]) return false;
    return true;
}

int main() {
    // 입력
    cin >> m >> n;

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++)
            cin >> board[i][j];

    for(int i = 0; i < m; i++)
        for(int j = 0; j < n; j++) {
            cin >> colored[i][j];
            // 시작점(색칠된 점 중에서)을 구합니다.
            if (colored[i][j]) start_x = i, start_y = j;
        }

    int lo = 0;                     // 답이 될 수 있는 가장 작은 숫자 값을 설정합니다.
    int hi = 1000000000;            // 답이 될 수 있는 가장 큰 숫자 값을 설정합니다.
    int ans = 0;                    // 답을 저장합니다.

    while(lo <= hi) {               // [lo, hi]가 유효한 구간이면 계속 수행합니다.
        int mid = (lo + hi) / 2;    // 가운데 위치를 선택합니다.
        if(reachable(mid)) {        // 결정문제에 대한 답이 Yes라면
            hi = mid - 1;           // 왼쪽에 조건을 만족하는 숫자가 더 있을 가능성 때문에 right를 바꿔줍니다.
            ans = mid;              // 답의 후보들 중 최댓값을 계속 갱신해줍니다.
        }
        else
            lo = mid + 1;           // 결정문제에 대한 답이 No라면 right를 바꿔줍니다.
    }

    // 정답을 출력합니다.
    cout << ans;
    return 0;   
}
