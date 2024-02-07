#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

char arr[6][6];
int n;
int max_ans = INT_MIN, min_ans = INT_MAX;
vector<char> v;
bool visited[6][6] = { false, };
int dx[] = { 1,0 };
int dy[] = { 0,1 };

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

int Calc2() {
	int sum = (v[0] - '0');

	for (int i = 2; i < v.size(); i+=2) {
		if (v[i - 1] == '+') {
			sum = sum + (v[i] - '0');
		}
		else if (v[i - 1] == '-') {
			sum = sum - (v[i] - '0');
		}
		else if (v[i - 1] == 'x') {
			sum = sum * (v[i] - '0');
		}
	}
	return sum;
}

void Calc(int x, int y) {
	if (x == n - 1 && y == n - 1) {
		max_ans = max(max_ans, Calc2());
		min_ans = min(min_ans, Calc2());
		return;
	}

	for (int i = 0; i < 2; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (InRange(nx, ny) && !visited[nx][ny]) {
			v.push_back(arr[nx][ny]);
			visited[nx][ny] = true;
			Calc(nx, ny);
			visited[nx][ny] = false;
			v.pop_back();
		}
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	v.push_back(arr[0][0]);
	visited[0][0] = true;
	Calc(0, 0);

	cout << max_ans << " " << min_ans;
}