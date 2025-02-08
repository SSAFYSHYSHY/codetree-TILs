#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 가위바위보 승리 여부 계산
typedef char Move;

// B가 내는 것에 대해 A가 특정한 손동작을 낼 때 승리하는지 판별
int win_count(const vector<Move>& B, Move A_move) {
    int count = 0;
    for (char b : B) {
        if ((A_move == 'H' && b == 'S') || (A_move == 'S' && b == 'P') || (A_move == 'P' && b == 'H')) {
            count++;
        }
    }
    return count;
}

int max_wins(vector<Move>& B) {
    int N = B.size();
    
    // A가 특정한 하나의 손동작만 냈을 때 승리하는 횟수
    int winH = win_count(B, 'H');
    int winP = win_count(B, 'P');
    int winS = win_count(B, 'S');
    
    // L과 R 배열을 활용하여 최적의 변경 지점 찾기
    vector<int> LH(N + 1, 0), LP(N + 1, 0), LS(N + 1, 0);
    vector<int> RH(N + 1, 0), RP(N + 1, 0), RS(N + 1, 0);
    
    for (int i = 1; i <= N; i++) {
        LH[i] = LH[i - 1] + (B[i - 1] == 'S');
        LP[i] = LP[i - 1] + (B[i - 1] == 'H');
        LS[i] = LS[i - 1] + (B[i - 1] == 'P');
    }
    
    for (int i = N - 1; i >= 0; i--) {
        RH[i] = RH[i + 1] + (B[i] == 'S');
        RP[i] = RP[i + 1] + (B[i] == 'H');
        RS[i] = RS[i + 1] + (B[i] == 'P');
    }
    
    // 최적의 변경 지점 찾기
    int max_win = max({winH, winP, winS});
    for (int k = 1; k < N; k++) {
        max_win = max({max_win,
                       LH[k] + RP[k],
                       LH[k] + RS[k],
                       LP[k] + RH[k],
                       LP[k] + RS[k],
                       LS[k] + RH[k],
                       LS[k] + RP[k]});
    }
    
    return max_win;
}

int main() {
    int N;
    cin >> N;
    vector<Move> B(N);
    for (int i = 0; i < N; i++) {
        cin >> B[i];
    }
    
    cout << max_wins(B) << endl;
    return 0;
}