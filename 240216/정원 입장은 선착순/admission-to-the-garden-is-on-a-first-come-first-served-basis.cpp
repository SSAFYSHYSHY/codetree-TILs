#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

priority_queue<pair<int, int>, vector<pair<int, int>>,
greater<pair<int, int>>> pQue;

priority_queue<pair<int, int>, vector<pair<int, int>>,
greater<pair<int, int>>> temppQue;
int maxtime;
int timearr[100001];

int main() {
    int N;
    cin >> N;

    int a, t;
    for (int i = 0; i < N; i++)
    {
        cin >> a >> t;

        timearr[i] = t;
        pQue.emplace(a, i);
    }

    int maxi = 0;
    while (!pQue.empty())
    {
        while (!pQue.empty())
        {
            int arrivetime = pQue.top().first;
            if (arrivetime > maxtime) break;

            temppQue.emplace(pQue.top().second, arrivetime);
            pQue.pop();
        }

        if (!temppQue.empty())
        {
            a = temppQue.top().second;
            t = timearr[temppQue.top().first];
            temppQue.pop();
        }
        else
        {
            a = pQue.top().first;
            t = timearr[pQue.top().second];
            pQue.pop();
        }

        if (maxtime == 0)
        {
            maxtime = a + t;
        }
        else
        {
            if (maxtime > a)
            {
                maxi = max(maxi, maxtime - a);
                maxtime += t;
            }
            else
                maxtime = a + t;
        }
    }

    cout << maxi;

    return 0;
}