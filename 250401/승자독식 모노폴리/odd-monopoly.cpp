#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int n, m, k;
int arr[22][22];
int dice_hp[22][22];

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

int shape[501][4][4];

struct Node {
    int idx, x, y, dir;
    bool flag;
};
vector<Node> player;

bool cmp(Node a, Node b) {
    return a.idx < b.idx;
}

void Input() {
    cin >> n >> m >> k;

    memset(arr, 0, sizeof(arr));
    memset(dice_hp, 0, sizeof(dice_hp));

    for (int i = 0; i <= n + 1; i++) {
        for (int j = 0; j <= n + 1; j++) {
            arr[i][j] = -1;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
            if (arr[i][j]) {
                dice_hp[i][j] = k;
                player.push_back({ arr[i][j], i, j, 0, true });
            }
        }
    }

    sort(player.begin(), player.end(), cmp);

    for (int i = 0; i < m; i++) {
        int num;
        cin >> num;
        player[i].dir = num - 1;
    }

    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                cin >> shape[i][j][k];
                shape[i][j][k]--;
            }
        }
    }
}

void Print() {
    cout << "---------------------";
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << dice_hp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";

    for(int i = 1 ; i<= n ; i++) {
        for (int j = 1; j <= n; j++) {
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n\n";
    cout << "\n";
}

bool Flag() {
    if (!player[0].flag) return false;
    
    for (int i = 1; i < player.size(); i++) {
        if (player[i].flag) return false;
    }

    return true;
}

void Sub() {
    //Print();

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (dice_hp[i][j] > 0) {
                dice_hp[i][j]--;
                if (dice_hp[i][j] == 0) arr[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < player.size(); i++) {
        if (player[i].flag) {
            dice_hp[player[i].x][player[i].y] = k;
        }
    }
}

bool InRange(int x, int y) {
    return (x >= 1 && x <= n && y >= 1 && y <= n);
}

void Move() {
    for (int i = 0; i < player.size(); i++) {
        if (!player[i].flag) continue;

        int idx = player[i].idx;
        int x = player[i].x;
        int y = player[i].y;
        int dir = player[i].dir;

        bool moved = false;
        for (int j = 0; j < 4; j++) {
            int ndir = shape[idx][dir][j];
            int nx = x + dx[ndir];
            int ny = y + dy[ndir];

            if (InRange(nx, ny) && arr[nx][ny] == 0) {
                dice_hp[nx][ny] = k;
                player[i] = { idx, nx, ny, ndir, true };
                moved = true;
                break;
            }
        }

        if (!moved) {
            for (int j = 0; j < 4; j++) {
                int ndir = shape[idx][dir][j];
                int nx = x + dx[ndir];
                int ny = y + dy[ndir];

                if (InRange(nx, ny) && arr[nx][ny] == idx) {
                    player[i] = { idx, nx, ny, ndir, true };
                    dice_hp[nx][ny] = k;
                    break;
                }
            }
        }
    }
}

void Player_Move() {

    for (int i = 0; i < player.size(); i++) {
        if (!player[i].flag) continue;
        arr[player[i].x][player[i].y] = player[i].idx;

        for (int j = i + 1; j < player.size(); j++) {
            if (!player[j].flag) continue;

            if (player[i].x == player[j].x && player[i].y == player[j].y) {
                player[j].flag = false;
                arr[player[i].x][player[i].y] = player[i].idx;
            }
        }
    }
}

int main() {
    Input();
    for (int i = 0; i <= 999; i++) {
        if (Flag()) {
            cout << i << "\n";
            return 0;
        }

        Move();
        Player_Move();
        Sub();
        //Print();
    }

    cout << -1 << "\n";
    return 0;
}
