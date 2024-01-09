#include <iostream>
#include <vector>

using namespace std;

int n, ans = 0;
int arr[11][11];
bool visited[11];
vector<int> v;

int Calc2(){
	int sum = 21e8;

	for (int i = 0; i < v.size(); i++) {
		sum = min(sum, v[i]);
	}

	return sum;
}

void Calc(int num) {
	if (num == n) {

		ans = max(ans, Calc2());

		return;
	}

	for (int i = 0; i < n; i++) {
		if (visited[i] == true) continue;

		visited[i] = true;
		v.push_back(arr[num][i]);

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
	Calc(0);

	cout << ans;
}