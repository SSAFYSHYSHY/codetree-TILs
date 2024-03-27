#include <iostream>
#include <algorithm>

#define MAX_NUM 200

using namespace std;

// 가능한 모든 모양을 정의해줍니다.
int blocks[19][4][4] =  { { {1, 1, 1, 1},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {0, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 1, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 1, 0},
                            {0, 0, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {1, 0, 0, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 0, 1, 0},
                            {1, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 1, 0},
                            {1, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {1, 1, 0, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {1, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {1, 1, 1, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 0, 0, 0} },

                          { {0, 1, 0, 0},
                            {1, 1, 1, 0},
                            {0, 0, 0, 0},
                            {0, 0, 0, 0} } };
int n, m;
int grid[MAX_NUM][MAX_NUM];

// 주어진 위치가 격자를 벗어나는지 여부를 반환합니다.
int InRange(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

// 주어진 위치에 대하여 가능한 모든 모양을 탐색하며 최대 합을 반환합니다.
int GetMaxSum(int x, int y) {
    int max_sum = 0;
    for(int shape = 0; shape < 19; shape++) {
        int sum = 0;
        for(int dx = 0; dx < 4; dx++) {
            for(int dy = 0; dy < 4; dy++) {
                int new_x = x + dx;
                int new_y = y + dy;

                if(InRange(new_x, new_y) && blocks[shape][dx][dy])
                    sum += grid[new_x][new_y];
            }
        }

        max_sum = max(max_sum, sum);
    }

    return max_sum;
}
                          
int main() {              
    int max_sum = 0;    
                          
    // 입력:
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> grid[i][j];

    // 격자의 각 위치에 대하여 탐색하여줍니다.
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            max_sum = max(max_sum, GetMaxSum(i, j));

    cout << max_sum;
}