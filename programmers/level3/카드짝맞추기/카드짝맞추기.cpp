// 22.03.28. 카드 짝 맞추기 (BFS)
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;
typedef pair<pair<int, int>, int> ppi;

int r, c;
vector<vector<int>> board;
int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

bool checkBoundary(int i, int j) {
    if (i < 0 || j < 0 || i > 3 || j > 3) return false;
    return true;
}

int bfs(int dest) {
    queue<ppi> q;
    q.push({{r, c}, 0});
    
    bool check[4][4] = {false};
    check[r][c] = true;
    
    while (!q.empty()) {
        int y = q.front().first.first;
        int x = q.front().first.second;
        int cnt = q.front().second;
        q.pop();
        
        if (board[y][x] == dest) {
            board[y][x] = 0;
            r = y, c = x;
            return cnt + 1;
        }
        
        // 양옆 이동
        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (!checkBoundary(ny, nx)) continue;
            
            if (!check[ny][nx]) {
                q.push({{ny, nx}, cnt + 1});
                check[ny][nx] = true;
            }
        }
        
        // 가장 가까운 카드로 이동
        for(int i = 0; i < 4; i++) {
            int ny = y;
            int nx = x;
            
            while (checkBoundary(ny + dy[i], nx + dx[i])) {
                ny += dy[i];
                nx += dx[i];
                
                if (board[ny][nx]) break;
            }
            
            if (!check[ny][nx]) {
                q.push({{ny, nx}, cnt + 1});
                check[ny][nx] = true;
            }
        }
    }
}

int solution(vector<vector<int>> b, int rr, int cc) {
    int answer = 1e9;
    
    vector<int> cards;
    bool num[7] = {false};
    
    for(auto v : b)
        for(auto i : v)
            num[i] = true;
    
    for(int i = 1; i < 7; i++) {
        if (num[i]) cards.push_back(i);
    }
        
    do {
        board = b;
        r = rr, c = cc;
        int tmp = 0;
        
        for(int i = 0; i < cards.size(); i++) {
            tmp += bfs(cards[i]);
            tmp += bfs(cards[i]);
        }
        
        answer = min(answer, tmp);
    } while (next_permutation(cards.begin(), cards.end()));
    
    return answer;
}