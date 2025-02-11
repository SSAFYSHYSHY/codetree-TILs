#include <iostream>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int n;
vector<tuple<int, int, int>> points;
pair<int, int> arr[100001];

void Input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		arr[i] = { x, y };
	}
}

int main() {
	Input();

	// +1, -1을 적용하여 points에 추가
	for (int i = 0; i < n; i++) {
		int x1, x2;
		tie(x1, x2) = arr[i];
		points.push_back({ x1, +1, i });
		points.push_back({ x2, -1, i });
	}

	// 정렬: x값 기준 오름차순, 같은 x면 +1이 먼저 오게 정렬
	sort(points.begin(), points.end());

	int total_length = 0;
	int active_segments = 0;  // 현재 활성화된 구간 개수
	int start = 0;  // 현재 구간의 시작점
	unordered_set<int> segs;

	for (int i = 0; i < 2 * n; i++) {
		int x, v, idx;
		tie(x, v, idx) = points[i];

		if (active_segments > 0) {
			total_length += (x - start); // 현재 활성화된 구간의 길이 추가
		}

		// 구간 시작 처리
		if (v == +1) {
			segs.insert(idx);
		}
		// 구간 종료 처리
		else {
			segs.erase(idx);
		}

		// 현재 좌표를 새로운 시작점으로 설정
		start = x;
		active_segments = segs.size();
	}

	cout << total_length << '\n';
}