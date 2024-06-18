#include <iostream>

using namespace std;

int arr[100001];
int n, m;

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	int j = 0, sum = 0, cnt = 0;
	for (int i = 0; i < n; i++) {

		while (j < n) {
			if(sum > m) {
                break;
            }
            else if(sum < m){
                sum += arr[j];
                j++;
            }
            else {
                break;
            }
		}

		if (sum == m) {
			cnt++;
		}

		sum -= arr[i];
	}

	cout << cnt;
}