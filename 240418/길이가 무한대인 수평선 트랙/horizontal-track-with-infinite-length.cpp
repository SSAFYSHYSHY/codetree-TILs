#include <iostream>
#include <set>
#include <tuple>

#define MAX_N 100000

using namespace std;

// 변수 선언
int n, t;
// x 순으로 정렬하여 사람들을 관리합니다.
set<pair<int, int> > people_x;
// 인접한 사람끼리 만나는 시간 순으로 정렬하여 사건들을 관리합니다.
set<tuple<double, int, int> > event_t;  

int x[MAX_N], v[MAX_N];

// (x1, v1) 사람이 바로 앞에 있는 (x2, v2)와 마주치는 데 걸리는 시간
// 정보를 얻어 사건 정보를 추가합니다. 
void AddEvent(int x1, int v1, int x2, int v2) {
    // 절대 따라잡을 수 없는 경우라면 무시합니다.
    if(v1 <= v2)
        return;
        
    event_t.insert(make_tuple(1.0 * (x2 - x1) / (v1 - v2), x1, v1));
}

// (x1, v1) 사람이 바로 앞에 있는 (x2, v2)와 마주치는 데 걸리는 시간
// 정보를 얻어 해당 사건 정보를 제거합니다.
void RemoveEvent(int x1, int v1, int x2, int v2) {
    // 절대 따라잡을 수 없는 경우라면 무시합니다.
    if(v1 <= v2)
        return;
    
    event_t.erase(make_tuple(1.0 * (x2 - x1) / (v1 - v2), x1, v1));
}

int main() {
    // 입력:
    cin >> n >> t;
    for(int i = 0; i < n; i++)
        cin >> x[i] >> v[i];
    
    // 사람들을 set으로 관리합니다.
    for(int i = 0; i < n; i++)
        people_x.insert(make_pair(x[i], v[i]));

    // 인접한 사람끼리 만나는 사건도 set으로 관리합니다.
    // (t, x, v) : 
    // 현재 x 위치에서 속도 v로 이동하는 사람과
    // 바로 앞에 있는 사람이 
    // 마주치는 데 거리는 시간 t라는 정보 기입
    for(int i = 0; i < n - 1; i++)
        AddEvent(x[i], v[i], x[i + 1], v[i + 1]);

    // 앞지르는 사건이 존재한다면 반복합니다.
    while(!event_t.empty()) {
        double curr_t; int x, v;
        tie(curr_t, x, v) = *event_t.begin();

        // 이미 t분이 넘었다면 종료합니다.
        if(curr_t > t)
            break;

        // 해당 사람과 사건을 삭제합니다.
        people_x.erase(make_pair(x, v));
        event_t.erase(make_tuple(curr_t, x, v));
        
        // 바로 앞 사람 위치를 구합니다.
        set<pair<int, int> >::iterator it = people_x.upper_bound(make_pair(x, v));
        int nx, nv;
        tie(nx, nv) = *it;

        // 바로 뒤에 사람이 있다면 
        // 이전 사건을 삭제하고
        // 새로운 사건을 추가합니다.
        if(it != people_x.begin()) {
            it--;
            int px, pv;
            tie(px, pv) = *it;
            RemoveEvent(px, pv, x, v);
            AddEvent(px, pv, nx, nv);
        }
    }

    // 서로 다른 그룹의 수를 출력합니다.
    cout << (int) people_x.size();
    return 0;
}