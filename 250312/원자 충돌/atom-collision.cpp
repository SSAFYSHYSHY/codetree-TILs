#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Fireball {
    int x, y, mass, speed, dir;
};

int n, m, k;
vector<Fireball> cur;
int dx[] = { -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 1, 1, 1, 0, -1, -1, -1 };

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++) {
        int x, y, mass, speed, dir;
        cin >> x >> y >> mass >> speed >> dir;
        cur.push_back({ x, y, mass, speed, dir });
    }
}

void move_fireballs() {
    vector<Fireball> moved;
    for (auto& fb : cur) {
        int nx = ((fb.x - 1 + dx[fb.dir] * fb.speed) % n + n) % n + 1;
        int ny = ((fb.y - 1 + dy[fb.dir] * fb.speed) % n + n) % n + 1;
        moved.push_back({ nx, ny, fb.mass, fb.speed, fb.dir });
    }
    cur = moved;
}

void merge_fireballs() {
    map<pair<int, int>, vector<Fireball>> map_fireballs;
    for (auto& fb : cur) {
        map_fireballs[{fb.x, fb.y}].push_back(fb);
    }

    vector<Fireball> next;
    for (auto& entry : map_fireballs) {
        auto [x, y] = entry.first;
        auto& vec = entry.second;

        if (vec.size() == 1) {
            next.push_back(vec[0]);
        } else {
            int total_mass = 0, total_speed = 0;
            bool all_even = true, all_odd = true;

            for (auto& fb : vec) {
                total_mass += fb.mass;
                total_speed += fb.speed;
                if (fb.dir % 2 == 0) all_odd = false;
                else all_even = false;
            }

            int new_mass = total_mass / 5;
            if (new_mass == 0) continue;

            int new_speed = total_speed / vec.size();
            vector<int> new_dirs = (all_even || all_odd) ? vector<int>{0, 2, 4, 6} : vector<int>{1, 3, 5, 7};

            for (int d : new_dirs) {
                next.push_back({ x, y, new_mass, new_speed, d });
            }
        }
    }

    cur = next;
}

int get_total_mass() {
    int sum = 0;
    for (auto& fb : cur) sum += fb.mass;
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    input();
    while (k--) {
        move_fireballs();
        merge_fireballs();
    }

    cout << get_total_mass() << '\n';
    return 0;
}
