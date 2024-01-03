#include <iostream>

using namespace std;

int n, m, k;
int arr[101][101];
int temp[101][101];

void Copy() {
	//떨어트리기.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
		}
	}

	for (int j = 0; j < n; j++) {
		int cnt = n - 1;

		for (int i = n - 1; i >= 0; i--) {
			if (arr[i][j] > 0) {
				temp[cnt][j] = arr[i][j];
				cnt--;
			}
		}
	}

	//arr에 복사.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

void Calc(int num) {
	//폭탄 연산.
	//각 j 0 부터 시작해서 i n-1 ~ 0 까지 비교.

	for (int j = 0; j < n; j++) {
		//같은 영역을 다 0 처리 해줘야 함. 그 같은 영역의 좌표.
		int x = 0;
		int y = 0;

		for (int i = n - 1; i > 0; i--) {
			int a = arr[i][j];
			int same = 1;

			for (int k = i - 1; k >= 0; k--) {
				if (arr[k][j] == a && arr[k][j] != 0) {
					same++;
				}
				else {
					break;
				}

			}

			if (same >= m) {
				x = i;
				y = x - same + 1;

				for (int l = y; l <= x; l++) {
					arr[l][j] = 0;
				}
			}
		}

	}

}

void Calc2() {
	//회전.
	//시계 방향 90도 회전.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			temp[i][j] = arr[n - j - 1][i];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			arr[i][j] = temp[i][j];
		}
	}


}

int main() {
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	if(n == 1 && m > 1) {
		cout << 1;
		return 0;
	}
	if(n == 1 && m == 1) {
		cout << 0;
		return 0;
	}

	for (int i = 0; i < k; i++) {
		//폭탄 연산
		Calc(m);

		//복사
		Copy();

		//회전
		Calc2();

		//복사
		Copy();

		Calc(m);
	}

	int cnt = 0;
	
	//cout << "\n";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//cout << arr[i][j] << " ";
			
			if (arr[i][j]) {
				cnt++;
			}
		}
		//cout << "\n";
	}

	cout << cnt;
}