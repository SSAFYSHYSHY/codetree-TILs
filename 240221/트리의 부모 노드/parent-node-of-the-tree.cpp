#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<int> v[100001];
int arr[100001];
bool visited[100001];
int start_point[100001];
int end_point[100001];

void Calc(int num) {
	for (int i = 0; i < v[num].size(); i++) {
		//자식 노드.
		int y = v[num][i];

		//아직 방문하지 않은 노드라면.
		//트리의 부모-자식 관계가 설정됨.
		//부모는 num, 자식은 y
		if (!visited[y]) {
			visited[y] = true;
			arr[y] = num;
			Calc(y);
		}

	}
}

int main() {
	cin >> n;

	for (int i = 1; i < n; i++) {
		cin >> start_point[i] >> end_point[i];
	}

	for (int i = 1; i <= n - 1; i++) {
		int x = start_point[i];
		int y = end_point[i];

		v[x].push_back(y);
		v[y].push_back(x);
	}

	//1번부터 순회시작.
	visited[1] = true;
	Calc(1);

	//자식 노드를 순회해서.
	for (int i = 2; i <= n; i++) {
		//arr에는 부모 노드의 정보가 저장 되어 있음.
		cout << arr[i] << "\n";
	}
}