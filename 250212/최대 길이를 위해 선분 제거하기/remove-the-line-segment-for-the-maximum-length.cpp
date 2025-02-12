#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
#include <unordered_set>
#include <climits>

using namespace std;

int n;
pair<int, int> segs[100001];
int weights[100001]; //각 선분을 제외했을때 빠지게 되는 길이 

void Input() {
	cin >> n;

	for (int i = 0; i < n; i++) {
		int x1, x2;
		cin >> x1 >> x2;

		segs[i] = make_pair(x1,x2);
	}

}

int main() {
	Input();

	//각 선분을 저장.
	vector<tuple<int, int, int>> points;
	for (int i = 0; i < n; i++) {
		int x1, x2;
		tie(x1, x2) = segs[i];

		points.push_back({ x1, +1, i });
		points.push_back({ x2, -1, i });
	}
	sort(points.begin(), points.end());

	//각 점을 순서대로 순회, 
	//제외 했을때 빠지게 되는 길이를 각 idx에 저장.
	int total_len = 0;
	unordered_set<int> sets;
	int prev_x = -1;

	for (int i = 0; i < 2 * n; i++) {
		int x, v, idx;
		tie(x, v, idx) = points[i];

		//걸쳐진 선분의 수는 segs의 크기와 같음.
		int seg_cnt = (int)sets.size();

		//1개 이상이면, 전체 길이의 합을 갱신.
		if (seg_cnt > 0) {
			total_len += x - prev_x;
		}

		//정확히 1개인 경우.
		if (seg_cnt == 1) {
			int tar_idx = *sets.begin();
			weights[tar_idx] += x - prev_x;
		}

		//시작점인 경우.
		if (v == +1) {
			sets.insert(idx);
		}
		else {
			sets.erase(idx);
		}

		prev_x = x;
	}

	int min_len = 21e8;

	for (int i = 0; i < n; i++) {
		min_len = min(min_len, weights[i]);
	}

	cout << total_len - min_len;
}