#include <iostream>
#include <algorithm>
#include <queue>
#include <tuple>
#define MAX_N 100000

using namespace std;

int n, m, k;
priority_queue<tuple<long long, int, int, int> > pq;   
int arr1[MAX_N];    
int arr2[MAX_N];    

long long ans;      

int main(){
    cin >> n >> m >> k;
    for(int i=0; i<n; i++)
        cin >> arr1[i];
    sort(arr1, arr1+n);
    for(int i=0; i<m; i++)
        cin >> arr2[i];
    sort(arr2, arr2+m);
    
    for(int i=0; i<n; i++){
        pq.push(make_tuple(-arr1[i]-arr2[0], -arr1[i], -arr2[0], 0));   
    }

    while(k--){
        int x,y,idx;
        tie(ans, x, y, idx) = pq.top();     
        pq.pop();

        pq.push(make_tuple(x-arr2[idx+1], x, -arr2[idx+1], idx+1));        
    }
    cout << -ans << '\n';
    return 0;
}