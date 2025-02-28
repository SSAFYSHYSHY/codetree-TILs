#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

vector<int> graph[1001]; // 그래프 인접 리스트
bool visited[1001]; // 방문 여부 확인용 배열

// DFS 탐색 함수
void dfs(int node, int &nodeCount, int &edgeCount) {
    visited[node] = true;
    nodeCount++; // 노드 수 증가
    for (int neighbor : graph[node]) {
        edgeCount++; // 간선 수 증가 (양방향이므로 두 번 세지 않기 위해 하나만 셈)
        if (!visited[neighbor]) {
            dfs(neighbor, nodeCount, edgeCount);
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;

    // 그래프 구성
    for (int i = 0; i < M; i++) {
        int u, v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u); // 양방향 간선
    }

    int treeCount = 0;

    // 각 노드에 대해 DFS로 연결 요소를 찾음
    for (int i = 1; i <= N; i++) {
        if (!visited[i]) {
            int nodeCount = 0, edgeCount = 0;
            dfs(i, nodeCount, edgeCount);

            // 트리 조건 검사
            if (edgeCount == 2 * (nodeCount - 1)) { // 간선 수가 노드 수 - 1 이어야 함 (양방향 간선 고려)
                treeCount++;
            }
        }
    }

    cout << treeCount << endl;
    return 0;
}
