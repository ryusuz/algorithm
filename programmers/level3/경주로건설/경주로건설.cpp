// 22.03.24. 경주로 건설
#include <string>
#include <vector>
#include <climits>
#include <iostream>

using namespace std;

int N;
int answer;

int dp[26][26];
int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
bool visit[26][26] = {false};

void dfs(int y, int x, int d, int cost, vector<vector<int>> board) {
    if (dp[y][x] != INT_MAX && cost > dp[y][x]) return;
    
    if (cost <= dp[y][x]) {
        dp[y][x] = cost;
        cout << y << "," << x << " :: " << cost << endl;
    }
    if (y == N-1 && x == N-1) {
        answer = (answer > cost) ? cost : answer;
        cout << "total! " << cost << endl;
        return;
    }
    
    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny < 0 || nx < 0 || ny >= N || nx >= N) continue;
        
        if (!visit[ny][nx] && board[ny][nx] == 0) {
            visit[ny][nx] = true;
            
            if (d == i) dfs(ny, nx, d, cost+100, board);
            else {
                if (!(y == 0 && x == 0)) cost += 500;
                dfs(ny, nx, i, cost+100, board);
                if (!(y == 0 && x == 0)) cost -= 500;
            }
            
            visit[ny][nx] = false;
        }
    }
    
}

int solution(vector<vector<int>> board) {
    answer = INT_MAX;
    N = board.size();
    
    for(int i = 0; i < 26; i++) {
        for(int j = 0; j < 26; j++)
            dp[i][j] = INT_MAX;
    }
    
    visit[0][0] = true;
    dfs(0, 0, 0, 0, board);
    
    return answer;
}