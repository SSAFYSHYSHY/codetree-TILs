#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int N, M;
int dp[201][201][201];
vector<int> s;
vector<int> e;
vector<int> v;

void Initial() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				dp[i][j][k] = INT_MIN;
			}
		}
	}
}

int Calc(int m, int n, int a) {
	if (m > M) return 0;
	if (n >= N) return 0;

	if (dp[m][n][a] != INT_MIN) {
		return dp[m][n][a];
	}

	if (s[n] > m || e[n] < m) {
		dp[m][n][a] = Calc(m, n + 1, a);
	}
	else if (a == 200) {
		dp[m][n][a] = max(Calc(m, n + 1, a), Calc(m + 1, 0, n));
	}
	else {
		dp[m][n][a] = max(Calc(m, n + 1, a), Calc(m + 1, 0, n) + abs(v[n] - v[a]));
	}
	return dp[m][n][a];
}

int main() {
	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a, b, c;

		cin >> a >> b >> c;
		s.push_back(a);
		e.push_back(b);
		v.push_back(c);
	}
	Initial();

	Calc(1, 0, 200);

	cout << dp[1][0][200];
}