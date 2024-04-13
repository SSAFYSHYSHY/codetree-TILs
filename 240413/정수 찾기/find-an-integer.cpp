#include <iostream>
#include <unordered_set>

using namespace std;

int a, b;

int arr[100001];
int brr[100001];

unordered_set<int> v;
unordered_set<int> v1;

int main() {
	cin >> a;

	for (int i = 0; i < a; i++) {
		cin >> arr[i];
		v.insert(arr[i]);
	}

	cin >> b;
	for (int i = 0; i < b; i++) {
		cin >> brr[i];
		v1.insert(brr[i]);
	}

	for (int i = 0; i < b; i++) {
		if (v.find(brr[i]) != v.end()) {
			cout << "1\n";
		}
		else {
			cout << "0\n";
		}
	}
}