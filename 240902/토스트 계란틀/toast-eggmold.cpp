#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, l, r, days = 0;
int arr[51][51];
bool visited[51][51];

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < n;
}

bool BFS(int x, int y) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> unionCells;
    q.push({x, y});
    visited[x][y] = true;
    unionCells.push_back({x, y});

    int sum = arr[x][y];
    int count = 1;
    bool isUnionFormed = false;

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (InRange(nx, ny) && !visited[nx][ny]) {
                int populationDiff = abs(arr[cx][cy] - arr[nx][ny]);
                if (l <= populationDiff && populationDiff <= r) {
                    q.push({nx, ny});
                    visited[nx][ny] = true;
                    unionCells.push_back({nx, ny});
                    sum += arr[nx][ny];
                    count++;
                    isUnionFormed = true;
                }
            }
        }
    }

    if (isUnionFormed) {
        int avg = sum / count;
        for (auto &cell : unionCells) {
            arr[cell.first][cell.second] = avg;
        }
    }

    return isUnionFormed;
}

bool Simulate() {
    memset(visited, false, sizeof(visited));
    bool moved = false;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                if (BFS(i, j)) {
                    moved = true;
                }
            }
        }
    }

    return moved;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    while (Simulate()) {
        days++;
    }

    cout << days << "\n";
    return 0;
}