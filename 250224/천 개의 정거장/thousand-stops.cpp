#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <map>

using namespace std;

const int INF = 1e9;
using tiii = tuple<int, int, int>;  // (현재 비용, 현재 위치, 현재 버스 ID)

// 버스 정보를 저장할 구조체
struct Bus {
    int fare;
    vector<int> stops;
};

int A, B, N;
vector<Bus> buses;
map<int, vector<pair<int, int>>> graph;  // 지점별로 (다음 지점, 버스 ID) 저장
vector<int> minCost(1001, INF);  // 최소 비용
vector<int> minTime(1001, INF);  // 최소 시간

void dijkstra() {
    priority_queue<tiii, vector<tiii>, greater<>> pq;
    pq.emplace(0, A, -1);  // (비용, 현재 위치, 이전 버스 ID)
    minCost[A] = 0;
    minTime[A] = 0;

    while (!pq.empty()) {
        auto [cost, node, busId] = pq.top();
        pq.pop();

        if (cost > minCost[node]) continue;  // 기존 비용보다 크면 무시

        for (auto& [next, nextBusId] : graph[node]) {
            int nextCost = cost;
            int nextTime = minTime[node] + 1;

            if (nextBusId != busId) {  // 환승하는 경우
                nextCost += buses[nextBusId].fare;
            }

            if (nextCost < minCost[next] || (nextCost == minCost[next] && nextTime < minTime[next])) {
                minCost[next] = nextCost;
                minTime[next] = nextTime;
                pq.emplace(nextCost, next, nextBusId);
            }
        }
    }
}

int main() {
    cin >> A >> B >> N;
    buses.resize(N);

    for (int i = 0; i < N; i++) {
        int fare, count;
        cin >> fare >> count;
        buses[i].fare = fare;
        buses[i].stops.resize(count);

        for (int j = 0; j < count; j++) {
            cin >> buses[i].stops[j];
        }

        // 버스 노선 연결
        for (int j = 0; j < count - 1; j++) {
            int u = buses[i].stops[j], v = buses[i].stops[j + 1];
            graph[u].emplace_back(v, i);
            graph[v].emplace_back(u, i);
        }
    }

    dijkstra();

    if (minCost[B] == INF || minTime[B] == INF) {
        cout << "-1 -1";
    }
    else {
        cout << minCost[B] << " " << minTime[B] << endl;
    }
    return 0;
}
