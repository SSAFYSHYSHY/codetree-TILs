#include <iostream>
#include <set>
#include <unordered_map>
#include <vector>
#include <sstream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, q;
    cin >> n >> q;

    set<int> treeSet;
    unordered_map<int, int> hashMap;
    ostringstream answer;

    // 배열 입력 받기
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        treeSet.insert(num);
    }

    // 좌표 압축
    int number = 1;
    for (auto x : treeSet) {
        hashMap[x] = number++;
    }

    // 쿼리 처리
    for (int i = 0; i < q; i++) {
        int startPointValue, endPointValue;
        cin >> startPointValue >> endPointValue;

        // startPointValue가 treeSet에 포함되지 않으면 ceiling을 찾고, endPointValue는 floor을 찾음
        auto startPointIter = treeSet.lower_bound(startPointValue);
        auto endPointIter = treeSet.upper_bound(endPointValue);

        if (startPointIter == treeSet.end() || endPointIter == treeSet.begin()) {
            answer << 0 << "\n";
        }
        else {
            // startPointValue는 포함될 수 있는 가장 작은 값, endPointValue는 포함될 수 있는 가장 큰 값
            int startPointNumber = hashMap[*startPointIter];
            int endPointNumber = hashMap[*prev(endPointIter)];

            if (startPointNumber > endPointNumber) {
                answer << 0 << "\n";
            }
            else {
                int count = endPointNumber - startPointNumber + 1;
                answer << count << "\n";
            }
        }
    }

    cout << answer.str();
    return 0;
}