#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<long long, int> v;
int n, k;
long long arr[100001];

int main() {
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		long long diff = (long long)k - arr[i];

        cnt += v[diff];

        v[arr[i]]++;
	}
	cout << cnt;
}