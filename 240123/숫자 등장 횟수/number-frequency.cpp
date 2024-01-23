#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

unordered_map<int, int> v;
int n, m;
int arr[100001];
vector<int> v1;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		v[arr[i]]++;
	}

	for (int i = 0; i < m; i++) {
		int a;
		cin >> a;
		v1.push_back(v[a]);
	}

	for (int i = 0; i < v1.size(); i++) {
		cout << v1[i] << " ";
	}
}