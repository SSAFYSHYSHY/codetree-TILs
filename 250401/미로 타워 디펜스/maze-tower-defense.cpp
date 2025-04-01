#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0};

int arr[51][51];
int new_arr[51][51];
vector<int> v, new_v;
queue<int> q, new_q;
int ans = 0;

void Input() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Calc(int dir, int pow) {
	int x = n / 2, y = n / 2;

	for (int i = 0; i < pow; i++) {
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		ans += arr[nx][ny];
		arr[nx][ny] = 0;

		x = nx;
		y = ny;
	}
}

void Acc() {
	if (!q.empty()) {
		q.pop();
	}

	int cnt = 0, dir = 2, dist = 1;
	int x = n / 2, y = n / 2;

	while (1) {

		for (int i = 0; i < dist; i++) {
			
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (nx == 0 && ny == -1) return;

			if (arr[nx][ny] > 0) {
				q.push(arr[nx][ny]);
			}

			x = nx;
			y = ny;
		}

		dir = (dir + 3) % 4;
		cnt++;

		if (cnt == 2) {
			dist++;
			cnt = 0;
		}
	}
}

void Fill() {
	memset(new_arr, 0, sizeof(new_arr));
	int x = n / 2, y = n / 2;

	int cnt = 0, dist = 1, dir = 2, idx = 0;

	while(1) {
		if (!InRange(x, y)) break;

		for (int i = 0; i < dist; i++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (!q.empty()) {
				new_arr[nx][ny] = q.front();
				q.pop();
			}

			x = nx;
			y = ny;
		}

		dir = (dir + 3) % 4;
		cnt++;

		if (cnt == 2) {
			dist++;
			cnt = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}

}

void Fill2() {
	v.clear();
	new_v.clear();
	while (!new_q.empty()) {
		new_q.pop();
	}

	int x = n / 2, y = n / 2;
	int dir = 2, dist = 1, cnt = 0;

	while (1) {

		if (!InRange(x, y)) break;

		for (int i = 0; i < dist; i++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];;

			if (arr[nx][ny] > 0) {
				v.push_back(arr[nx][ny]);
			}

			x = nx;
			y = ny;
		}

		dir = (dir + 3) % 4;
		cnt++;
		if (cnt == 2) {
			dist++;
			cnt = 0;
		}
	}

	//사이즈 별로.
	for (int i = 0; i < v.size(); i++) {
		int ncnt = 1;

		for (int j = i + 1; j < v.size(); j++) {
			if (v[i] == v[j]) {
				i = j;
				ncnt++;
			}
			else {
				break;
			}
		}

		new_v.push_back(ncnt);
		new_v.push_back(v[i]);
	}

	v = new_v;

	for (int i = 0; i < v.size(); i++) {
		new_q.push(v[i]);
	}

	int idx = 0;
	x = n / 2, y = n / 2;
	cnt = 0, dir = 2, dist = 1;

	while (1) {
		if (!InRange(x, y)) break;

		for (int i = 0; i < dist; i++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (!new_q.empty()) {
				arr[nx][ny] = new_q.front();
				new_q.pop();
			}

			x = nx;
			y = ny;
		}

		dir = (dir + 3) % 4;
		cnt++;

		if (cnt == 2) {
			dist++;
			cnt = 0;
		}
	}
}

bool Flag() {
	int x = n / 2,y = n / 2;
	int cnt = 0;
	int dir = 2;
	int dist = 1;
	int now_num = 0;
	int idx = 0;
	vector<pair<int, int>> v_pos[501];

	while (1) {
		if (!InRange(x, y))break;

		for (int i = 0; i < dist; i++) {
			int nx = x + dx[dir];
			int ny = y + dy[dir];

			//now_num이 0 인데, 가고자 하는 위치가 0 이 아니면.
			if (now_num == 0 && arr[nx][ny] != 0) {
				now_num = arr[nx][ny];
				v_pos[idx].push_back({ nx,ny });
			}
			//now_num이 숫자가 배정되어 있고, 가고자 하는 위치가 다르다면, 갱신.
			else if (now_num != 0 && now_num != arr[nx][ny]) {
				now_num = arr[nx][ny];
				idx++;
				v_pos[idx].push_back({nx,ny});
			}
			//같은 숫자면.
			else if (now_num != 0 && now_num == arr[nx][ny]) {
				v_pos[idx].push_back({nx,ny});
			}

			x = nx;
			y = ny;
		}

		dir = (dir + 3) % 4;
		cnt++;

		if (cnt == 2) {
			cnt = 0;
			dist++;
		}
	}

	bool change = false;
	for (int i = 0; i < idx; i++) {
		if (v_pos[i].size() >= 4) {
			ans = ans + (v_pos[i].size() * arr[v_pos[i][0].first][v_pos[i][0].second]);

			for (int j = 0; j < v_pos[i].size(); j++) {
				arr[v_pos[i][j].first][v_pos[i][j].second] = 0;

			}
			change = true;
		}
	}

	if (!change) return false;
	return true;
}

void Print() {
	cout << "----------------";
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Print2() {
	cout << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << " ";
	}
	cout << "\n";
}

int main() {
	Input();

	for (int i = 0; i < m; i++) {
		int dir, pow;
		cin >> dir >> pow;

		//dir 방향으로 pow 만큼 없애고 ans 누적.
		Calc(dir, pow);
		
		//벡터에 중앙회오리에 시작해서 숫자 누적.
		Acc();
		
		//다시 회오리에 채워넣어주고 arr갱신.
		Fill();

		while (1) {

			if (!Flag()) break;
			else {

				Acc();

				Fill();
			}
		}

		//Acc();
		//사이즈, 개수 new_v에 누적. arr에 다시 카피.
		Fill2();
		//Print();
	}

	cout << ans;
	return 0;
}