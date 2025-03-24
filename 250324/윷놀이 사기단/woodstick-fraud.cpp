#include <iostream>
#include <algorithm>
#define Can 10
#define Num 4
#define MAX_POS 45
#define START 0
#define END 20

using namespace std;

int move_nums[11];
int curr_pos[4];
int arr[] = {
	0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,0,
	13,16,19,0,0,
	22,24,0,0,0,
	28,27,26,0,0,
	0,0,0,0,0,
	25,30,35,40
};
int ans = 0;

bool Blue(int curr_pos) {
	return curr_pos != START && curr_pos % 5 == 0;
}

int NextCalc(int curr_pos, int move_num) {
	if (curr_pos == END) return END;

	if (move_num == 0) {
		return curr_pos;
	}

	int next_pos = curr_pos + 1;
	if (curr_pos == 23 || curr_pos == 27 || curr_pos == 33) {
		next_pos = 41;
	}
	else if (curr_pos == 19) {
		next_pos = 44;
	}
	else if (curr_pos == 44) {
		next_pos = END;
	}

	return NextCalc(next_pos, move_num - 1);
}

bool Over() {
	for (int i = 0; i < 4; i++) {
		for (int j = i + 1; j < 4; j++) {
			if (curr_pos[i] == curr_pos[j] &&
				curr_pos[i] != START &&
				curr_pos[i] != END)
				return true;
		}
	}

	return false;
}

void Back(int cnt, int score) {
	if (cnt == 10) {
		ans = max(ans, score);
		return;
	}

	for (int i = 0; i < 4; i++) {
		if (curr_pos[i] == END) continue;

		int temp = curr_pos[i];

		if (Blue(curr_pos[i])) {
			curr_pos[i] = NextCalc(curr_pos[i] + 16, move_nums[cnt] - 1);
		}
		else {
			curr_pos[i] = NextCalc(curr_pos[i], move_nums[cnt]);
		}

		if (!Over()) {
			Back(cnt + 1, score + arr[curr_pos[i]]);
		}

		curr_pos[i] = temp;
	}
}

int main() {
	for (int i = 0; i < 10; i++) {
		cin >> move_nums[i];
	}

	Back(0, 0);
	cout << ans;
}