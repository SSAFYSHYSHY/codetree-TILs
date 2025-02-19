#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>

using namespace std;

int n;
vector<pair<int, int> > nums;

int ans;

void Input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        nums.push_back(make_pair(y, x));
    }
    sort(nums.begin(), nums.end());
}

int main() {
    int l = 0, r = n - 1;
    
    while (l <= r) {
        int ly, lx;
        tie(ly, lx) = nums[l];
        int ry, rx;
        tie(ry, rx) = nums[r];

        ans = max(ans, ly + ry);

        if (lx < rx) {
            nums[r] = make_pair(ry, rx - lx);
            l++;
        }
        else if (lx > rx) {
            nums[l] = make_pair(ly, lx - rx);
            r--;
        }
        else {
            l++;
            r--;
        }
    }
    cout << ans;
    return 0;
}
