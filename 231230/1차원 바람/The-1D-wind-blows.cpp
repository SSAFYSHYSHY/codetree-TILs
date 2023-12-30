#include <iostream>

using namespace std;

int n, m, q;
int arr[101][101];
int num[101], ord[101];

void Calc2(int num, int swi) {
	//0 은 왼쪽에서 부는 바람.
	if (swi == 0) {
		int temp = arr[num][m-1];

		for (int i = m; i > 0; i--) {
			arr[num][i] = arr[num][i - 1];
		}

		arr[num][0] = temp;
	}

	//1은 오른쪽에서 부는 바람.
	if (swi == 1) {
		int temp = arr[num][0];

		for (int i = 0; i < m - 1; i++) {
			arr[num][i] = arr[num][i + 1];
		}

		arr[num][m - 1] = temp;
	}
}

//두 행을 비교해서 똑같은게 나오면 바로 visited 선언하고 반환.
bool Calc(int x, int x1) {
	for (int i = 0; i < m; i++) {
		if (arr[x][i] == arr[x1][i]) {
			return true;
		}
	}

	return false;
}
  
int main() {
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < q; i++) {
		int a;
		char c;
		cin >> a >> c;

		num[i] = a - 1;

		if (c == 'L') {
			ord[i] = 0;
		}
		else {
			ord[i] = 1;
		}
	}

	for (int t = 0; t < q; t++) {
		
		int a, b;
		a = num[t];
		b = ord[t];

		Calc2(a, b);
		int swi = b;
		int swi2 = b;

		//i 부터 0 까지 찾기.
		for (int i = a ; i > 0; i--) {

			//i, i-1 비교하기.
			if (Calc(i, i - 1)) {
				swi = (swi + 1) % 2;
				
				//cout << swi << " ";

				Calc2(i - 1, swi);
			}
			else {
				continue;
			}
		}

		//i 부터 n 까지 찾기.
		for (int i = a; i < n-1; i++) {

			if (Calc(i, i + 1)) {
				swi2 = (swi2 + 1) % 2;

				//cout << swi2 << " ";

				Calc2(i + 1, swi2);
			}
			else {
				continue;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}