#include <iostream>
#include <unordered_map>

using namespace std;

int n, ans = 0;
int A[5001], B[5001], C[5001], D[5001];
unordered_map<int, int> v;

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> B[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> C[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> D[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			v[A[i] + B[j]]++;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int sub = -C[i] - D[j];
			if (v.count(sub) > 0) {
				ans += v[sub];
			}
		}
	}

	cout << ans;
}