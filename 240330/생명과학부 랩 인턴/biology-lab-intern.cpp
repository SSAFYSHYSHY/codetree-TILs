#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

int n, m, k, ans = 0;

queue<tuple<int,int,int>> virus[101][101];

//위, 아래, 오, 왼
// 1, 2, 3, 4
int dx[] = {0,-1,1,0,0};
int dy[] = {0,0,0,1,-1};

int arr[101][101] = { 0, };
int new_arr[101][101] = { 0, };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

void Print(){
	cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
 		}
		cout << "\n";
	}
	cout << "\n";
}

void Calc2(int x, int y) {

	arr[x][y] = 0;

	//이동 거리, 방향
	int s, d, b;

	tie(s,d, b) = virus[x][y].front();
	virus[x][y].pop();

	for (int i = 0; i < s; i++) {
		int nx = x + dx[d];
		int ny = y + dy[d];

		if (InRange(nx, ny)) {
			x = nx;
			y = ny;
		}
		else {
			if (d == 1) {
				d = 2;
				x = x + dx[d];
				y = y + dy[d];
			}
			else if(d == 2){
				d = 1;
				x = x + dx[d];
				y = y + dy[d];
			}
			else if (d == 3) {
				d = 4;
				x = x + dx[d];
				y = y + dy[d];
			}
			else if (d == 4) {
				d = 3;
				x = x + dx[d];
				y = y + dy[d];
			}
		}
	}

	new_arr[x][y] = 1;
	virus[x][y].push(make_tuple(s, d, b));
}

void Add(int x, int y) {
	int s, d, b;
	tie(s, d, b) = virus[x][y].front();
	virus[x][y].pop();

	int a_s, a_d, a_b;

	while(!virus[x][y].empty()) {
		tie(a_s, a_d, a_b) = virus[x][y].front();
		virus[x][y].pop();

		if (a_b > b) {
			b = a_b;
			s = a_s;
			d = a_d;
		}
	}

	virus[x][y].push(make_tuple(s, d, b));
}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			new_arr[i][j] = 0;
		}
	}
}

void Copy() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

void Calc(int num) {
	//초기화.
	Initial();

	//플레이어 탐색.
	for (int i = 0; i < n; i++) {
		
		if (virus[i][num].size() != 0) {
			int score;
			tie(ignore, ignore, score) = virus[i][num].front();
			virus[i][num].pop();
			arr[i][num] = 0;
			ans += score;
			break;
		}
	}

	//잔류 바이러스 이동.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j].size() > 0 && arr[i][j] == 1) {
				Calc2(i, j);
			}
		}
	}

	//칸에 2칸 이상이면 합병.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (virus[i][j].size() > 1) {
				Add(i, j);
			}
		}
	}

	Copy();
}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int x, y, s, d, b;

		cin >> x >> y >> s >> d >> b;
		x -= 1;
		y -= 1;
		arr[x][y] = 1;

		virus[x][y].push(make_tuple(s, d, b));
	}

	//시뮬 시작.
	for (int i = 0; i < m; i++) {
		
		Calc(i);

		//Print();
	}

	cout << ans;
}