#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const double MAX_N = 1e9;

double n;
double arr[100001];
double velo[100001];
double l = 1, r = 1e9, ans = 1e9;

bool Calc(double mid) {
    double lnum = max(0.0, arr[0] - velo[0] * mid);
    double rnum = min(MAX_N, arr[0] + velo[0] * mid); // velocity 적용

    for (int i = 1; i < n; i++) {
        double lnum2 = max(0.0, arr[i] - velo[i] * mid);
        double rnum2 = min(MAX_N, arr[i] + velo[i] * mid); // velocity 적용

        if (lnum2 > rnum || rnum2 < lnum) {
            return false;
        }

        lnum = max(lnum, lnum2);
        rnum = min(rnum, rnum2);
    }

    return true;
}

int main() {
    cout.precision(4);
    cout << fixed;
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];
    for (int i = 0; i < n; i++) cin >> velo[i];

    while (l <= r) {
        double mid = (l + r) / 2;

        if (Calc(mid)) {
            r = mid - 1;
            ans = min(ans, mid);
        }
        else {
            l = mid + 1;
        }
    }

    cout << ans;
    return 0;
}