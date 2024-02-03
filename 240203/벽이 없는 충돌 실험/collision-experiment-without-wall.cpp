#include <iostream>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;


//idx, x,y,w,dir
vector<tuple<int, int, int, int, int>> v;
vector<pair<int, int>> arr[2001][2001];
int t, n, ans = -1, max_num, ans_idx;
vector<tuple<int, int, int, int, int>> temp_v;

int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < max_num && 0 <= y && y < max_num;
}

void CalcAll() {
	temp_v.clear();
	int idx, x, y, w, dir;

	for (int i = 0; i < v.size(); i++) {
		tie(idx, x, y, w, dir) = v[i];

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (InRange(nx, ny)) {
			temp_v.push_back(make_tuple(idx, nx, ny, w, dir));
		}

		//다음 공이 없으면 해당 번호와 무게 삽입, 있으면 충돌 연산.
		if (arr[nx][ny].empty()) {
			arr[nx][ny].push_back(make_pair(idx, w));
		}
		//충돌 연산 조건, 다음에 있는 것보다 무게가 크거나 같으면, idx로 비교.
		else if (w == arr[nx][ny].front().second && idx > arr[nx][ny].front().first) {
			ans = ans_idx;
			arr[nx][ny].push_back(make_pair(idx, w));
		}
	}
	//복사
	v = temp_v;
}

void Move() {
	//이동.
	temp_v.clear();
	int idx, x, y, w, dir;

	for (int i = 0; i < v.size(); i++) {
		tie(idx, x, y, w, dir) = v[i];

		if (w == arr[x][y].front().second && idx == arr[x][y].front().second) {
			temp_v.push_back(make_tuple(idx, x, y, w, dir));
			arr[x][y].push_back(make_pair(0, 0));
		}
	}
	v = temp_v;
}

void Simul() {
	//모조리 연산.
	CalcAll();

	//이동.
	Move();
}

int main() {
	cin >> t;

	while (t--) {
		v.clear();
		int dirc[128];
		dirc['U'] = 0;
		dirc['L'] = 1;
		dirc['R'] = 2;
		dirc['D'] = 3;
		ans = -1;
		cin >> n;

		for (int i = 0; i < n; i++) {
			int x, y, w;
			char dir;
			cin >> x >> y >> w >> dir;
			x += 1000;
			y += 1000;

			if (x > max_num) {
				max_num = x;
			}
			if (y > max_num) {
				max_num = y;
			}

			v.push_back(make_tuple(i, x, y, w, dirc[dir]));
		}

		//최장 길이 만큼 반복 그래야 왔다 갔다 2번씩 함 그러다 충돌이 일어나면 그게 기록.
		for (ans_idx = 1; ans_idx <= 2 * max_num; ans_idx++) {
			Simul();
		}
		cout << ans << "\n";
	}
}