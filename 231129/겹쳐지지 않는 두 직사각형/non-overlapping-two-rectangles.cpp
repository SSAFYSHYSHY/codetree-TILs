#include <iostream>

using namespace std;

int arr[6][6];
int board[6][6];
int n, m;

//1.입력
//2.첫번째 직사각형
//	2.1 두번째 직사각형
//		2.1.1 두 직사각형 간의 겹치지 않은 영역이면
//			2.1.1.1 보드 초기화
//			2.1.1.2 두 직사각형 좌표 그리기
//			2.1.1.3 cnt >=2 이상 True 반환
//		2.1.2 두 직사각형 합의 반환
//	2.2 합 반환.
//3. 합반환.

void Board() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			board[i][j] = 0;
		}
	}
}

void Rect(int x, int y, int x1, int y1) {
	for (int i = x; i <= x1; i++) {
		for (int j = y; j <= y1; j++) {
			board[i][j]++;
		}
	}
}

bool Check() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] >= 2) {
				return true;
			}
		}
	}

	return false;
}

bool Calc2(int x, int y, int x1, int y1, int x2, int y2, int x3, int y3) {
	Board();
	Rect(x, y, x1, y1);
	Rect(x2, y2, x3, y3);
	return Check();
}

int Rect1(int a, int b, int c, int d) {
	int sum = 0;
	
	for (int i = a; i <= c; i++) {
		for (int j = b; j <= d; j++) {
			sum += arr[i][j];
		}
	}

	return sum;
}

//두 직사
int Calc(int x, int y, int x1, int y1) {
	int sum = -21e8;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < m; l++) {
					if (!Calc2(x, y, x1, y1, i, j, k, l)) {
						sum = max(sum, Rect1(x, y, x1, y1) + Rect1(i,j,k,l));
					}
				}
			}
		}
	}

	return sum;
}

//첫 직사
int Calc() {
	int sum = -21e8;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < m; l++) {
					sum = max(sum, Calc(i, j, k, l));
				}
			}
		}
	}

	return sum;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = Calc();

	cout << ans;

	return 0;
}