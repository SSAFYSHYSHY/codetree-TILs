#include<iostream>
using namespace std;
long long s;

int main() {
	cin >> s;
	long long sum = 0;
	long long num = 0;

	while (sum < s) {
		num++;
		sum += num;
	}
	if(sum>s)
		cout << num - 1;
	else
		cout << num;

	return 0;
}