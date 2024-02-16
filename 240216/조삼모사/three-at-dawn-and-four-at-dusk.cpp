#include <iostream>
#include <algorithm>
#include <climits>
#include <vector>

using namespace std;

int arr[21][21];
bool visited[21] = { false, };
int n, ans = INT_MAX;

int Calc2(){
    int sum = 0 , sum1= 0;
    for(int i = 1; i <= n ; i++) {
        for(int j = 1; j <= n ; j++) {
            if(i==j) continue;

            if(!visited[i] && !visited[j]) {
                sum += arr[i][j];
            }
            if(visited[i] && visited[j]){
                sum1 += arr[i][j];
            }
        }
    }

    return abs(sum - sum1);
}

void Calc(int curr, int cnt) {
	if (cnt == (n / 2)) {
		ans = min(ans, Calc2());
		return;
	}

    if(curr == n) {
        return ;
    }

    Calc(curr + 1, cnt);

    visited[curr] = true;
    Calc(curr + 1, cnt + 1);
    visited[curr] = false;

	
}

int main() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j];
		}
	}

	Calc(0, 0);

	cout << ans;
}