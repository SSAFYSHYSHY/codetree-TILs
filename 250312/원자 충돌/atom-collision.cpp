#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

struct Node {
	int x, y, m, s, d;
};

int arr[51][51];
int new_arr[51][51];
vector<Node> v;

int dx[] = {-1,-1,0,1,1,1,0,-1};
int dy[] = {0,1,1,1,0,-1,-1,-1};
int ans = 0;
int n, m, k;

void Print() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

void Input() {
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++) {
		int x, y, m, s, d;
		cin >> x >> y >> m >> s >> d;

		v.push_back({ x,y,m,s,d });
	}
}

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void Move() {
	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		int m = v[i].m;
		int s = v[i].s;
		int d = v[i].d;

		if (x == -1 && y == -1) continue;

		for (int j = 0; j < s; j++) {
			x += dx[d];
			y += dy[d];


			if (!InRange(x, y)) {
				if (x <= 0) {
					x = n;
				}
				else if (x > n) {
					x = 1;
				}

				if (y <= 0) {
					y = n;
				}
				else if (y > n) {
					y = 1;
				}
			}

		}

		arr[x][y]++;
		v[i] = { x, y, m, s,d };
	}
}

void Check(int c_x, int c_y) {
	int sum_m = 0;
	int sum_v = 0;
	//방향에 따라 
	int num = arr[c_x][c_y];
	int ol = 0, tl = 0;

	for (int i = 0; i < v.size(); i++) {
		if (v[i].x == -1 && v[i].y == -1) {
			continue;
		}

		if (v[i].x == c_x && v[i].y == c_y) {
			sum_m += v[i].m;
			sum_v += v[i].s;
			int dir = v[i].d;

			if (dir % 2 == 0) {
				ol++;
			}
			else {
				tl++;
			}

			//합쳐진 원자는 더 이상 사용하지 않음.
			v[i].x = -1;
			v[i].y = -1;
		}
	}

	//합쳐진 합의 나눔과 속도를 나눔. 이후 4 방향따라 나눠야 함.
	sum_m /= 5;
	sum_v /= arr[c_x][c_y];

	//0 이면 고려 안함.
	if (sum_m == 0) {
		return;
	}
	//아니면 4 방향에 따라 나눔.
	else {
		//만약 방향이 안바뀌어서 그대로면.
		if (ol == arr[c_x][c_y] || tl == arr[c_x][c_y]) {
			v.push_back({ c_x,c_y,sum_m,sum_v, 0 });
			v.push_back({ c_x,c_y,sum_m,sum_v, 2 });
			v.push_back({ c_x,c_y,sum_m,sum_v, 4 });
			v.push_back({ c_x,c_y,sum_m,sum_v, 6 });
		}
		//방향이 바뀌어서 대각선을 고려.
		else {
			v.push_back({ c_x,c_y,sum_m,sum_v, 1 });
			v.push_back({ c_x,c_y,sum_m,sum_v, 3 });
			v.push_back({ c_x,c_y,sum_m,sum_v, 5 });
			v.push_back({ c_x,c_y,sum_m,sum_v, 7 });
		}
	}

}

int main() {
	Input();

	for (int t = 0; t < k; t++) {
		//각 바이러스별로 일단 이동.
		memset(arr, 0, sizeof(arr));
		Move();
		//Print();

		//2 이상인 배열에 한해서 체크 검정.
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (arr[i][j] > 1) {
					Check(i, j);
				}
			}
		}

		//break;
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i].x == -1 && v[i].y == -1) continue;

		ans += v[i].m;
	}

	cout << ans;
}