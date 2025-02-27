#include <iostream>
#include <algorithm>

using namespace std;

int n, m,x,y, k;
int arr[21][21];

//주사위 정보. 같이 굴려짐.
//아래, 위, 북,동,남,서
int dice[6] = {0,0,0,0,0,0};
int new_dice[6] = { 0,0,0,0,0,0 };

//동,서,북,남 방향 전환.
int dx[] = {0,0,0,-1,1};
int dy[] = {0,1,-1,0,0};

int dice_roll[5][6] = {
	//동,서, 북 ,남
	{},
	{3,5,2,1,4,0},
	{5,3,2,0,4,1},
	{2,4,1,3,0,5},
	{4,2,0,3,1,5}
};

void Input() {
	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}
}

bool InRange(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

bool Calc(int dir) {
	//다음 가는 범위.
	x += dx[dir];
	y += dy[dir];
	
	//범위 밖으로 벗어나면 무시.
	if (!InRange(x, y)) {
		x -= dx[dir];
		y -= dy[dir];

		return false;
	}


	//범위 안에 정상적으로 들어왔으므로 연산 시작.
	// 1. 주사위 굴리기. 
	for (int i = 0; i < 6; i++) {
		//해당 좌표.
		int idx = dice_roll[dir][i];

		//주사위의 정보에 카피.
		new_dice[i] = dice[idx];
	}

	//for (int i = 0; i < 6; i++) {
	//	cout << new_dice[i] << " ";
	//}
	//cout << "\n";

	//굴린 곳에 대한 배열을 전환.
	//1 아랫면이 0 이고 배열면이 0 이 나미녀 dice에 배열 복사, 해당 arr 0으로
	if (new_dice[0] == 0 && arr[x][y] != 0) {
		new_dice[0] = arr[x][y];
		arr[x][y] = 0;
	}
	//2 아랫면이 0 이 아니고 배열면이 0  이면 arr 에 dice 복사. 해당 dice 0 으로
	else if (new_dice[0] != 0 && arr[x][y] == 0) {
		arr[x][y] = new_dice[0];
		new_dice[0] = 0;
	}
	//3 아랫면이 0 이 아니고 배열면이 0 이 아니면, 그냥 덮어쓰기?
	else if (new_dice[0] != 0 && arr[x][y] != 0) {
		new_dice[0] = arr[x][y];
		arr[x][y] = 0;
	}

	//for (int i = 0; i < 6; i++) {
	//	cout << new_dice[i] << " ";
	//}
	//cout << "\n\n";

	for (int i = 0; i < 6; i++) {
		dice[i] = new_dice[i];
	}
	return true;
}

int main(){
	Input();

	//k 만큼 시뮬 반복.
	while (k--) {
		int dir;
		cin >> dir;

		//범위 안에 들어온 함수에 대해서.
		if (Calc(dir)) {
			//주사위의 윗면 출력.
			cout << dice[1] << "\n";
		}
		//범위 밖이니 continue로 무시.
		else {
			continue;
		}

	}
}


