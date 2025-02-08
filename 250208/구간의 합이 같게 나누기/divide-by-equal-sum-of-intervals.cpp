#include <iostream>

#define MAX_N 100000

using namespace std;

int n;

long long arr[MAX_N];
long long L[MAX_N], R[MAX_N];

int main() {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];

    long long total_sum = 0;
    for(int i = 0; i < n; i++)
        total_sum += arr[i];
    
    if(total_sum % 4 != 0) {
        cout << 0;
        return 0;
    }

    long long target_sum = total_sum / 4;

    L[0] = 0;
    long long sum = arr[0]; 
    long long cnt = (sum == target_sum) ? 1 : 0;
    for(int i = 1; i < n; i++) {
        sum += arr[i];
        if(sum == 2 * target_sum)
            L[i] = cnt;
        
        if(sum == target_sum)
            cnt++;
    }
    
    R[n - 1] = 0;
    sum = arr[n - 1]; 
    cnt = (sum == target_sum) ? 1 : 0; 
    for(int i = n - 2; i >= 0; i--) {
        sum += arr[i];
        if(sum == 2 * target_sum)
            R[i] = cnt;
        
        if(sum == target_sum)
            cnt++;
    }
    
    long long ans = 0;
    for(int i = 1; i < n - 1; i++)
        ans += (long long)L[i] * R[i + 1];
    cout << ans;
    return 0;
}
