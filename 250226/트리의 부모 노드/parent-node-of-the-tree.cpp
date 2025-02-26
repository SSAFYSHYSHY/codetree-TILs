#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int arr[100001];
vector<int> v[100001];
bool visited[100001] = { false, };
int n;

void Input() {
	cin >> n;

	for (int i = 0; i < n - 1; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
		v[y].push_back(x);
	}

	visited[1] = true;
}

void DFS(int num) {

	for (int i = 0; i < v[num].size(); i++) {
		int y = v[num][i];

		if (!visited[y]) {
			visited[y] = true;
			arr[y] = num;
			DFS(y);
		}
	}
}


int main() {
	Input();

	DFS(1);

	for (int i = 2; i < n; i++) {
		cout << arr[i] << "\n";
	}
}