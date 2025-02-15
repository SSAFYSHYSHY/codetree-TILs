#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, int> map;
string str;
int k, ans, cnt;

bool isValid(int j) {
    return cnt <= k;  // 현재 다른 문자의 개수가 k 이하인지 확인
}

int main() {
    cin >> str >> k;
    int n = str.size();  // 0-based index 사용

    int j = 0;
    for (int i = 0; i < n; i++) {
        while (j < n) {
            if (map[str[j]] == 0) cnt++;  // 새로운 문자 등장 시 카운트 증가
            map[str[j]]++;

            if (!isValid(j)) {  // k를 초과하면 종료
                map[str[j]]--;    // 마지막 증가한 값을 롤백
                if (map[str[j]] == 0) cnt--;
                break;
            }
            j++;
        }

        ans = max(ans, j - i);  // 최장 길이 갱신

        map[str[i]]--;  // i 증가에 따라 문자 개수 감소
        if (map[str[i]] == 0) cnt--;
    }

    cout << ans;

    return 0;
}