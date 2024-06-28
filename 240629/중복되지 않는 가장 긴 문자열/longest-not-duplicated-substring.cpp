#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int main() {
    string s;
    cin >> s;

    unordered_map<char, int> last_seen; // 각 문자의 마지막 출현 위치를 저장하는 맵
    int max_length = 0;
    int j = 0; // 현재 부분 문자열의 시작 인덱스

    for (int i = 0; i < s.length(); i++) {
        // 문자가 중복된 경우, 시작 포인터 j를 마지막 중복 문자의 다음 위치로 이동
        if (last_seen.find(s[i]) != last_seen.end()) {
            j = max(j, last_seen[s[i]] + 1);
        }

        // 현재 문자 위치를 업데이트
        last_seen[s[i]] = i;

        // 현재 부분 문자열의 길이를 계산하고 최대 길이 업데이트
        max_length = max(max_length, i - j + 1);
    }

    cout << max_length << endl;
    return 0;
}