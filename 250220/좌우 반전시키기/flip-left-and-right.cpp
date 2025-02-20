#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = 0;
    
    // 2번째 칸부터 순차적으로 진행
    for (int i = 1; i < n; i++) {
        if (arr[i - 1] == 0) {
            // i 번째 칸을 눌러야 함
            count++;
            arr[i - 1] = 1;
            arr[i] ^= 1;
            if (i + 1 < n) {
                arr[i + 1] ^= 1;
            }
        }
    }
    if(arr[n - 1] == 0) {
        count = -1;
    }

    cout << count << endl;
    return 0;
}
