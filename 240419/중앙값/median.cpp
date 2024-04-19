#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int t, m;
priority_queue<int> q;
int arr[100001];

void Find() {
	int med = arr[0];

	priority_queue<int> max_q;
	priority_queue<int> min_q;

	cout << med << " ";

	for (int i = 1; i < m; i++) {
		if (i % 2 == 1) {
			if (arr[i] < med) {
				max_q.push(arr[i]);
			}
			else {
				min_q.push(-arr[i]);
			}
		}

		else {
			int new_cnt;

			if (max_q.size() > min_q.size()) {
				new_cnt = max_q.top();
				max_q.pop();
			}
			else {
				new_cnt = -min_q.top();
				min_q.pop();
			}

			int nums[] = { med, arr[i], new_cnt };
			sort(nums, nums + 3);


			max_q.push(nums[0]);
			med = nums[1];
			min_q.push(-nums[2]);

			cout << med << " ";
		}
	}


}

int main() {
	cin >> t;

	while (t--) {
		cin >> m;

		for (int i = 0; i < m; i++) {
			cin >> arr[i];
		}

		Find();
	}
}