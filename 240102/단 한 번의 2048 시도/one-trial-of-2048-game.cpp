#include <iostream>

using namespace std;

int arr[4][4];
int temp[4][4];

void Calc2(int num) {
	//같은 숫자끼리만 처리해준다. 이동은 아직 아님.
	//왼쪽에서 밀어주는 배열.
	//j 의 끝행부터 터트려야 함. j = n - 1으로 고정.
	if (num == 1) {

		//temp 배열 작성.
		for (int i = 0; i < 4; i++) {
			for (int j = 3; j >= 0; j--) {
				int a = arr[i][j];
				for (int k = j - 1; k >= 0; k--) {
					if (arr[i][k] == 0) {
						continue;
					}
					else if (arr[i][k] == a) {
						arr[i][j] = arr[i][j] + arr[i][k];
						arr[i][k] = 0;
						break;
					}
					else if (arr[i][k] != a) {
						break;
					}
				}
			}
		}


		//왼쪽 이동 함수. 0을 만나면 모조리 이동.
		for (int i = 0; i < 4; i++) {
			int cnt = 3;
			for (int j = 3; j >= 0; j--) {
				if (arr[i][j]) {
					temp[i][cnt] = arr[i][j];
					cnt--;
				}
			}
		}
	}

	//왼쪽에서 밀어주는 배열.
	//j 의 첫 행부터 터트려야 함. j = 0 으로 고정.
	else if (num == 2) {
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int a = arr[i][j];
				for (int k = j + 1; k < 4; k++) {
					if (arr[i][k] == 0) {
						continue;
					}
					else if (arr[i][k] == a) {
						arr[i][j] = arr[i][j] + arr[i][k];
						arr[i][k] = 0;
						break;
					}
					else if (arr[i][k] != a) {
						break;
					}
				}
			}
		}

		//오른쪽 이동 함수. 0을 만나면 모조리 이동.
		for (int i = 0; i < 4; i++) {
			int cnt = 0;
			for (int j = 0; j <= 3; j++) {
				if (arr[i][j]) {
					temp[i][cnt] = arr[i][j];
					cnt++;
				}
			}
		}
	}

	//위쪽에서 밀어주는 배열.
	//x 의 끝행부터 터트려야 함. i = n-1 로 고정.
	else if (num == 3) {
		for (int j = 0; j < 4; j++) {
			for (int i = 3; i >= 0; i--) {
				int a = arr[i][j];
				for (int k = i - 1; k >= 0; k--) {
					if (arr[k][j] == 0) {
						continue;
					}
					else if (arr[k][j] == a) {
						arr[i][j] = arr[k][j] + arr[i][j];
						arr[k][j] = 0;
						break;
					}
					else if (arr[k][j] != a) {
						break;
					}
				}
			}
		}

		//위쪽 이동 함수. 0을 만나면 모조리 이동.
		for (int j = 0; j < 4; j++) {
			int cnt = 3;
			for (int i = 3; i >= 0; i--) {
				if (arr[i][j]) {
					temp[cnt][j] = arr[i][j];
					cnt--;
				}
			}
		}
	}

	//아래쪽에서 밀어주는 배열.
	//x의 시작부터 터트려야함. i = 0 으로 고정.
	else if (num == 4) {
		for (int j = 0; j < 4; j++) {
			for (int i = 0; i < 4; i++) {
				int a = arr[i][j];
				for (int k = i + 1; k < 4; k++) {
					if (arr[k][j] == 0) {
						continue;
					}
					else if (arr[k][j] == a) {
						arr[i][j] = arr[k][j] + arr[i][j];
						arr[k][j] = 0;
						break;
					}
					else if (arr[k][j] != a) {
						break;
					}
				}
			}
		}

		//아래쪽 이동 함수. 0을 만나면 모조리 이동.
		for (int j = 0; j < 4; j++) {
			int cnt = 0;
			for (int i = 0; i <= 3; i++) {
				if (arr[i][j]) {
					temp[cnt][j] = arr[i][j];
					cnt++;
				}
			}
		}
	}
}

void Calc(char dir) {

	//방향에 따른 배열 함수.
	if (dir == 'R') {
		Calc2(1);
	}
	else if (dir == 'L') {
		Calc2(2);
	}
	else if (dir == 'D') {
		Calc2(3);
	}
	else if (dir == 'U') {
		Calc2(4);
	}

	//연산된 temp에 arr 복사.
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			arr[i][j] = temp[i][j];
		}
	}
}

int main() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cin >> arr[i][j];
		}
	}
	char dir;
	cin >> dir;

	Calc(dir);

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}

}