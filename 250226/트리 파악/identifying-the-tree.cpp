#include <iostream>
#include <vector>

using namespace std;

int n; // 트리의 노드 개수
vector<int> tree[100001]; // 트리의 간선 정보
bool visited[100001]; // 방문 여부
int depth[100001]; // 각 노드의 깊이

// DFS를 통해 각 노드의 깊이를 구하고 리프 노드를 찾는다.
void dfs(int node, int d) {
    visited[node] = true;
    depth[node] = d;
    
    bool isLeaf = true; // 리프 노드인지 체크하는 변수
    
    for (int next : tree[node]) {
        if (!visited[next]) {
            isLeaf = false;
            dfs(next, d + 1);
        }
    }
    
    // 자식이 없으면 리프 노드
    if (isLeaf) {
        // 리프 노드의 깊이를 기록 (홀수인지 짝수인지 판단)
    }
}

int main() {
    cin >> n;
    
    // 트리의 간선 정보 입력
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        tree[u].push_back(v);
        tree[v].push_back(u);
    }
    
    // DFS를 통해 트리의 깊이를 구한다.
    dfs(1, 0);
    
    // 홀수 깊이의 리프 노드 개수 구하기
    int oddLeafCount = 0;
    for (int i = 1; i <= n; i++) {
        if (tree[i].size() == 1 && i != 1) { // 리프 노드
            if (depth[i] % 2 == 1) {
                oddLeafCount++;
            }
        }
    }
    
    // 홀수 깊이의 리프 노드 개수가 홀수이면 A가 승리
    if (oddLeafCount % 2 == 1) {
        cout << 1 << endl; // A가 승리
    } else {
        cout << 0 << endl; // B가 승리
    }
    
    return 0;
}
