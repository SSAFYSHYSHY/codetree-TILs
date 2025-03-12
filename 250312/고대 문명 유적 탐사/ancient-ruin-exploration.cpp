#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

struct Node {
	int x, y, num, idx;
};

int k, m;
queue<int> saved_num;
vector<Node> v;
vector<pair<int, int>> pos;
int arr[5][5];
int new_arr[5][5];
int original_arr[5][5];
bool visited[5][5] = { false, };

int dx[] = { -1,1,0,0 };
int dy[] = { 0,0,-1,1 };

void Print() {

	cout << "\n\n";
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void Input() {
	cin >> k >> m;

	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> arr[i][j];
			original_arr[i][j] = arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		saved_num.push(x);
	}
}

void Rotate(int s_x, int s_y) {
	memset(new_arr, 0, sizeof(new_arr));

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			new_arr[s_x + j][s_y + 2 - i] = arr[s_x + i][s_y + j];
		}
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			arr[s_x + i][s_y + j] = new_arr[s_x + i][s_y + j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < 5 && 0 <= y && y < 5;
}

int BFS(int x, int y, int num) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visited[x][y] = true;
	int size = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == num) {
				q.push({ nx,ny });
				visited[nx][ny] = true;
				size++;
			}
		}
	}

	if (size >= 3) {
		return size;
	}
	return 0;
}

void Find_BFS(int x, int y, int k) {

	//회전 수.
	for (int i = 0; i < k; i++) {
		Rotate(x, y);
	}

	int sum = 0;
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (!visited[i][j] && arr[i][j] > 0) {
				sum += BFS(i, j, arr[i][j]);
			}
		}
	}

	memset(visited, false, sizeof(visited));

	if (sum > 0) {
		v.push_back({ x ,y ,sum,k });
	}

	//arr의 카피.
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			arr[i][j] = original_arr[i][j];
		}
	}
}

bool cmp(Node a, Node b) {
	if (a.num != b.num) return a.num > b.num;
	else if (a.idx != b.idx) return a.idx < b.idx;
	else if (a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

void Find() {
	int sum = 0;

	for (int i = 0; i <= 2; i++) {
		for (int j = 0; j <= 2; j++) {
			for (int k = 0; k < 4; k++) {
				Find_BFS(i, j, k);
			}
		}
	}

	sort(v.begin(), v.end(), cmp);
}

bool cmp2(pair<int, int> a, pair<int, int> b) {
	if (a.second != b.second) return a.second < b.second;
	return a.first > b.first;
}

int BFS2(int x, int y, int num) {
	queue<pair<int, int>> q;
	vector<pair<int, int>> temp;
	q.push({ x,y });
	temp.push_back({ x,y });
	visited[x][y] = true;
	int size = 1;

	while (!q.empty()) {
		int cx = q.front().first;
		int cy = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cx + dx[i];
			int ny = cy + dy[i];

			if (InRange(nx, ny) && !visited[nx][ny] && arr[nx][ny] == num) {
				q.push({ nx,ny });
				size++;
				visited[nx][ny] = true;
				temp.push_back({ nx,ny });
			}
		}
	}

	//크기가 3인 경우. temp 정렬.
	if (size >= 3) {
		for (int i = 0; i < temp.size(); i++) {
			pos.push_back({ temp[i].first, temp[i].second });
		}

		return size;
	}

	return 0;
}

int main() {
	Input();

	// 메인 while문 내부 수정
	while (k--) {
		int ans = 0;
		v.clear(); // Find 전에 꼭 비워야 함
		pos.clear();
		memset(visited, false, sizeof(visited));

		Find();
		if (v.empty()) break; // 아무 회전 결과도 없을 경우 종료

		// 가장 좋은 회전 실행
		for (int i = 0; i < v[0].idx; i++) Rotate(v[0].x, v[0].y);

		// 첫 BFS2 수행
		memset(visited, false, sizeof(visited));
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (!visited[i][j] && arr[i][j] > 0) {
					ans += BFS2(i, j, arr[i][j]);
				}
			}
		}

		sort(pos.begin(), pos.end(), cmp2);
		for (auto& p : pos) {
			arr[p.first][p.second] = 0;
			if (!saved_num.empty()) {
				arr[p.first][p.second] = saved_num.front();
				saved_num.pop();
			}
		}

		// 연쇄 처리
		while (true) {
			pos.clear();
			memset(visited, false, sizeof(visited));

			bool flag = false;
			int chain_sum = 0;

			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					if (!visited[i][j] && arr[i][j] > 0) {
						chain_sum += BFS2(i, j, arr[i][j]); // 누적합
					}
				}
			}

			if (chain_sum < 3) break;
			flag = true;

			sort(pos.begin(), pos.end(), cmp2);
			for (auto& p : pos) {
				arr[p.first][p.second] = 0;
				if (!saved_num.empty()) {
					arr[p.first][p.second] = saved_num.front();
					saved_num.pop();
				}
			}
			ans += chain_sum;

			// original_arr 업데이트
			for (int i = 0; i < 5; i++) {
				for (int j = 0; j < 5; j++) {
					original_arr[i][j] = arr[i][j];
				}
			}
		}

		if (ans == 0) break;
		cout << ans << " ";
	}

}