#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

vector<int> v;
int n, m;
bool visited[7] = {false,};

void Back(int now) {
	if (now == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 1; i <= 6; i++) {
		v.push_back(i);
		Back(now + 1);
		v.pop_back();
	}
}

void Back2(int now, int idx) {
	if (now == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= 6; i++) {
		v.push_back(i);
		Back2(now + 1, i);
		v.pop_back();
	}
}

void Back3(int now, int idx) {
	if (now == n) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = idx; i <= 6; i++) {
		if (!visited[i]) {
			v.push_back(i);
			visited[i] = true;
			Back3(now + 1, idx);
			visited[i] = false;
			v.pop_back();
		}
	}
}

int main() {
	cin >> n >> m;

	if (m == 1) {
		Back(0);
	}
	//중복제거 , (1,2) (2,1)은 같은 경우로 취급.
	else if (m == 2) {
		Back2(0 , 1);
	}
	//똑같은 숫자 제거.
	else {
		Back3(0, 1);
	}

}