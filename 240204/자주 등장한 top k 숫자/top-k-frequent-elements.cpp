#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int n, k;
unordered_map<int, int> v;
int arr[100001];
int ans = 0;

//정렬하고자 hashmap의 데이터를 벡터에 대입.

bool cmp(pair<int,int> &a, pair<int,int> &b) {
	if (a.second > b.second) {
		return true;
	}
	else if (a.second == b.second) {
		return a.first > b.first;
	}
	return false;
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		v[arr[i]]++;
	}
	
	vector<pair<int, int>> sorted_v(v.begin(), v.end());
	sort(sorted_v.begin(), sorted_v.end(), cmp);

	for (int i = 0; i < k; i++) {
		cout << sorted_v[i].first << " ";
	}
}