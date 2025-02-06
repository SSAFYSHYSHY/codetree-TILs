#include <iostream>
#include <set>
#include <unordered_map>
#include <tuple>

#define MAX_N 2500
#define MAX_Q 300000
#define MAX_M 5000

using namespace std;

// 변수 선언
int n, q;
pair<int, int> points[MAX_N];
tuple<int, int, int, int> queries[MAX_Q];

set<int> nums;
unordered_map<int, int> mapper;

int prefix_sum[MAX_M + 2][MAX_M + 2];

// x보다 같거나 큰 최초의 숫자를 구해
// 이를 좌표압축 했을 때의 결과를 반환합니다.
int GetLowerBoundary(int x) {
    set<int>::iterator it = nums.lower_bound(x);

    if(it == nums.end())
        return (int) nums.size() + 1;

    return mapper[*it];
}

// x보다 같거나 작은 최초의 숫자를 구해
// 이를 좌표압축 했을 때의 결과를 반환합니다.
int GetUpperBoundary(int x) {
    set<int>::iterator it = nums.upper_bound(x);

    if(it == nums.begin())
        return 0;

    it--;
    return mapper[*it];
}

// (x1, y1), (x2, y2) 직사각형 구간 내의 점의 개수를 반환합니다.
int GetSum(int x1, int y1, int x2, int y2) {
    return prefix_sum[x2][y2]     - prefix_sum[x1 - 1][y2] -
           prefix_sum[x2][y1 - 1] + prefix_sum[x1 - 1][y1 - 1];
}

int main() {
    // 입력:
    cin >> n >> q;

    // 입력과 동시에
    // 주어진 x, y 좌표값들을 전부 treeset에 넣어줍니다.

    for(int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        points[i] = make_pair(x, y);

        nums.insert(x);
        nums.insert(y);
    }
    
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        queries[i] = make_tuple(x1, y1, x2, y2);
    }
    
    // treeset에서 값이 작은 것부터 보면서
    // 1번부터 순서대로 매칭하여
    // 그 결과를 hashmap에 넣어줍니다.
    int cnt = 1;
    for(set<int>::iterator it = nums.begin(); it != nums.end(); it++) {
        mapper[*it] = cnt;
        cnt++;
    }

    // 주어진 점들에 대해 
    // 누적합 배열을 완성합니다.
    for(int i = 0; i < n; i++) {
        int x, y;
        tie(x, y) = points[i];
        
        // 좌표 압축을 진행합니다.
        int new_x = mapper[x];
        int new_y = mapper[y];

        prefix_sum[new_x][new_y]++;
    }

    for(int i = 1; i <= cnt; i++)
        for(int j = 1; j <= cnt; j++)
            prefix_sum[i][j] += prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1];
    
    // 각 질의에 대해
    // 구간 내 점의 개수를 구합니다.
    for(int i = 0; i < q; i++) {
        int x1, y1, x2, y2;
        tie(x1, y1, x2, y2) = queries[i];
        
        // x1, y1의 경우 같거나 큰 최초의 위치를 lower_bound로,
        // x2, y2의 경우 같거나 작은 최초의 위치를 upper_bound - 1로 구해줍니다.

        int new_x1 = GetLowerBoundary(x1);
        int new_y1 = GetLowerBoundary(y1);
        int new_x2 = GetUpperBoundary(x2);
        int new_y2 = GetUpperBoundary(y2);

        // 구간 내 점의 개수를 
        // 누적합을 이용하여 계산합니다.
        int ans = GetSum(new_x1, new_y1, new_x2, new_y2);
        cout << ans << endl;
    }
    return 0;
}
