#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>

using namespace std;

int r, c, k, n = 0 , m = 0;
int arr[202][202];
int new_arr[202][202];
int cnt_arr[101] = {0,};

struct Node {
	int x, cnt;
};
vector<Node> v;

void Input() {
	cin >> r >> c >> k;

	for (int i = 1; i <= 3; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> arr[i][j];
		}
	}
}

void Find() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (arr[i][j] > 0) {
				n = max(n, i);
				m = max(m, j);
			}
		}
	}
}

bool cmp(Node a, Node b) {
	if (a.cnt != b.cnt) return a.cnt < b.cnt;
	return a.x < b.x;
}

void Calc1() {
	//행으로 연산.
	memset(new_arr, 0, sizeof(new_arr));

	for (int i = 1; i <= 100; i++) {
		//각 행에 대해서 0보다 크면.
			//각 수의 개수들을 누적함.
			for (int j = 1; j <= 100; j++) {
				cnt_arr[arr[i][j]]++;
			}

			//각 수의 누적된 개수들을 vector에 누적.
			for (int j = 1; j <= 100; j++) {
				if (cnt_arr[j]) {
					v.push_back({ j, cnt_arr[j] });
				}
			}

			//정렬.
			sort(v.begin(), v.end(), cmp);

			//new_arr배열에 넣기.
			int k = 1;
			for (int j = 0; j < v.size(); j++) {
				int x = v[j].x;
				int x_cnt = v[j].cnt;

				new_arr[i][k] = x;
				new_arr[i][k + 1] = x_cnt;
				k += 2;
			}

			v.clear();
			memset(cnt_arr, 0, sizeof(cnt_arr));
	}

}

void Calc2() {
	memset(new_arr, 0, sizeof(new_arr));

	for (int j = 1; j <= 100; j++) {
		//각 열에 대해서 0보다 크면.
			//각 수의 개수들을 누적함.
			for (int i = 1; i <= 100; i++) {
				cnt_arr[arr[i][j]]++;
			}

			//각 수의 누적된 개수들을 vector에 누적.
			for (int i = 1; i <= 100; i++) {
				if (cnt_arr[i]) {
					v.push_back({ i, cnt_arr[i] });
				}
			}

			//정렬.
			sort(v.begin(), v.end(), cmp);

			//new_arr배열에 넣기.
			int k = 1;
			for (int i = 0; i < v.size(); i++) {
				int x = v[i].x;
				int x_cnt = v[i].cnt;

				new_arr[k][j] = x;
				new_arr[k + 1][j] = x_cnt;
				k += 2;
			}

			v.clear();
			memset(cnt_arr, 0, sizeof(cnt_arr));
	}
}

void Copy() {
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			arr[i][j] = new_arr[i][j];
		}
	}
}

void Print() {
	cout << "\n\n";

	for (int i = 1; i <= 10; i++) {
		for (int j = 1; j <= 10; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}

int main() {
	Input();

	for (int i = 1; i <= 100; i++) {
		//일치시.
		if (arr[r][c] == k) {
			cout << i - 1;
			return 0;
		}

		//시뮬 가장 큰 행과 열을 가져옴.
		//Print();
		Find();

		//큰행과 큰열을 서로 비교 
		//행이 크거나 같은 경우.
		if (n >= m) {
			Calc1();
		}
		//열이 큰 경우.
		else {
			Calc2();
		}

		Copy();

		//Print();
	}

	cout << -1;
}