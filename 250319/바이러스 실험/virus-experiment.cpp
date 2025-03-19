#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Node {
	int x, y, age, live;
};

int arr[11][11];
int new_arr[11][11];
vector<Node> v, temp_v;
int n, m, k;

int dx[] = { -1,-1,-1,0,0,1,1,1 };
int dy[] = { -1,0,1,-1,1,-1,0,1 };

bool InRange(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= n;
}

void Input() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = 5;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> new_arr[i][j];
		}
	}

	for (int i = 0; i < m; i++) {
		int x =0 , y = 0, age = 0;
		cin >> x >> y >> age;

		v.push_back({ x, y, age , true});
	}
}

bool cmp(Node a, Node b) {
	return a.age < b.age;
}

void Calc1() {
	sort(v.begin(), v.end(), cmp);
	vector<Node> alive;
	vector<Node> dead;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		int age = v[i].age;
		bool flag = v[i].live;

		//나이보다 같은 크기 이상의 양분이라면
		if (arr[x][y] >= age) {
			arr[x][y] -= age;
			age++;
			alive.push_back({ x,y,age,true });
		}
			//그렇지 못한다면 먹지 못하므로 사망.
		else {
			dead.push_back({ x,y,age,false});
		}
	}

	for (int i = 0; i < dead.size(); i++) {
		arr[dead[i].x][dead[i].y] += (dead[i].age / 2);
	}

	v = alive;
}

void Calc3() {
	vector<Node> v2;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].x;
		int y = v[i].y;
		int age = v[i].age;

		if (age % 5 == 0) {
			for (int k = 0; k < 8; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (InRange(nx, ny)) {
					v2.push_back({ nx,ny,1,true });
				}
			}
		}
	}

	for (int i = 0; i < v2.size(); i++) {
		v.push_back({ v2[i] });
	}
}

void Calc4() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] += new_arr[i][j];
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	Input();

	for (int i = 0; i < k; i++) {
		//바이러스의 크기 만큼 진행, 죽은거 처리.
		//우선 정렬.
		Calc1();

		//8 방향 순회.
		Calc3();

		//+1씩 증가.
		Calc4();


	}

	cout << v.size();
}