#include <iostream>
#include <string>

using namespace std;

int arr[1001][1001];
int n, k;
int x, y, dir;

int dx[] = { 1, 0 , -1, 0 };
int dy[] = { 0,-1, 0,1 };

void Calc(int num) {
	if (num <= n) {
		x = 0;
		y = num - 1;
		dir = 0;
	}
	else if (num <= n * 2) {
		x = num - n - 1;
		y = n - 1;
		dir = 1;
	}
	else if (num <= n * 3) {
		x = n - 1;
		y = n - (num - 2 * n);
		dir = 2;
	}
	else{
		x = n - (num - 3 * n);
		y = 0;
		dir = 3;
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Move(int nd) {
	x += dx[nd];
	y += dy[nd];
	dir = nd;
}
 

int Calc2() {
	int num = 0;

	while (InRange(x, y)) {
		if (arr[x][y] == 0) {
			Move(dir ^ 1);
		}
		else {
			Move(3 - dir);
		}

		num += 1;
	}

	return num;
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++) {
			if (s[j] == '/') {
				arr[i][j] = 0;
			}
			else {
				arr[i][j] = 1;
			}
		}
	}
	cin >> k;

	Calc(k);

	int ans = Calc2();

	cout << ans;
}