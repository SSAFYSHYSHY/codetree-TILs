#include <iostream>
#define SHIFT_L 1
#define SHIFT_R 0

using namespace std;

int n, m, q;
int arr[101][101];

void Calc2(int num, int swi) {
	//0 은 왼쪽에서 부는 바람.
	if (swi == 0) {
		int temp = arr[num][m];

		for (int i = m; i >= 2; i--) {
			arr[num][i] = arr[num][i - 1];
		}

		arr[num][1] = temp;
	}

	//1은 오른쪽에서 부는 바람.
	else {
		int temp = arr[num][1];

		for (int i = 1; i <= m - 1; i++) {
			arr[num][i] = arr[num][i + 1];
		}

		arr[num][m] = temp;
	}
}

//두 행을 비교해서 똑같은게 나오면 바로 visited 선언하고 반환.
bool Calc(int x, int x1) {
	for (int i = 1; i <= m; i++) {
		if (arr[x][i] == arr[x1][i]) {
			return true;
		}
	}

	return false;
}
  
bool Flip(int dir){
    return (dir == SHIFT_L) ? SHIFT_R : SHIFT_L;
}

void Simul(int a, int dir) {
    Calc2(a, dir);

    dir = Flip(dir);

    for(int i = a, d = dir; i >= 2; i--) {

        if(Calc(i, i - 1)) {
            Calc2(i - 1, d);
            d = Flip(d);
        }

        else
            break;
    }

    for(int i = a, d = dir; i <= n-1; i++) {

        if(Calc(i, i + 1)) {
            Calc2(i + 1, d);
            d = Flip(d);
        }

        else
            break;
    }
}

int main() {
	cin >> n >> m >> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j];
		}
	}

	while(q--) {
        int a;
        char c;
        cin >> a >> c;

        Simul(a, c == 'L' ? SHIFT_R : SHIFT_L);
    }

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
}