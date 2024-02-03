#include <iostream>
#include <tuple>
#include <vector>

using namespace std;

int n, m, t;
int arr[51][51];
int new_arr[51][51];
typedef tuple<int, int, int, int, int> ball;
//idx , x,y,w,dir;
vector<ball> v;
vector<ball> temp_v;

int dx[] = { -1,0,0,1 };
int dy[] = { 0,-1,1,0 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

ball MoveAll(ball b) {
	int idx, x, y, dir, w;

	
	tie(idx, x, y, dir, w) = b;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	//범위 안에 있는 경우. 이동.
	if (InRange(nx, ny)) {
		x = nx;
		y = ny;
	}
	else {
		dir = 3 - dir;
	}

	return make_tuple(idx, x, y, dir, w);
}

void Move() {
	for (int i = 0; i < v.size(); i++) {
		v[i] = MoveAll(v[i]);
	}
}

void Calc2(int x, int y) {
	int vx, vy, w, dir, idx;
	int w_sum = 0;
	int idx_sum = 0;
	int dir_sum = 0;

	//배열의 크기 만큼 순환을 하고 같은 위치에 대해서 값의 누적과 방향을 설정해줌.
	for (int i = 0; i < v.size(); i++) {
		tie(idx, vx, vy, dir, w) = v[i];

		if (vx == x && vy == y) {
			
			w_sum += w;

			if (idx > idx_sum) {
				idx_sum = idx;
				dir_sum = dir;
			}
		}
	}

	temp_v.push_back(make_tuple(idx_sum, x, y, dir_sum, w_sum));

}

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = 0;
		}
	}
	temp_v.clear();
}

void Calc() {
	Initial();

	//위치 연산.
	for (int i = 0; i < v.size(); i++) {
		int x, y;
		tie(ignore, x, y, ignore, ignore) = v[i];

		arr[x][y]++;
	}

	//위치에 대한 값들이 이상일때. 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j]) {
				Calc2(i,j);
			}
		}
	}

	v = temp_v;
}

void Simul() {
	//모조리 이동.
	Move();

	//충돌시 조건.
	Calc();
}

int main() {
	cin >> n >> m >> t;

	int dirc[128];
	dirc['U'] = 0;
	dirc['L'] = 1;
	dirc['R'] = 2;
	dirc['D'] = 3;


	for (int i = 0; i < m; i++) {
		int x, y, w;
		char dir;
		cin >> x >> y >> dir >> w;
		x -= 1;
		y -= 1;

		v.push_back(make_tuple(i+1, x, y, dirc[dir], w));
	}

	while (t--) {
		Simul();

		/*for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << arr[i][j] << " ";
			}
			cout << "\n";
		}
		cout << "\n";*/

	}

	int ans = 0, w_ans = 0;

	for (int i = 0; i < v.size(); i++) {
		tie(ignore, ignore, ignore, ignore, w_ans) = v[i];

		if (w_ans > ans) {
			ans = w_ans;
		}
	}

	cout << v.size() << " " << ans;
}