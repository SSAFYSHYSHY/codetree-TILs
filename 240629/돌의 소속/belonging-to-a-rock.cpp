#include <iostream>

using namespace std;

int arr[100001];
int prefix[100001][3];
int n, q;

int main() {
	cin >> n >> q;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= n; i++) {
		if (arr[i] == 1) {
			prefix[i][0] = 1;
		}
		else if (arr[i] == 2) {
			prefix[i][1] = 1;
		}
		else if (arr[i] == 3) {
			prefix[i][2] = 1;
		}

		prefix[i][0] += prefix[i - 1][0];
		prefix[i][1] += prefix[i - 1][1];
		prefix[i][2] += prefix[i - 1][2];
	}

	for (int i = 2; i <= n; i++) {
		prefix[i][0] = prefix[i - 1][0];
		prefix[i][1] = prefix[i - 1][1];
		prefix[i][2] = prefix[i - 1][2];

		if (arr[i] == 1) {
			prefix[i][0] += 1;
		}
		else if (arr[i] == 2) {
			prefix[i][1] += 1;
 		}
		else if (arr[i] == 3) {
			prefix[i][2] += 1;
		}
	}

	for (int i = 0; i < q; i++) {
		int s, e;
		cin >> s >> e;

		int aa = prefix[e][0] - prefix[s - 1][0];
		int bb = prefix[e][1] - prefix[s - 1][1];
		int cc = prefix[e][2] - prefix[s - 1][2];

		cout << aa << " " << bb << " " << cc << "\n";

	}


}