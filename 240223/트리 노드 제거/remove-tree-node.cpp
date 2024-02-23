#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> graph;
vector<int> leaf;
int root = 0;

void dfs(int x, int parent) {
    if (graph[x].empty()) {
        leaf[x] += 1;
    }

    for (int y : graph[x]) {
        if (y != parent) {
            dfs(y, x);
            leaf[x] += leaf[y];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    graph.resize(n);
    leaf.resize(n, 0);

    vector<int> parent(n);
    for (int i = 0; i < n; ++i) {
        cin >> parent[i];
        if (parent[i] == -1) {
            root = i;
            continue;
        }
        graph[parent[i]].push_back(i);
    }

    int erased;
    cin >> erased;

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < graph[i].size(); ++j) {
            if (graph[i][j] == erased) {
                graph[i].erase(graph[i].begin() + j);
                break;
            }
        }
    }

    if (root != erased) {
        dfs(root, -1);
    }

    cout << leaf[root] << '\n';

    return 0;
}