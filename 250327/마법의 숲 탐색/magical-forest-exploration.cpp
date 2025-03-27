#include <iostream>
#include <queue>

#define MAX_L 70

using namespace std;

int R, C, K;
int A[MAX_L + 3][MAX_L]; 
int dy[4] = { -1, 0, 1, 0 }, dx[4] = { 0, 1, 0, -1 };
bool isExit[MAX_L + 3][MAX_L]; 
int answer; 

bool inRange(int y, int x) {
    return 3 <= y && y < R + 3 && 0 <= x && x < C;
}

void resetMap() {
    for (int i = 0; i < R + 3; i++) {
        for (int j = 0; j < C; j++) {
            A[i][j] = 0;
            isExit[i][j] = false;
        }
    }
}


bool canGo(int y, int x) {
    bool flag = 0 <= x - 1 && x + 1 < C && y + 1 < R + 3;
    flag = flag && (A[y - 1][x - 1] == 0);
    flag = flag && (A[y - 1][x] == 0);
    flag = flag && (A[y - 1][x + 1] == 0);
    flag = flag && (A[y][x - 1] == 0);
    flag = flag && (A[y][x] == 0);
    flag = flag && (A[y][x + 1] == 0);
    flag = flag && (A[y + 1][x] == 0);
    return flag;
}

int bfs(int y, int x) {
    int result = y;
    queue<pair<int, int> > q;
    bool visit[MAX_L + 3][MAX_L];
    for (int i = 0; i < R + 3; i++) {
        for (int j = 0; j < C; j++) {
            visit[i][j] = false;
        }
    }

    q.push(make_pair(y, x));
    visit[y][x] = true;
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = cur.first + dy[k], nx = cur.second + dx[k];
            if (inRange(ny, nx) && !visit[ny][nx] && (A[ny][nx] == A[cur.first][cur.second] || (A[ny][nx] != 0 && isExit[cur.first][cur.second]))) {
                q.push(make_pair(ny, nx));
                visit[ny][nx] = true;
                result = max(result, ny);
            }
        }
    }
    return result;
}

void down(int y, int x, int d, int id) {
    if (canGo(y + 1, x)) {
        down(y + 1, x, d, id);
    }
    else if (canGo(y + 1, x - 1)) {
        down(y + 1, x - 1, (d + 3) % 4, id);
    }
    else if (canGo(y + 1, x + 1)) {
        down(y + 1, x + 1, (d + 1) % 4, id);
    }
    else {
        if (!inRange(y - 1, x - 1) || !inRange(y + 1, x + 1)) {
            resetMap();
        }
        else {
            A[y][x] = id;
            for (int k = 0; k < 4; k++)
                A[y + dy[k]][x + dx[k]] = id;
            isExit[y + dy[d]][x + dx[d]] = true;
            answer += bfs(y, x) - 3 + 1;
        }
    }
}

int main() {
    cin >> R >> C >> K;
    for (int id = 1; id <= K; id++) { 
        int x, d;
        cin >> x >> d; 
        x--;
        down(0, x, d, id);
    }
    cout << answer << endl;
    return 0;
}
