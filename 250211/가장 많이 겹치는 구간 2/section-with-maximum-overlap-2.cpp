#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
int visited[200001];
pair<int, int> arr[100001];

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		arr[i].first = x;
		arr[i].second = y;
	}
}

int main(){
	Input();

	//각 n만큼 순회해서 +1,-1의 값을 누적.
	for (int i = 0; i < n; i++) {
		int x, y;
		tie(x, y) = arr[i];

		visited[x] += 1;
		visited[y] -= 1;
	}

	int sum = 0, ans = 0;
	for (int i = 1; i < 200001; i++) {
		sum += visited[i];

		ans = max(ans, sum);
	}

	cout << ans;
}
