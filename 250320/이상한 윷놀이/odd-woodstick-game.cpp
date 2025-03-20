#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

#define WHITE 0
#define RED 1
#define BLUE 2

using namespace std;

int n, k;
int arr[13][13];
vector<pair<int, int>> v[13][13];

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

tuple<int, int, int> Find(int target_num) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < (int)v[i][j].size(); k++) {
				int p_num, p_dir;
				tie(p_num, p_dir) = v[i][j][k];

				if (p_num == target_num) {
					return make_tuple(i, j, p_dir);
				}
			}
		}
	}
}

vector<pair<int, int>> Pop(int x, int y, int num) {
	vector<pair<int, int>> pieces;

	for (int i = 0; i < (int)v[x][y].size(); i++) {
		int p_num, dir;
		tie(p_num, dir) = v[x][y][i];

		if (p_num == num) {
			pieces.assign(v[x][y].begin() + i, v[x][y].end());

			v[x][y].erase(v[x][y].begin() + i, v[x][y].end());
			break;
		}
 	}

	return pieces;
}

void Move(int x, int y, vector<pair<int, int>> pieces, bool flag) {
	if (flag) {
		reverse(pieces.begin(), pieces.end());
	}
	v[x][y].insert(v[x][y].end(), pieces.begin(), pieces.end());
}

bool Calc() {
	int dx[] = { 0,0,-1,1 };
	int dy[] = { 1,-1,0,0 };

	for (int i = 0; i < k; i++) {
		int px, py, dir;
		tie(px, py, dir) = Find(i);

		int nx = px + dx[dir];
		int ny = py + dy[dir];
		bool flag = false;

		if (!InRange(nx, ny) || arr[nx][ny] == BLUE) {
			dir = (dir % 2 == 0) ? (dir + 1) : (dir - 1);
			nx = px + dx[dir];
			ny = py + dy[dir];

			if (!InRange(nx, ny) || arr[nx][ny] == BLUE) {
				nx = px;
				ny = py;
			}
			else if (arr[nx][ny] == RED) {
				flag = true;
			}
		}
		else if (arr[nx][ny] == RED) {
			flag = true;
		}

		vector<pair<int, int>> pieces = Pop(px, py, i);
		pieces[0] = make_pair(i, dir);

		Move(nx, ny, pieces, flag);

		if (v[nx][ny].size() >= 4) {
			return true;
		}
	} 

	return false;
}

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < k; i++) {
		int x, y, d;
		cin >> x >> y >> d;

		v[x - 1][y - 1].push_back({ i, d - 1 });
	}

	int ans = -1;
	for (int t = 1; t <= 1000; t++) {
		bool flag = Calc();

		if (flag) {
			ans = t;
			break;
		}
	}

	cout << ans;
}