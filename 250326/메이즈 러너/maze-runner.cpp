#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int x, y;
	int dist;
	bool flag;
};

int n, m, k;
int arr[21][21];
int new_arr[21][21];
vector<Node> v;
pair<int, int> exits;

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Input(){
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;

		x--;
		y--;

		v.push_back({ x,y,0,false });
	}

	int x, y;
	cin >> x >> y;
	x--; y--;
	exits.first = x;
	exits.second = y;
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Move() {
	for (int i = 0; i < v.size(); i++) {
		if (v[i].flag == true) continue;

		int cx = v[i].x;
		int cy = v[i].y;
		int cdist = abs(exits.first - cx) + abs(exits.second - cy);
		int dist = v[i].dist;
		bool cflag = v[i].flag;

		int cnt = 0;
		int ax = 0 , ay = 0;
		for (int j = 0; j < 4; j++) {
			int nx = cx + dx[j];
			int ny = cy + dy[j];

			//가고자 하는 위치가 종료 지점이면 true로 바꾸고, dist 증가후 break
			if (nx == exits.first && ny == exits.second) {
				cflag = true;
				cnt++;
				break;
			}

			//아니면 이동한 곳에 대해 범위 안에 들어오고 벽이 아니면.
			if (InRange(nx, ny) && arr[nx][ny] == 0) {
				//거리 확인
				int ndist = abs(nx - exits.first) + abs(ny - exits.second);

				//거리가 더 작은 것에 대해 갱신.
				if (ndist < cdist) {
					cdist = ndist;
					ax = nx;
					ay = ny;
					cnt++;
				}
			}

		}

		//하나라도 cnt 이상을 만족하면. 해당 플레이어 재갱신
		if (cnt > 0) {
			v[i] = { ax,ay,dist + 1, cflag };
		}
		else {
			v[i] = { cx, cy, dist, cflag };
		}
	}
}

bool Finded(int cx, int cy, int k) {
	bool flag1 = false, flag2 = false;

	for (int i = cx; i < cx + k; i++) {
		for (int j = cy; j < cy + k; j++) {
			if (!InRange(i, j)) return false;

			if (exits.first == i && exits.second == j) flag1 = true;

			for (int l = 0; l < v.size(); l++) {
				if (v[l].flag == true) continue;
				if (v[l].x == i && v[l].y == j) {
					flag2 = true;
				}
			}
		}
	}

	if (flag1 == true && flag2 == true) {
		return true;
	}
	return false;
}

tuple<int, int, int> Find() {
	for (int k = 2; k <= n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (Finded(i, j, k)) {
					return make_tuple(i, j, k);
				}
			}
		}
	}


}

bool Flag() {
	for (int i = 0; i < v.size(); i++) {
		if (!v[i].flag) {
			return false;
		}
	}

	return true;
}

void Rotate(int x, int y, int dice) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			new_arr[i][j] = 0;
		}
	}

	int ex = exits.first, ey = exits.second;
	vector<pair<int, int>> temp;

	for (int i = 0; i < v.size(); i++) {
		temp.push_back({ -1, -1 });
	}

	for (int i = 0; i < dice; i++) {
		for (int j = 0; j < dice; j++) {
			//출구 회전.
			if (exits.first == x + i && exits.second == y + j) {
				ex = x + j;
				ey = y + dice - i - 1;
			}

			//플레이어 회전.
			for (int k = 0; k < v.size(); k++) {
				if (v[k].x == x + i && v[k].y == y + j) {
					int nx = x + j;
					int ny = y + dice - i - 1;
					temp[k] = { nx,ny };
				}
			}

			new_arr[i + x][y + j] = arr[x + dice - j - 1][y + i];
		}
	}

	//출구.
	exits = { ex,ey };

	//플레이어 회전.
	for (int i = 0; i < v.size(); i++) {
		if (temp[i].first != -1 && temp[i].second != -1) {
			v[i].x = temp[i].first;
			v[i].y = temp[i].second;
		}
	}

	//다시 옮기기.
	for (int i = 0; i < dice; i++) {
		for (int j = 0; j < dice; j++) {
			arr[x + i][y + j] = new_arr[x + i][y + j];

			if (arr[x + i][y + j] > 0) arr[x + i][y + j]--;
		}
	}
}

int main() {
	Input();

	for (int i = 0; i < 8; i++) {

		//다 통과 했는지 체크.
		if (Flag()) break;

		//플레이어들 이동.
		Move();

		//Print();

		//완탐으로 정사각형 찾기.
		int cx, cy, dice;
		tie(cx, cy, dice) = Find();

		//찾은 좌표에 대한 회전.
		Rotate(cx, cy, dice);

		//Print();
	}

	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i].dist;
	}

	cout << ans << "\n";
	cout << exits.first + 1 << " " << exits.second + 1;

}