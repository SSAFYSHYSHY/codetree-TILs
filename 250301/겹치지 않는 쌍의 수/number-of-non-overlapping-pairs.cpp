#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    vector<int> bitmask(N);

    // 그룹을 비트마스크로 변환
    for (int i = 0; i < N; i++) {
        int group_size;
        cin >> group_size;

        int mask = 0;
        for (int j = 0; j < group_size; j++) {
            int person;
            cin >> person;
            mask |= (1 << (person - 1)); // 1-based -> 0-based 인덱스
        }
        bitmask[i] = mask;
    }

    // 서로 겹치지 않는 그룹 쌍 찾기
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = i + 1; j < N; j++) {
            if ((bitmask[i] & bitmask[j]) == 0) { // 겹치는 사람 없음
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}
