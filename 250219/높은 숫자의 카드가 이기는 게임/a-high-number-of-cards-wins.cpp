#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int maxPoints(int n, vector<int>& b_cards) {
    set<int> a_cards;

    // 1부터 2N까지 중 B의 카드를 제외한 것이 A의 카드
    vector<bool> used(2 * n + 1, false);
    for (int b : b_cards) used[b] = true;

    for (int i = 1; i <= 2 * n; i++) {
        if (!used[i]) a_cards.insert(i);
    }

    int score = 0;

    // B의 카드를 순서대로 처리
    for (int b : b_cards) {
        // B보다 큰 A의 카드 중 가장 작은 카드 선택
        auto it = a_cards.upper_bound(b);
        if (it != a_cards.end()) {
            score++;  // 승점 획득
            a_cards.erase(it);
        }
        else {
            // 이길 수 없으면 가장 작은 A의 카드 소모
            a_cards.erase(a_cards.begin());
        }
    }

    return score;
}

int main() {
    int n;
    cin >> n;

    vector<int> b_cards(n);
    for (int i = 0; i < n; i++) {
        cin >> b_cards[i];
    }

    cout << maxPoints(n, b_cards) << endl;
    return 0;
}
