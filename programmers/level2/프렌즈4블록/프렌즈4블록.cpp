// 22.02.23. 프렌즈 4 블록
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

int dy[3] = {1, 0, 1};
int dx[3] = {0, 1, 1};
vector<pair<int, int>> points;

bool check(int y, int x, vector<string> &board) {
    char block = board[y][x];
    
    for(int i = 0; i < 3; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        
        if (ny >= board.size() || nx >= board[0].size()) return false;
        
        if (block != board[y+dy[i]][x+dx[i]]) return false;
    }
    
    points.push_back({y, x});
    return true;
}

int removeBlock(vector<string> &board) {
    int ret = 0;
    
    for(int i = 0; i < points.size(); i++) {
        int y = points[i].first, x = points[i].second;
        
        if (board[y][x] != '.') {
            ret++;
            board[y][x] = '.';
        }
        
        for(int j = 0; j < 3; j++) {
            int ny = y + dy[j], nx = x + dx[j];
            
            if (board[ny][nx] != '.') {
                ret++;
                board[ny][nx] = '.';
            }
        }

    }
    
    return ret;
}

void pushBlock(int m, int n, vector<string> &board) {
        
    for(int i = 0; i < n; i++) {
        bool flag = false;
        queue<pair<int, int>> q;
        
        for(int j = m - 1; j >= 0; j--) {
            if (!flag && board[j][i] != '.') continue;
            
            if (board[j][i] == '.') {
                flag = true;
                q.push({j, i});
                continue;
            }
            
            int y = q.front().first;
            int x = q.front().second;
            q.pop();
            
            board[y][x] = board[j][i];
            board[j][i] = '.';
            q.push({j, i});
        }
    }
}

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    bool flag = false;
    
    while (!flag) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if (board[i][j] == '.') continue;
                
                if(check(i, j, board)) flag = true;
            }
        }
        if (!flag) break;
        
        answer += removeBlock(board);
        points.clear();

        pushBlock(m, n, board);

        flag = false;
    }
        
    return answer;
}