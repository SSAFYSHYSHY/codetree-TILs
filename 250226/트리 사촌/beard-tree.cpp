#include <iostream>
#include <vector>
#define MAX_N 1000

using namespace std;

int n, k;
int arr[1001];
int dist[1001];
int find_node;
int ans;

void Input() {
	cin >> n >> k;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i];

		if (arr[i] == k) {
			find_node = i;
		}
	}
}

int main() {
	Input();

	int dist_node = 0;
	for (int i = 2; i <= n; i++) {
		if (arr[i] > arr[i - 1] + 1) {
			dist_node++;
		}

		dist[i] = dist_node;
	}

	for (int i = 1; i <= n; i++) {
		if (!dist[dist[i]] || !dist[dist[find_node]])continue;
		if (dist[i] != dist[find_node] && dist[dist[i]] == dist[dist[find_node]]) {
			ans++;
		}
	}

	cout << ans;
}