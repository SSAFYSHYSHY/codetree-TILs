#include <iostream>
#include <algorithm>
#include <tuple>

#define MAX_M 100000
#define MAX_NUM (long long)(1e18)

using namespace std;

int n, m;
pair<long long, long long> segments[MAX_M];

bool IsPossible(long long dist) {

    int cnt = 0;
    long long last_x = -MAX_NUM;
    for(int i = 0; i < m; i++) {
        long long a, b;
        tie(a, b) = segments[i];
        
        while(last_x + dist <= b) {
            cnt++;
            last_x = max(a, last_x + dist);
            if(cnt >= n)
                break;
        }
    }
    return cnt >= n;
}

int main() {
  
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        long long a, b;
        cin >> a >> b;
        segments[i] = make_pair(a, b);
    }

  
    sort(segments, segments + m);
    
    long long left = 1;                         
    long long right = MAX_NUM;                 
    long long ans = 0;                        
    
    while (left <= right) {                     
        long long mid = (left + right) / 2;     
        if(IsPossible(mid)) {                   
            left = mid + 1;                     
            ans = max(ans, mid);               
        }
        else                               
            right = mid - 1;                    
    }

    cout << ans;
    return 0;
}