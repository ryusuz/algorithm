// 22.03.23. N-Queen (백트래킹)
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int N;
int answer;
vector<int> col;

bool check(int row) {
    for(int i = 1; i < row; i++) {
        if (col[i] == col[row]) return false;
        
        if (abs(col[i] - col[row]) == abs(i - row)) return false;
    }
    
    return true;
}

void dfs(int row) {    
    if (row > N) {
        answer++;
        return;
    } 
    
    for(int i = 1; i <= N; i++) {
        col[row] = i;

        if (check(row)) dfs(row+1);
        else col[row] = 0;
    }
}

int solution(int n) {
    answer = 0;
    N = n;
    col = vector<int>(n+1, 0);
    
    dfs(1);
    
    return answer;
}