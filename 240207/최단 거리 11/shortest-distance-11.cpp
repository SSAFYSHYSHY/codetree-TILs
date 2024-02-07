#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue> 

using namespace std;

int n, m; 
#define N_MAX 1'000 + 1

vector<pair<int,int>> edges[N_MAX]; 
priority_queue<pair<int,int>, vector<pair<int,int>>, 
                    greater<pair<int,int>> > pq; 

int dist[N_MAX]; 

int main(){
    cin>>n>>m;
    
    for(int i=0; i<m; i++){
        int v1,v2,w;
        cin>>v1>>v2>>w; 
        edges[v1].push_back({v2, w});
        edges[v2].push_back({v1, w});
    }

    for(int i=1; i<=n; i++){
        sort(edges[i].begin(), edges[i].end());
    }

    for(int i=1; i<=n; i++)
        dist[i] = (int)1e9;

    int a, b;
    cin>>a>>b; 

    dist[b] = 0;
    pq.push({0,b});
    while(!pq.empty()){
        int v, d; 
        tie(d, v) = pq.top();
        pq.pop();

        if(dist[v]!=d)
            continue; 

        vector<pair<int,int>>& vec = edges[v];
        for(int i=0; i<(int)vec.size(); i++){
            int new_v, new_d;
            tie(new_v, new_d) = vec[i]; 
            int new_dist = dist[v] + new_d;
            if(new_dist < dist[new_v]){
                dist[new_v] = new_dist;
                pq.push({new_dist, new_v});
            }    
        }
    }

    cout<<dist[a]<<'\n'; 

    int ptr = a; 
    cout<<ptr<<' ';
    while(ptr!=b){
        vector<pair<int,int>>& v = edges[ptr];
        for(int i=0; i<(int)v.size(); i++){
            int new_v, new_d;
            tie(new_v, new_d) = v[i];

            if(dist[ptr] == dist[new_v] + new_d){
                ptr=new_v;
                break;
            }
        }
        cout<<ptr<<' ';

    }
    return 0; 
    
}