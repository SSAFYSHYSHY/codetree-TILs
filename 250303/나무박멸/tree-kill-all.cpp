#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, k, c, ans_cnt = 0;

int count_manage[21][21];
int arr[21][21];
int div_arr[21][21];
int count_num[21][21];
int new_arr[21][21];
bool visited[21][21];

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int k_dx[] = { -1,-1,1,1 };
int k_dy[] = { -1,1,-1,1 };

void Input() {
	cin >> n >> m >> k >> c;

	memset(visited, false, sizeof(visited));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}
}


void Print() {
	cout << "\n\n";

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n\n";
}


void Manage() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == true && count_manage[i][j] > 0 ) {
				count_manage[i][j]--;
			}

			else if (visited[i][j] == true && count_manage[i][j] == 0) {
				count_manage[i][j] = 0;
				visited[i][j] = false;
				arr[i][j] = 0;
			}
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

void Add() {
	memset(new_arr, 0, sizeof(new_arr));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (InRange(nx, ny)) {
						// 0 이 아닌 이웃의 나무 끼리.
						if (arr[nx][ny] > 0) {
							arr[i][j]++;
						}
						else if (arr[nx][ny] == 0) {
							new_arr[i][j]++;
						}
					}
				}
			}
		}
	}
}

void Div1() {

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			div_arr[i][j] = 0;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {

				for (int k = 0; k < 4; k++) {
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (InRange(nx, ny) && arr[nx][ny] == 0) {

						div_arr[nx][ny] = div_arr[nx][ny] + (arr[i][j] / new_arr[i][j]);
					}

				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] < 0) continue;

			arr[i][j] += div_arr[i][j];
		}
	}
}

int Calc(int x, int y, int k) {
	//대각선으로 이동해서 최대값을 찾기.
	int sum = arr[x][y];

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int nx = x + k_dx[i]*j;
			int ny = y + k_dy[i]*j;

			if (!InRange(nx, ny)) break;
			if (arr[nx][ny] <= 0) break;

			sum += arr[nx][ny];
		}
	}

	return sum;
}

void Calc2(int x, int y, int k) {
	ans_cnt += arr[x][y];
	arr[x][y] = -2;
	count_manage[x][y] = c;
	visited[x][y] = true;

	for (int i = 0; i < 4; i++) {
		for (int j = 1; j <= k; j++) {
			int nx = x + k_dx[i] * j;
			int ny = y + k_dy[i] * j;

			if (!InRange(nx, ny)) break;
			if (arr[nx][ny] < 0) break;

			ans_cnt += arr[nx][ny];
			arr[nx][ny] = -2;
			count_manage[nx][ny] = c;
			visited[nx][ny] = true;
		}
	}
}

void Spray() {
	int find_max = 0;
	int max_x = 0, max_y = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] > 0) {

				//최대값 찾기. 같은 값을 무시해야지 동일한 값이 나오더라도 초기 발견한 
				//i , j의 최소값을 찾을 수 있다.
				//이는 for 문을 완전탐색 기법으로 진행했기 때문에 가능함.
				if (find_max < Calc(i, j, k)) {
					find_max = Calc(i, j, k);
					max_x = i;
					max_y = j;
				}

			}
		}
	}

	//최대값을 응용해 K 만큼 대각선 범위에 대해서 -1을 제외하고 진행.
	//-1을 마주하면 continue;
	//그리고 count_manage[][]에 대해 C 갱신, 기존 배열에대해 -2 로 넣기.
	Calc2(max_x, max_y, k);
	Manage();
}

int main() {
	Input();

	for (int i = 0; i < m; i++) {
		//확장.
		Add();

		//나누기.
		Div1();

		//제초제 뿌리기.
		Spray();
	}

	cout << ans_cnt;
}