#include <iostream>
#include <string>

using namespace std;

int n;
string s;
int ans = 1;

int main() {
	cin >> n;
	cin >> s;

	//i 부터 시작 개수 증가.
	for (int i = 1; i < n; i++) {
		
		bool flag = false;

		//0번째 idx부터 n - i 까지. 개수의 범위 안에 들어가야 함.
		for (int j = 0; j <= n - i; j++) {
			
			// j 합성과 나누어지는 k string.
			for (int k = j+1; k <= n - i; k++) {
				bool flag2 = false;
				
				//두 합을 비교.
				for (int l = 0; l < i; l++) {
					if (s[j + l] != s[k + l]) {
						flag2 = true;
					}
				}

				if (!flag2) flag = true;
			}
		}

		if (flag) {
			ans += 1;
		}
		else {
			break;
		}
	}

	cout << ans;
}