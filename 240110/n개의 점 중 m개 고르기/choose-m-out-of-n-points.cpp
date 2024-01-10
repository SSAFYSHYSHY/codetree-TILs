#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>

using namespace std;

pair<int, int> p[21];
int n, m;
double ans = 21e8;
vector<pair<int, int>> v;

double Calc2(int num) {
	double diff = 0.0;

	for (int i = 0; i < num; i++) {
		int x, y, x1, y1;
		tie(x, y) = v[i];
		for (int j = i + 1; j < num; j++) {
			tie(x1, y1) = v[j];
			diff = max((double)sqrt(pow((x1 - x), 2) + pow((y1 - y), 2)), diff);
		}
	}

	return diff;
}

void Calc(int curr, int idx) {
	if (curr == m  ) {
		ans = min(ans, Calc2(m));
		return;
	}

	for (int i = idx; i < n; i++) {
		v.push_back(p[i]);
		Calc(curr + 1, i + 1);
		v.pop_back();
	}
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		p[i] = { x,y };
	}

	Calc(0, 0);

    //cout << ans << "\n";
	cout << (int)(round(pow(ans,2)));
}