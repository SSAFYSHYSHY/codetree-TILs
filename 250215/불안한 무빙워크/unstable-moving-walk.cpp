#include <iostream>
#include <tuple>
#include <algorithm>

using namespace std;

int n, k;
pair<int, bool> u[101], d[101]; // (내구도, 로봇 존재 여부)

void Shift() {
    pair<int, bool> temp = u[n - 1];  // 위쪽 벨트 마지막 값 저장

    // 위쪽 벨트 이동
    for (int i = n - 1; i > 0; i--) {
        u[i] = u[i - 1];
    }
    u[0] = d[n - 1]; // 아래쪽 마지막 칸이 위쪽 첫 번째 칸으로 이동

    // 아래쪽 벨트 이동
    for (int i = n - 1; i > 0; i--) {
        d[i] = d[i - 1];
    }
    d[0] = temp; // 위쪽 마지막 값이 아래쪽 첫 번째 칸으로 이동

    // n-1 번째 칸에서 로봇 제거 (내리는 위치)
    u[n - 1].second = false;
}

void MoveAll() {
    for (int i = n - 2; i >= 0; i--) { // 뒤에서부터 로봇 이동
        if (u[i].second && !u[i + 1].second && u[i + 1].first > 0) {
            u[i + 1].second = true; // 로봇 이동
            u[i + 1].first--; // 내구도 감소
            u[i].second = false; // 기존 위치 비우기
        }
    }
    u[n - 1].second = false; // 내리는 위치에서 로봇 제거
}

void Add() {
    if (u[0].first > 0) { // 첫 번째 위치에 내구도가 남아 있다면
        u[0].second = true; // 로봇 추가
        u[0].first--; // 내구도 감소
    }
}

bool Check() {
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (u[i].first == 0) cnt++;
        if (d[i].first == 0) cnt++;
    }
    return cnt >= k; // 내구도가 0인 칸이 k개 이상이면 종료
}

int main() {
    cin >> n >> k;

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        u[i] = { a, false }; // 내구도와 로봇 여부
    }

    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        d[i] = { a, false };
    }

    int trial = 0;
    while (!Check()) {
        Shift();
        MoveAll();
        Add();
        trial++;
    }

    cout << trial;
}