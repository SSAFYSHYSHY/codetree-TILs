#include <iostream>

using namespace std;

int n;
int arr[101];

int Calc(int h) {
	int temp[101] = {0,};
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		temp[i] = arr[i];
		temp[i] -= h;
	}

	bool flag = false;
	for (int i = 0; i < n; i++) {
		if (temp[i] > 0 && flag == false) {
			cnt++;
			flag = true;
		}
		else if(temp[i] <= 0) {
			flag = false;
		}
	}
	return cnt;

}
 
int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int ans = 0;
	for (int t = 1; t <= 100; t++) {
		int cnt = 0;

		cnt = Calc(t);

		ans = max(cnt, ans);
	}

	cout << ans;
}