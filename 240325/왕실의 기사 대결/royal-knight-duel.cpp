#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

char crr[41][41];
int arr[41][41];
int new_arr[41][41];

bool visited[41][41] = {false,};
bool c_flag = false;
bool flag_health[31] = { false, };

int l, n, q, ans = 0;

int health[31] = {0,};
queue<pair<int,int>> bfs_q;

//0,1,2,3
int dx[] = {-1,0,1,0};
int dy[] = {0,1,0,-1};

void Print() {
	cout << " \n";
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cout << new_arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";

	cout << "\n";

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			cout << visited[i][j] << " ";
		}
		cout << "\n";
	}

	cout << "\n";
}

void Initial(int num) {
	bool flag = false;
	c_flag = false;

	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			visited[i][j] = false;
			new_arr[i][j] = 0;

			if (arr[i][j] == num) {
				flag = true;
				bfs_q.push(make_pair(i,j ));
				visited[i][j] = true;
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < l && 0 <= y && y < l;
}

void New_BFS(int x, int y) {
	queue<pair<int, int>> n_q;
	n_q.push(make_pair(x, y));
	visited[x][y] = true;

	while (!n_q.empty()) {
		pair<int, int> p = n_q.front();
		int x = p.first;
		int y = p.second;
		n_q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (InRange(nx, ny) && arr[nx][ny] == arr[x][y] && !visited[nx][ny]) {
				visited[nx][ny] = true;
				n_q.push(make_pair( nx, ny));
			}
		}
	}
}

void BFS(int d) {
	while (!bfs_q.empty()) {
		pair<int, int> p = bfs_q.front();
		int x = p.first;
		int y = p.second;
		bfs_q.pop();

		int nx = x + dx[d];
		int ny = y + dy[d];

		if (InRange(nx, ny) && !visited[nx][ny]) {
			//같은 값이면.
			if (arr[nx][ny] == arr[x][y]) {
				visited[nx][ny] = true;
				bfs_q.push(make_pair(nx, ny));
			}
			//다른 값에 마주하게 되면 같이 가야 함.
			else if(arr[x][y] != arr[nx][ny] && arr[nx][ny] > 0) {
				c_flag = true;
				New_BFS(nx,ny);
			}
		}
	}
}

bool Flag_Move(int dir) {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			if (visited[i][j] == true) {
				//이동하고자 하는 범위 안에 있고
				if (InRange(i + dx[dir], j + dy[dir])) {
					//해당 범위가 벽이라면 반환.
					if (crr[i + dx[dir]][j + dy[dir]] == 'w') {
						return false;
					}
				}
				//범위 밖에 도달하면
				else {
					return false;
				}

			}
		}

	}

	return true;
}

void Move(int flag , int dir) {
	if (flag == 1) {
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				if (arr[i][j] > 0 && visited[i][j]) {
					new_arr[i + dx[dir]][j + dy[dir]] = arr[i][j];
				}
				if(arr[i][j] > 0 && !visited[i][j]) {
					new_arr[i][j] = arr[i][j];
				}
			}
		}
	}
	else {
		for (int i = 0; i < l; i++) {
			for (int j = 0; j < l; j++) {
				new_arr[i][j] = arr[i][j];
			}
		}
	}
}

void Erase(int num) {
	for(int i = 0; i < l ; i++) {
		for (int j = 0; j < l; j++) {
			if (new_arr[i][j] == num) {
				new_arr[i][j] = 0;
			}
		}
	}
}

void Kill() {

	//함정을 밟았으면.
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			if (new_arr[i][j] > 0 && crr[i][j] == 't') {
				health[new_arr[i][j]]--;
				ans++;
			}
		}
	}

	//만약 health의 숫자가 0이하 일 경우.
	for (int i = 0; i < 31; i++) {
		if (health[i] <= 0 && flag_health[i] == true) {
			Erase(i);
			ans--;
		}
	}
}

void Copy() {
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

void Calc(int num, int dir) {
	//초기화.
	Initial(num);

	//BFS()
	BFS(dir);

	//이동. 벽에 부딪히지 않고 모든 배열이 이동 가능하다면.
	if (Flag_Move(dir)) {
		Move(1, dir);

		//k 에 대한 연산. 함정을 밟았고 그 위치의 숫자의 k 차감.
		//k 가 음수라면, 해당 숫자 배열에서 삭제.
		if (c_flag) {
			Kill();
		}
	}
	else {
		Move(2, dir);
	}

	//Copy();
	Copy();

}

int main() {
	cin >> l >> n >> q;

	//체스 판 만들기.
	for (int i = 0; i < l; i++) {
		for (int j = 0; j < l; j++) {
			int a;
			cin >> a;

			if (a == 0) {
				crr[i][j] = 'f';
			}
			else if (a == 1) {
				crr[i][j] = 't';
			}
			else {
				crr[i][j] = 'w';
			}
		}
	}

	//기사 배치.
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		int r, c, h, w, k;
		cin >> r >> c >> h >> w >> k;
		health[cnt] = k;
		flag_health[cnt] = true;

		r--;
		c--;

		for (int x = r; x < r + h; x++) {
			for (int y = c; y < c + w; y++) {
				arr[x][y] = cnt;
			}
		}

		cnt++;
	}

	//Print();

	while (q--) {
		int num, d;
		cin >> num >> d;
		Calc(num ,d);
	}

	cout << ans;
}