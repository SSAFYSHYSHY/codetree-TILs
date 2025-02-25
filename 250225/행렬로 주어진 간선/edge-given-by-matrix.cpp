#include <iostream>
#include <algorithm>

#define MAX_N 100

using namespace std;

int n;
int graph[MAX_N + 1][MAX_N + 1];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> graph[i][j];

    for (int i = 1; i <= n; i++)
        graph[i][i] = 1;

    for (int k = 1; k <= n; k++) 
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if (graph[i][k] && graph[k][j])
                    graph[i][j] = 1;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++)
            cout << graph[i][j] << " ";
        cout << endl;
    }

    return 0;
}
