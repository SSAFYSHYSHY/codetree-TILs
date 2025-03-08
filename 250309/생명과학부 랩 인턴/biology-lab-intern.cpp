#include <iostream>
#include <tuple>

#define MAX_NUM 100
#define DIR_NUM 4
#define BLANK make_tuple(-1, -1, -1)

using namespace std;

int n, m, k;

tuple<int, int, int> mold[MAX_NUM][MAX_NUM];
tuple<int, int, int> next_mold[MAX_NUM][MAX_NUM];

int ans;

bool InRange(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

void Collect(int col) {
    for (int row = 0; row < n; row++)
        if (mold[row][col] != BLANK) {
            int mold_size;
            tie(mold_size, ignore, ignore) = mold[row][col];

            ans += mold_size;
            mold[row][col] = BLANK;
            break;
        }
}

tuple<int, int, int> GetNextPos(int x, int y, int dist, int move_dir) { 
    int dx[DIR_NUM] = { -1, 1, 0, 0 };
    int dy[DIR_NUM] = { 0, 0, 1, -1 };

    while (dist--) {
        int next_x = x + dx[move_dir], next_y = y + dy[move_dir];
        if (InRange(next_x, next_y))
            x = next_x, y = next_y;
        else {
            move_dir = (move_dir % 2 == 0) ? (move_dir + 1) : (move_dir - 1);
            x = x + dx[move_dir]; y = y + dy[move_dir];
        }
    }

    return make_tuple(x, y, move_dir);
}

void Move(int x, int y) {
    int mold_size, dist, move_dir;
    tie(mold_size, dist, move_dir) = mold[x][y];

    int next_x, next_y, next_dir;
    tie(next_x, next_y, next_dir) = GetNextPos(x, y, dist, move_dir);

    tuple<int, int, int> new_mold = make_tuple(mold_size, dist, next_dir);

    if (new_mold > next_mold[next_x][next_y])
        next_mold[next_x][next_y] = new_mold;
}

void MoveAll() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            next_mold[i][j] = BLANK;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (mold[i][j] != BLANK)
                Move(i, j);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mold[i][j] = next_mold[i][j];
}

void Simulate(int col) {
    Collect(col);

    MoveAll();
}

int main() {
    cin >> n >> m >> k;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            mold[i][j] = BLANK;

    for (int i = 0; i < k; i++) {
        int x, y, s, d, b;
        cin >> x >> y >> s >> d >> b;

        if (d <= 2)
            s %= (2 * n - 2);
        else
            s %= (2 * m - 2);

        mold[x - 1][y - 1] = make_tuple(b, s, d - 1);
    }

    for (int col = 0; col < m; col++)
        Simulate(col);

    cout << ans;
    return 0;
}
