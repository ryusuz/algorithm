// 22.03.06. 퍼즐 조각 맞추기
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
using namespace std;

/*
1. 게임보드 숫자들 변경
2. 게임보드 내의 비어있는 칸 알아내기
3. 테이블 내의 퍼즐 모양 알아내기 => 좌표값 => 0,0 기준으로 재정렬 필요
4. 퍼즐 회전하며 비어있는 칸과 같은지 체크
*/

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

vector<pair<int, int>> bfs(int y, int x, vector<vector<int>> &board, vector<vector<bool>> &visit) {
    vector<pair<int, int>> ret;
    
    int minX = x, minY = y;
    
    queue<pair<int, int>> q;
    q.push({y, x});
    ret.push_back({y, x});
    
    visit[y][x] = true;
    
    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny >= board.size() || nx < 0 || nx >= board[0].size() || board[ny][nx] == 0) continue;
            
            if (!visit[ny][nx]) {
                visit[ny][nx] = true;
                q.push({ny, nx});
                ret.push_back({ny, nx});
                
                if (minY > ny) minY = ny;
                if (minX > nx) minX = nx;
            }
        }
    }
    
    // 0,0 기준 정렬       
    for(auto& r : ret) {
        r.first -= minY;
        r.second -= minX;
    }
   
    return ret;
}

vector<pair<int, int>> rotate(vector<pair<int, int>> &board) {
    vector<pair<int, int>> ret;
    int minY = 50, minX = 50;
    
    for (auto i : board) {
        int y = i.first;
        int x = -i.second;
        ret.push_back({ x, y });
        
        if (minY > y) minY = y;
        if (minX > x) minX = x;
    }
    
    for(auto& p : ret) {
        p.first -= minX;
        p.second -= minY;
    }
    
    return ret;
}

bool isSame(vector<pair<int, int>> a, vector<pair<int, int>> b) {
    for(int i = 0; i < a.size(); i++) {
        if (a[i].first != b[i].first) return false;
        
        if (a[i].second != b[i].second) return false;
    }
    
    return true;
}


int solution(vector<vector<int>> game_board, vector<vector<int>> table) {
    int answer = 0;
    
    // 1. 게임 보드 반전
    for(auto& v : game_board) {
        for(auto& n : v) n = (n == 0) ? 1 : 0;
    }
    
    // 2~3. 게임보드 빈칸, 테이블 퍼즐 알아내기 (bfs)
    vector<vector<pair<int, int>>> blank;
    vector<vector<bool>> visit(50, vector<bool>(50, false));
    
    vector<vector<pair<int, int>>> puzzle;
    vector<vector<bool>> visit2(50, vector<bool>(50, false));
    
    for(int i = 0; i < game_board.size(); i++) {
        for(int j = 0; j < game_board[0].size(); j++) {
            if (!visit[i][j] && game_board[i][j] == 1)
                blank.push_back(bfs(i, j, game_board, visit));
            
            if (!visit2[i][j] && table[i][j] == 1)
                puzzle.push_back(bfs(i, j, table, visit2));
        }
    }
    
    // 4. 퍼즐 돌려서 맞춰보기
    bool check[1000] = {false};
    
    for(auto& b : blank) {
        sort(b.begin(), b.end());
        int bsize = b.size();
        bool flag = false; 
        
        for(int i = 0; i < puzzle.size(); i++) {
            auto p = puzzle[i];
            if (check[i] || p.size() != bsize) continue;

            for(int j = 0; j < 4; j++) {
                sort(p.begin(), p.end());

                if(isSame(b, p)) {
                    answer += bsize;
                    check[i] = true;
                    flag = true;
                    break;
                }
                p = rotate(p);
            }
            
            if (flag) break;
        }
    }
    
    return answer;
}