#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int n, m, k;
char arr[1001][1001];
int prefix[1001][1001][3];

int main() {
	cin >> n >> m >> k;

	for (int i = 1; i <= n; i++) {
		string s;
		cin >> s;
		for (int j = 1; j <= s.length(); j++) {
			arr[i][j] = s[j - 1];
		}
	}

	//초기화 단계.
	for (int i = 1; i <= n; i++) {
		if (arr[i][1] == 'a') {
			prefix[i][1][0] = 1;
		}
		else if (arr[i][1] == 'b') {
			prefix[i][1][1] = 1;
		}
		else if (arr[i][1] == 'c') {
			prefix[i][1][2] = 1;
		}

		prefix[i][1][0] += prefix[i - 1][1][0];
		prefix[i][1][1] += prefix[i - 1][1][1];
		prefix[i][1][2] += prefix[i - 1][1][2];
	}
	//초기화 단계.
	for (int i = 1; i <= m; i++) {
		if (arr[1][i] == 'a') {
			prefix[1][i][0] = 1;
		}
		else if (arr[1][i] == 'b') {
			prefix[1][i][1] = 1;
		}
		else if (arr[1][i] == 'c') {
			prefix[1][i][2] = 1;
		}

		prefix[1][i][0] += prefix[1][i - 1][0];
		prefix[1][i][1] += prefix[1][i - 1][1];
		prefix[1][i][2] += prefix[1][i - 1][2];
	}

	//preifx 연산.
	for (int i = 2; i <= n; i++) {
		for (int j = 2; j <= m; j++) {
			prefix[i][j][0] = prefix[i - 1][j][0] + prefix[i][j - 1][0] - prefix[i - 1][j - 1][0];
			prefix[i][j][1] = prefix[i - 1][j][1] + prefix[i][j - 1][1] - prefix[i - 1][j - 1][1];
			prefix[i][j][2] = prefix[i - 1][j][2] + prefix[i][j - 1][2] - prefix[i - 1][j - 1][2];

			if (arr[i][j] == 'a') {
				prefix[i][j][0] += 1;
			}
			else if (arr[i][j] == 'b') {
				prefix[i][j][1] += 1;
			}
			else if (arr[i][j] == 'c') {
				prefix[i][j][2] += 1;
			}
		}
	}


	//k만큼 명령어.
	int x, y, x2, y2;
	for (int i = 0; i < k; i++) {
		cin >> x >> y >> x2 >> y2;

		int aa = prefix[x2][y2][0] - prefix[x - 1][y2][0] - prefix[x2][y - 1][0] + prefix[x-1][y-1][0];
		int bb = prefix[x2][y2][1] - prefix[x - 1][y2][1] - prefix[x2][y - 1][1] + prefix[x-1][y-1][1];
		int cc = prefix[x2][y2][2] - prefix[x - 1][y2][2] - prefix[x2][y - 1][2] + prefix[x-1][y-1][2];

		cout << aa << " " << bb << " " << cc << "\n";
	}

}