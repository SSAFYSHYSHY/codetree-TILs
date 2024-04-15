#include <iostream>
#include <unordered_set>
#include <algorithm>

using namespace std;

int a, b, ans = 0;
int arr[200001];
int brr[200001];

unordered_set<int> s_a;
unordered_set<int> s_b;

int main() {
	cin >> a >> b;

	for (int i = 0; i < a; i++) {
		cin >> arr[i];
		s_a.insert(arr[i]);
	}
	for (int i = 0; i < b; i++) {
		cin >> brr[i];
		s_b.insert(brr[i]);
	}

	for (int i = 0; i < a; i++) {
		if (s_b.find(arr[i]) == s_b.end()) {
			ans++;
		}
	}
	for (int i = 0; i < b; i++) {
		if (s_a.find(brr[i]) == s_a.end()) {
			ans++;
		}
	}

	cout << ans;


}