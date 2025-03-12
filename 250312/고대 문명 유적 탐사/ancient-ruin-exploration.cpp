#include <iostream>
#include <queue>
#include <vector>

#define N_large 5 // 고대 문명 전체 격자 크기입니다.
#define N_small 3 // 회전시킬 격자의 크기입니다.

using namespace std;

// 고대 문명 격자를 정의합니다
class Board {
public:
    int a[N_large][N_large];

    Board() {
        for (int i = 0; i < N_large; ++i) {
            for (int j = 0; j < N_large; ++j) {
                a[i][j] = 0;
            }
        }
    }

    // 주어진 y, x가 고대 문명 격자의 범위 안에 있는지 확인하는 함수
    bool InRange(int y, int x) {
        return 0 <= y && y < N_large && 0 <= x && x < N_large;
    }

    // 현재 격자에서 sy, sx를 좌측상단으로 하여 시계방향 90도 회전
    void Rotate(int sy, int sx) {
        int temp[3][3];
        for (int i = 0; i < N_small; ++i) {
            for (int j = 0; j < N_small; ++j) {
                temp[i][j] = a[sy + i][sx + j];
            }
        }
        // 90도 시계방향 회전
        for (int i = 0; i < N_small; ++i) {
            for (int j = 0; j < N_small; ++j) {
                a[sy + i][sx + j] = temp[N_small - j - 1][i];
            }
        }
    }

    // 현재 격자에서 유물 획득 (BFS)
    int CalScore() {
        int score = 0;
        bool visit[N_large][N_large] = {false};
        int dy[4] = {0, 1, 0, -1}, dx[4] = {1, 0, -1, 0};
        
        // BFS로 유물 탐색
        for (int i = 0; i < N_large; ++i) {
            for (int j = 0; j < N_large; ++j) {
                if (!visit[i][j]) {
                    queue<pair<int, int>> q, trace;
                    q.push({i, j});
                    trace.push({i, j});
                    visit[i][j] = true;
                    while (!q.empty()) {
                        auto cur = q.front(); q.pop();
                        for (int k = 0; k < 4; ++k) {
                            int ny = cur.first + dy[k], nx = cur.second + dx[k];
                            if (InRange(ny, nx) && a[ny][nx] == a[cur.first][cur.second] && !visit[ny][nx]) {
                                q.push({ny, nx});
                                trace.push({ny, nx});
                                visit[ny][nx] = true;
                            }
                        }
                    }
                    // 유물이 되면 점수 계산 및 비우기
                    if (trace.size() >= 3) {
                        score += trace.size();
                        while (!trace.empty()) {
                            auto t = trace.front(); trace.pop();
                            a[t.first][t.second] = 0;
                        }
                    }
                }
            }
        }
        return score;
    }

    // 유물 획득 후 조각 채우기
    void Fill(queue<int>& que) {
        for (int j = 0; j < N_large; ++j) {
            for (int i = N_large - 1; i >= 0; --i) {
                if (a[i][j] == 0 && !que.empty()) {
                    a[i][j] = que.front();
                    que.pop();
                }
            }
        }
    }
};

int main() {
    int M, K;
    queue<int> q;
    Board board;

    cin >> K >> M;
    for (int i = 0; i < N_large; ++i) {
        for (int j = 0; j < N_large; ++j) {
            cin >> board.a[i][j];
        }
    }

    for (int i = 0; i < M; ++i) {
        int t;
        cin >> t;
        q.push(t);
    }

    // 최대 K번의 탐사과정을 거칩니다.
    while (K--) {
        int maxScore = 0;
        Board maxScoreBoard = board;

        // 회전 목표에 맞는 결과를 maxScoreBoard에 저장합니다.
        for (int cnt = 1; cnt <= 3; ++cnt) {
            for (int sx = 0; sx <= N_large - N_small; ++sx) {
                for (int sy = 0; sy <= N_large - N_small; ++sy) {
                    Board rotated = board;
                    for (int i = 0; i < cnt; ++i) {
                        rotated.Rotate(sy, sx); // 지정된 위치에서 회전 수행
                    }
                    int score = rotated.CalScore();
                    if (maxScore < score) {
                        maxScore = score;
                        maxScoreBoard = rotated;
                    }
                }
            }
        }

        // 더 이상 유물을 획득할 수 없으면 탐사 종료
        if (maxScore == 0) break;

        board = maxScoreBoard;

        // 유물의 연쇄 획득
        while (true) {
            board.Fill(q);
            int newScore = board.CalScore();
            if (newScore == 0) break;
            maxScore += newScore;
        }

        cout << maxScore << " ";
    }

    return 0;
}
