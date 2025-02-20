#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int arr1[n], arr2[n];
    string str;
    
    // 초기 문자열 입력
    cin >> str;
    for (int i = 0; i < n; i++) {
        arr1[i] = (str[i] == 'G') ? 0 : 1;
    }
    
    // 목표 문자열 입력
    cin >> str;
    for (int i = 0; i < n; i++) {
        arr2[i] = (str[i] == 'G') ? 0 : 1;
    }

    int cnt = 0;
    
    // 문자열을 탐색하며 최소 반전 횟수 계산
    for (int i = 0; i < n - 1; i++) {
        bool same = (arr1[i] == arr2[i]);

        for (int j = i + 1; j < n; j++) {
            if (same && arr1[j] == arr2[j]) {
                i++;
                continue;
            } else if (!same && arr1[j] != arr2[j]) {
                i++;
                continue;
            } else {
                cnt++;
                break;
            }
        }
    }

    // 마지막 문자가 다를 경우 반전 추가
    if (arr1[n - 1] != arr2[n - 1]) cnt++;

    cout << cnt << endl;
    return 0;
}
