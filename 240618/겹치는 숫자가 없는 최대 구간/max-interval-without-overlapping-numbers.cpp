#include <iostream>

using namespace std;

int arr[100001];
int cnt[100001] = {};
int n;
int ans = 0;

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}

	int j = 0;
	for (int i = 1; i <= n; i++) {

		while (j + 1 <= n && cnt[arr[j + 1]] != 1) {
			cnt[arr[j+1]]++;
			j++;
		}

		ans = max(ans, j - i + 1);
		cnt[arr[i]]--;
	}

	cout << ans;
}