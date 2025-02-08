#include <iostream>
#include <string>

using namespace std;

long long n;
string s;

long long L[100001];
long long R[100001];
long long ans = 0;

void Input() {
	cin >> n >> s;

	if (s[0] == 'C') {
		L[0] = 1;
	}
	else {
		L[0] = 0;
	}

	if (s[n - 1] == 'W') {
		R[n - 1] = 1;
	}
	else {
		R[n - 1] = 0;
	}
}

int main() {
	Input();

	for (long long i = 1; i < n; i++) {
		L[i] = L[i - 1];
		if (s[i] == 'C') {
			L[i] += 1;
		}
	}

	for (long long i = n - 2; i >= 0; i--) {
		R[i] = R[i + 1];
		if(s[i] == 'W') {
			R[i] += 1;
		}
	}

	for (int i = 1; i < n - 1; i++) {
		if (s[i] == 'O') {
			ans += (R[i] * L[i]);
		}
	}

	cout << ans;
}