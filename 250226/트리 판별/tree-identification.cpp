#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<int, vector<int>> graph;
unordered_map<int, int> indegree;
unordered_set<int> nodes;
int root = -1;

// DFS를 이용한 연결성 검사
bool dfs(int node, unordered_set<int> &visited) {
    if (visited.count(node)) return false; // 사이클 발생
    
    visited.insert(node);
    for (int neighbor : graph[node]) {
        if (!dfs(neighbor, visited)) return false;
    }
    return true;
}

bool isTree() {
    // 1. 루트 노드 찾기 (진입 차수가 0인 노드가 단 하나여야 함)
    int rootCount = 0;
    for (int node : nodes) {
        if (indegree[node] == 0) {
            rootCount++;
            root = node;
        }
    }
    if (rootCount != 1) return false;

    // 2. 루트 제외 모든 노드의 진입 차수가 1인지 확인
    for (int node : nodes) {
        if (node != root && indegree[node] != 1) return false;
    }

    // 3. DFS를 통해 모든 노드 방문 확인 및 사이클 존재 여부 확인
    unordered_set<int> visited;
    if (!dfs(root, visited)) return false;

    // 4. 모든 노드가 방문되었는지 확인
    return visited.size() == nodes.size();
}

int main() {
    int M;
    cin >> M;
    
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
        nodes.insert(a);
        nodes.insert(b);
    }

    cout << isTree() << endl;
    return 0;
}
