#include <iostream>
#include <tuple>
#include <queue>

using namespace std;

int n, ans_cnt = 0, cnt = 0, robot_level = 2;
int arr[21][21];
int new_arr[21][21];
bool visited[21][21];

queue<pair<int, int>> q;
pair<int, int> robot_pos;

void Initial() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			visited[i][j] = false;
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < n;
}

bool CanGo(int x, int y) {
	return InRange(x, y) && !visited[x][y] && arr[x][y] <= robot_level;
}

void BFS() {
	int dx[] = { 1, 0, -1,0 };
	int dy[] = { 0, 1, 0,-1 };

	while (!q.empty()) {
		pair<int, int> curr = q.front();
		int curr_x, curr_y;
		tie(curr_x, curr_y) = curr;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = curr_x + dx[i];
			int ny = curr_y + dy[i];

			//방문이 가능하다면.
			if (CanGo(nx, ny)) {
				q.push(make_pair(nx, ny));
				new_arr[nx][ny] = new_arr[curr_x][curr_y] + 1;
				visited[nx][ny] = true;
			}
		}
	}
}

bool Calc2(pair<int,int> best, pair<int,int> now) {
	//굳이 돌 필요가 없다면.
	if (best == make_pair(-1, -1)) return true;

	int best_x, best_y;
	tie(best_x, best_y) = best;

	int now_x, now_y;
	tie(now_x, now_y) = now;

	//best와 now의 우선순위를 비교해서 배열값, x , y 순 비교.
	return make_tuple(new_arr[best_x][best_y], best_x, best_y) >
		make_tuple(new_arr[now_x][now_y], now_x, now_y);
}

bool Calc() {
	//visited 초기화
	Initial();

	//로봇의 위치를 빼내고 방문한 표시와 0으로 초기화.
	int robot_x, robot_y;
	tie(robot_x, robot_y) = robot_pos;
	new_arr[robot_x][robot_y] = 0;
	visited[robot_x][robot_y] = true;

	//큐에 등록하고 new_arr로의 경로를 증가시킴.
	q.push(robot_pos);
	BFS();

	//최우선 몬스터들을 모두 돌아다녀서 선정함.
	pair<int, int> best_pos = make_pair(-1,-1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			// 방문했고, 배열에 0이고, robot_level과 동일하다면.
			if (!visited[i][j] || !arr[i][j] || arr[i][j] == robot_level)
				continue;

			pair<int, int> now_pos= make_pair(i,j);

			//연산해서 우선순위에 잡은 것을 best_pos에 저장.
			if (Calc2(best_pos, now_pos)) {
				best_pos = now_pos;
			}

		}
	}

	//최우선 몬스터 선택해서 경로를 더함, 
	//만약 최대 좌표가 -1,-1 이면 이동 그렇지 않으면 반환.

	if (best_pos != make_pair(-1, -1)) {
		int best_x, best_y;
		tie(best_x, best_y) = best_pos;

		//x,y 좌표를 경로 cnt에 저장.
		ans_cnt += new_arr[best_x][best_y];
		//기존 배열의 로봇을 사라져야 함.
		arr[best_x][best_y] = 0;
		//로봇 위치 갱신.
		robot_pos = best_pos;
		cnt++;

		if (cnt == robot_level) {
			robot_level++;
			cnt = 0;
		}

		return true;

	}
	else {
		return false;
	}
}

int main() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			//로봇의 위치를 저장하고 0으로 배열 변환.
			if (arr[i][j] == 9) {
				arr[i][j] = 0;
				robot_pos = make_pair(i, j);
			}
		}
	}

	//몬스터가 없어질때까지 무한 반복, 몬스터가 없으면 break;
	while (1) {
		bool flag = Calc();
		if (!flag) {
			break;
		}
	}

	cout << ans_cnt;
}