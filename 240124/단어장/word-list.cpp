#include <iostream>
#include <string>
#include <map>

using namespace std;

map<string, int> v;

int n;
string s[100001];

int main() {
	cin >> n;

	for(int i = 0; i < n ; i++) {
		cin >> s[i];

		v[s[i]]++;
	}

	map<string, int>::iterator it;

	for (it = v.begin(); it != v.end(); it++) {
		cout << it->first << " " << it->second << "\n";
	}


}