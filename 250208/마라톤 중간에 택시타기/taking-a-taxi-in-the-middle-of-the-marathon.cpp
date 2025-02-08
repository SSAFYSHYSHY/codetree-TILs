#include <iostream>
#include <vector>

using namespace std;

int n;
int R[100001];
int L[100001];

struct Node {
	int x, y;
};

vector<Node> v;

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v.push_back({ x,y });
	}
}

int Dist(Node a , Node b) {
	return abs(a.x - b.x) + abs(a.y - b.y);
}

int main() {
	Input();

	L[1] = 0;
	for (int i = 1; i < n; i++) {
		L[i] = L[i - 1] + Dist(v[i-1], v[i]);
	}

	R[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		R[i] = R[i + 1] + Dist(v[i] , v[i + 1]);
	}

	int mini = 21e7;
	for (int i = 1; i < n - 1; i++) {
		mini = min(mini, L[i - 1] + R[i + 1] + Dist(v[i - 1], v[i + 1]));
	}

	cout << mini;
}