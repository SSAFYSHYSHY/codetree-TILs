#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <algorithm>

using namespace std;

//다음 노드, 버스 번호, 탑승 순서, 요금
struct Node {
	int next_idx, num, num2;
	long long cost;
};

int a, b, n;

vector<Node> v[1001];
pair<long long, int> dist[1001][1001];
priority_queue<tuple<long long, int, int, int, int>, vector<tuple<long long, int, int, int, int>>, greater<>> pq;

void Input() {
	cin >> a >> b >> n;

	for (int i = 1; i <= n; i++) {
		long long cost;
		int cnt;
		cin >> cost >> cnt;

		vector<int> v2;

		for (int j = 0; j < cnt; j++) {
			int x;
			cin >> x;
			v2.push_back(x);
		}

		for (int j = 0; j < cnt - 1; j++) {
			v[v2[j]].push_back({ v2[j + 1],i,j + 1, cost });
		}
	}

	//dist 초기화.
	for (int i = 1; i <= 1000; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = { LLONG_MAX, INT_MAX };
		}
	}

	for (int i = 1; i <= n; i++) {
		dist[a][i] = { 0,0 };
	}
}

int main() {
	Input();

	pq.push({ 0,0,a,0,0 });

	while (!pq.empty()) {
		long long now_cost;
		int now_time, now_idx, now_num, now_num2;
		tie(now_cost, now_time, now_idx, now_num, now_num2) = pq.top();
		pq.pop();

		for (int i = 0; i < v[now_idx].size(); i++) {
			int next_idx, next_num, next_num2;
			long long next_cost;

			next_idx = v[now_idx][i].next_idx;
			next_num = v[now_idx][i].num;
			next_num2 = v[now_idx][i].num2;
			next_cost = v[now_idx][i].cost;

			long long new_cost = now_cost;
			int new_time = now_time + 1;

			if (now_num != next_num) {
				new_cost += next_cost;
			}

			if (dist[next_idx][next_num] > make_pair(new_cost, new_time)) {
				dist[next_idx][next_num] = { new_cost, new_time };
				pq.push(make_tuple(new_cost, new_time, next_idx, next_num, next_num2));
			}
		}
	}

	
	pair<long long, int> ans = { LLONG_MAX, INT_MAX };
	for (int i = 1; i <= n; i++) {
		ans = min(ans, dist[b][i]);
	}

	if (ans.first == LLONG_MAX) {
		cout << "-1 -1" << "\n";
	}
	else {
		cout << ans.first << " " << ans.second << "\n";
	}


}

