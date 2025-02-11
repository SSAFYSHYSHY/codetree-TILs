#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
pair<int, int> arr[100001];
int visited[200001];
int sum = 0, ans = 0;

void Input() {
	cin >> n;

	for(int i = 0; i < n ; i++) {
		int x, y;
		cin >> x >> y;

		arr[i].first = x;
		arr[i].second = y;
	}
}

int main() {
	Input();

	//+1,-1 연산.
	for (int i = 0; i < n; i++) {
		int x, y;
		tie(x, y) = arr[i];

		visited[x] += 1;
		visited[y] -= 1;
	}

	//i 번째 부터 최대값들을 갱신한다.
	for (int i = 1; i < 200001; i++) {
		sum += visited[i];

		ans = max(sum, ans);

	}

	cout << ans;
}