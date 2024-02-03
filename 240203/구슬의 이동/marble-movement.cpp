#include <iostream>
#include <tuple>
#include <algorithm>
#include <vector>

using namespace std;

int arr_cnt[51][51];
typedef tuple<int, int, int, int> ball;

// U R L D
int dx[] = {-1,0,0,1};
int dy[] = {0,1,-1,0};
int dirc[128];

vector<ball> temp_v;
vector<ball> v;

int n, m, t, k;

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

ball Move(ball b) {
	int x, y, dir, velo;
	tie(x, y, dir, velo) = b;

	//velo 만큼 이동.
	for (int i = 0; i < velo; i++) {
		//가고자 하는 방향.
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		//벽이 있는지 판단. 없으면 앞으로.
		if(InRange(nx, ny)) {
			x = nx;
			y = ny;
		}
		else {
			//0,3 1,2 대칭 이동.
			dir = 3 - dir;
			i--;
		}
	}

	return make_tuple(x, y, dir, velo);
}

void MoveAll() {
	for (int i = 0; i < v.size(); i++) {
		v[i] = Move(v[i]);
	}
}

//해당 구슬과 충돌이 일어난 구슬이 있는지 확인. k 개 미만인지 확인.
bool Calc2(int target_idx) {
	int tar_x, tar_y;
	tie(tar_x, tar_y, ignore, ignore) = v[target_idx];

	return arr_cnt[tar_x][tar_y] >= k;
}

///// 1. 우선순위에 따른 구슬의 생존, 나머지는 삭제.
///////1.1 구슬의 속도가 가장 빠른 것부터 우선순위가 높음.
///////1.2 구슬의 속도가 일치하면, 구슬의 번호가 더 큰 구슬의 우선순위가 높음.

void Calc3(int x, int y) {
	bool flag[62] = { false, };
	//k 만큼 반복, 우선 순위를 찾아 새로 삽입.
	for (int i = 0; i < k; i++) {
		int ans = 0;
		int idx = 0;

		//해당 위치한 배열들.
		for (int j = 0; j < v.size(); j++) {
			int x, y, velo;
			tie(x, y, ignore, velo) = v[j];

			//해당 벡터가 일치하는 좌표이고 방문도 하지 않았어야 함..
			if (x == x && y == y && flag[j] == false) {
				if (velo > ans) {
					ans = velo;
					idx = j;
				}
				else if (velo >= ans && j > idx) {
					ans = velo;
					idx = j;
				}
				temp_v.push_back(v[j]);
				flag[j] = true;
				break;
			}
			else continue;
		}
	}
}

//충돌이 일어난 구슬.
void Calc() {
	temp_v.clear();

	//각 위치에 대한 수 증가.
	for (int i = 0; i < v.size(); i++) {
		int x, y;
		tie(x, y, ignore, ignore) = v[i];

		arr_cnt[x][y]++;
	}

	//충돌에 대한 구슬 기록.
	for (int i = 0; i < v.size(); i++) {
		//충돌이 일어나지 않은 구역.
		if (!Calc2(i)) {
			temp_v.push_back(v[i]);
		}
		//충돌이 일어난 구역.
		///// 1. 우선순위에 따른 구슬의 생존, 나머지는 삭제.
		///////1.1 구슬의 속도가 가장 빠른 것부터 우선순위가 높음.
		///////1.2 구슬의 속도가 일치하면, 구슬의 번호가 더 큰 구슬의 우선순위가 높음.
		else {
			//해당 배열칸을 연산.
			int tar_x, tar_y;
			tie(tar_x, tar_y, ignore, ignore) = v[i];

			Calc3(tar_x, tar_y);
		}
	}

	//각 구슬의 위치가 적어놓은 count 수를 초기화.
	for (int i = 0; i < v.size(); i++) {
		int x, y;
		tie(x, y, ignore, ignore) = v[i];

		arr_cnt[x][y]--;
	}

	//연산한 것들을 다시 채워줌.
	v = temp_v;
}

void Simul() {
	//v 크기 만큼 Move() 함수.
	MoveAll();


	//충돌이 일어나는 구슬에 대한 연산
	Calc();
}

int main() {
	cin >> n >> m >> t >> k;

	dirc['U'] = 0;
	dirc['R'] = 1;
	dirc['L'] = 2;
	dirc['D'] = 3;

	for (int i = 0; i < m; i++) {
		int x, y, velo;
		char d;

		cin >> x >> y >> d >> velo;

		v.push_back(make_tuple(x,y, dirc[d], velo));
	}

	//t 만큼 시뮬을 반복.
	while (t--) {
		Simul();
	}

	cout << v.size() << "\n";
}