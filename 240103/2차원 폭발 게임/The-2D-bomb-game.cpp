#include <iostream>

#define MAX_NUM 100
#define BLANK -1
#define WILL_EXPLODE 0

using namespace std;

int n, m, k, end_of_numbers_1d, end_of_temp_1d;
int numbers_2d[MAX_NUM][MAX_NUM];
int numbers_1d[MAX_NUM];
int temp_2d[MAX_NUM][MAX_NUM];
int temp_1d[MAX_NUM];

int GetEndIdxOfExplosion(int start_idx, int curr_num) {
    int end_idx = start_idx + 1;
    while(end_idx < end_of_numbers_1d) {
        if(numbers_1d[end_idx] == curr_num)
            end_idx++;
        else{
            break;
        }
    }

    return end_idx - 1;
}

void FillZero(int start_idx, int end_idx) {
    for(int i = start_idx; i <= end_idx; i++) {
        numbers_1d[i] = WILL_EXPLODE;
    }
}

void MoveToTemp() {
    end_of_temp_1d = 0;
    for(int i = 0; i < end_of_numbers_1d; i++) {
        if(numbers_1d[i] != WILL_EXPLODE) {
            temp_1d[end_of_temp_1d++] = numbers_1d[i];
        }
    }
}

void CopyFromTemp() {
    end_of_numbers_1d = end_of_temp_1d;
    for(int i = 0; i < end_of_numbers_1d; i++) {
        numbers_1d[i] = temp_1d[i];
    }
}

void Explode() {

    bool did_explode;
    do {
        did_explode = false;
        for(int curr_idx = 0; curr_idx < end_of_numbers_1d; curr_idx++) {  

            if(numbers_1d[curr_idx] == WILL_EXPLODE) { 
                continue;
            }

            int end_idx = GetEndIdxOfExplosion(curr_idx, numbers_1d[curr_idx]);

            if(end_idx - curr_idx + 1 >=  m) {
                FillZero(curr_idx, end_idx);
                did_explode = true;
            }
        }
        MoveToTemp();
        CopyFromTemp();       
    }
    while(did_explode); 

}

void CopyColumn(int col){
    end_of_numbers_1d = 0;
    for(int i = 0; i < n; i++)
        if(numbers_2d[i][col] != BLANK)
            numbers_1d[end_of_numbers_1d++] = numbers_2d[i][col];

    return;
}

void CopyResult(int col){
    int result_idx = end_of_numbers_1d - 1;
    for(int i = n - 1; i >= 0; i--) {
        if(result_idx >= 0)
            numbers_2d[i][col] = numbers_1d[result_idx--];
        else
            numbers_2d[i][col] = BLANK;
    }
}

void Simulate() {
    for(int col = 0; col < n; col++) {
        CopyColumn(col);
        Explode();
        CopyResult(col);
    }
}

void Rotate() {
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            temp_2d[i][j] = BLANK;

    int curr_idx;
    for(int i = n - 1; i >= 0; i--) {
        curr_idx = n - 1;
        for(int j = n - 1; j >= 0; j--) {
            if(numbers_2d[i][j] != BLANK)
                temp_2d[curr_idx--][n - i - 1] = numbers_2d[i][j];
        }
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            numbers_2d[i][j] = temp_2d[i][j];
}

int main() {
    cin >> n >> m >> k;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            cin >> numbers_2d[i][j];

    Simulate();
    for(int i = 0; i < k; i++) {
        Rotate();
        Simulate();
    }

    int answer = 0;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            if(numbers_2d[i][j] != BLANK)
                answer++;
    
    cout << answer;


    return 0;
}