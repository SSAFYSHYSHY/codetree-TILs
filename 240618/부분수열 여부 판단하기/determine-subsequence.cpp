#include <iostream>

using namespace std;

int arr[100001];
int brr[100001];

int n, m;

bool Calc() {
	int i = 1;
	for (int j = 1; j <= m; j++) {

		while (i <= n && arr[i] != brr[j]) {
			i++;
		}

		if (i == n + 1) {
			return false;
		}
		else {
			i++;
		}
	}

	return true;
}

int main() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	for (int i = 1; i <= m; i++) {
		cin >> brr[i];
	}

	if (Calc()) {
		cout << "Yes";
	}
	else {
		cout << "No";
	}
}