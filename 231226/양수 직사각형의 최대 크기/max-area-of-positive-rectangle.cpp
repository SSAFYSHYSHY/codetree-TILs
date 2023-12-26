#include <iostream>
#include <algorithm>

using namespace std;

int n, m;
int arr[21][21];

bool CanGo(int x, int y) {
    return 0 <= x && x < n && 0 <= y && y < m;
}

int Rect(int x1, int y1, int x2, int y2) {
	int sum = 0;
	for (int i = x1; i <= x2; i++) {
		for (int j = y1; j <= y2; j++) {
            //만약 음수 만나면 그냥 0 반환.
			if (arr[i][j] <= 0) return 0;

            //i, j 가 범위값 안에 들어오면.
            if(CanGo(i,j)) {
			    sum += 1;
            }
		}
	}

	return sum;
}

int Calc2(int x1, int y1, int x2, int y2) {
	int sum = 0;

    //
	sum  = Rect(x1, y1, x2, y2);

	return sum;
}

int Calc() {
	int ans = 0;

	//사각형 모양 잡기.
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = i; k < n; k++) {
				for (int l = j; l < m; l++) {
					//잡았으면 양수들 최대값. 없으면 0 반환.
                    ans = max(ans, Calc2(i, j, k, l));
				}
			}
		}
	}

	return ans;
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	int ans = Calc();
    if(ans == 0) {
        cout << -1;
        return 0;
    }

	cout << ans;
}