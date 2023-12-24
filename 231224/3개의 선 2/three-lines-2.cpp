#include <iostream>

using namespace std;

int n;
int x[21], y[21];

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}

	int ans = 0;
	for (int i = 0; i <= 10; i++) {
		for (int j = 0; j <= 10; j++) {
			for (int k = 0; k <= 10; k++) {

				bool flag = false;

				for (int l = 0; l < n; l++) {
					//조건 1.
					if (x[l] == i || x[l] == j || x[l] == k) {
						continue;
					}

					flag = true;
				}

				if (!flag) {
					ans = 1;
				}


				flag = false;
				for (int l = 0; l < n; l++) {
					//조건 2.
					if (x[l] == i || x[l] == j || y[l] == k) {
						continue;
					}

					flag = true;
				}

				if (!flag) {
					ans = 1;
				}

				flag = false;
				for (int l = 0; l < n; l++) {
					//조건 3.
					if (x[l] == i || y[l] == j || y[l] == k) {
						continue;
					}

					flag = true;
				}

				if (!flag) {
					ans = 1;
				}

				flag = false;
				for (int l = 0; l < n; l++) {
					//조건 4.
					if (y[l] == i || y[l] == j || y[l] == k) {
						continue;
					}

					flag = true;
				}

				if (!flag) {
					ans = 1;
				}

			}
		}
	}

	cout << ans;
}