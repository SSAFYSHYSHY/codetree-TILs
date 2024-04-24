#include <iostream>

using namespace std;

int n;
int arr[11] = {0,};
bool visited[11] = { false, };

void Calc(int num, int now) {
	if (now == n) {
		for (int i = 0; i < n - 1; i++) {
			cout << arr[i] << "-";
		}
		cout << arr[n - 1] <<"\n";
		return;
	}

	for (int i = num; i <= 6; i++) {
		visited[i] = true;
		arr[now] = i;
		Calc(i, now + 1);
		visited[i] = false;
	}
}

int main() {
	cin >> n;

	Calc(1, 0);
}