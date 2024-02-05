#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


int n;
unordered_map<int, vector<int>> v;

int main(){
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;

		v[x].push_back(y);
	}

	long long sum = 0;
	for (auto it = v.begin(); it != v.end(); it++) {
		vector<int> v1 = it->second;
		
		sort(v1.begin(), v1.end());

		sum += v1[0];
	}


	cout << sum;
}