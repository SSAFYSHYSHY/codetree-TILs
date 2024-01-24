#include <iostream>
#include <string>
#include <map>

using namespace std;

int n;
map<string, int> v;
string s[10001];

int main() {
	cout << fixed;
	cout.precision(4);

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> s[i];
		v[s[i]]++;
	}

	map<string, int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << (it->first ) << " " << (double)((it->second))/n * 100 << "\n";
	}

}