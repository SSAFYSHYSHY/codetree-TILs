#include <iostream>
#include <algorithm>
#include <tuple>
#include <vector>
#include <unordered_set>

using namespace std;

int n;

vector<tuple<int, int, int>> points;
pair<int, int> arr[100001];

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2;
		cin >> x1 >> x2;

		arr[i] = make_pair(x1, x2);
	}
}

int main() {
	Input();

	//각 선분을 두 지점으로 나눠 담은 후 
	//정렬, 이때 +1, -1 시작, 끝.
	for (int i = 0; i < n; i++) {
		int x1, x2;
		tie(x1, x2) = arr[i];

		points.push_back({ x1, +1, i });
		points.push_back({ x2, -1, i });
	}

	sort(points.begin(), points.end());

	unordered_set<int> segs;

	int len = 0, s_x = -1, max_len = 0;
	for(int i = 0; i < 2* n ; i++) {
		int x, v, idx;
		tie(x, v, idx) = points[i];

		if (v == +1) {
			if ((int)segs.size() == 0) {
				s_x = x;
			}

			segs.insert(idx);
		}
		else {
			segs.erase(idx);

			if ((int)segs.size() == 0) {
				int e_x = x;
				len = (e_x - s_x);
				max_len = max(max_len, len);
			}
		}
	}

	cout << max_len;

}