#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, ans = 21e8;
int arr[11][11];
bool visited[11];
vector<int> v;

void Calc(int num) {
	//모든 지점 방문 했을때 최소 값 갱신.
	if (num == n) {
		int sum = 0;

		for (int i = 0; i < v.size() - 1; i++) {
			int curr = arr[v[i]][v[i + 1]];

			//현재 값이 0 이면 빠꾸.
			if (curr == 0) return;

			sum += curr;
		}

		//최종 1번 지점으로 돌아오는지.
		int supply_sum = arr[v.back()][0];
		if (supply_sum == 0) return;

		//최소값 갱신.
		ans = min(ans, sum + supply_sum);

		return;

	}

	for (int i = 0; i < n; i++) {
		if (visited[i]) continue;

		visited[i] = true;
		v.push_back(i);

		Calc(num + 1);

		v.pop_back();
		visited[i] = false;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	//1번 지점 부터 탐색 시작.
	visited[0] = true;
	v.push_back(0);
	Calc(1);

	cout << ans;
}