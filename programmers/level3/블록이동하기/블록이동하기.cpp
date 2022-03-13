// 22.03.12. 블록 이동하기 bfs
#include <vector>
#include <queue>
using namespace std;
struct Robot { 
    int move;
    int dir;
    int x;
    int y;
};

int solution(vector<vector<int>> board) {
    int len = board.size();
    int dir1[4][2] = {{0, 2},{1,0},{0,-1},{-1,0}};
    int dir2[4][2] = {{2,0},{0,-1},{-1,0},{0,1}};
    int MIN[100][100][2];
    
    for(int i = 0; i < len; i++) {
        for(int j = 0; j < len; j++) {
            for(int k = 0; k < 2; k++) {
                MIN[i][j][k] = 987654321;
            }
        }
    }
    
    MIN[0][0][0] = 0;
    queue<Robot> q;
    q.push({0,-1,0,0});
    
    while(!q.empty()) {
        Robot now = q.front();
        q.pop();
        
        if(now.dir == -1){
            // 가로 방향
            
            if(now.x == len - 1 && now.y == len - 2) return now.move;
            
            for(int i = 0; i < 4; i++) {
                int nx = now.x + dir1[i][0];
                int ny = now.y + dir1[i][1];
                
                if(nx < 0 || ny < 0 || nx >= len || ny >= len || board[nx][ny] == 1) continue;
            
                switch(i) {
                    case 0:
                        if(MIN[nx][ny - 1][0] > now.move + 1){
                            MIN[nx][ny - 1][0] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx, ny - 1});
                        } break;
                    case 1:
                        if(board[nx][ny + 1] == 0){
                            if(MIN[now.x][now.y][1] > now.move + 1){
                                MIN[now.x][now.y][1] = now.move + 1;
                                q.push({now.move + 1, -now.dir, now.x, now.y});
                            }
                            
                            if(MIN[now.x][now.y + 1][1] > now.move + 1){
                                MIN[now.x][now.y + 1][1] = now.move + 1;
                                q.push({now.move + 1, -now.dir, now.x, now.y + 1});
                            }
                            
                            if(MIN[nx][ny][0] > now.move + 1){
                                MIN[nx][ny][0] = now.move + 1;
                                q.push({now.move + 1, now.dir, nx, ny});
                            }
                        } break;
                    case 2:
                        if(MIN[nx][ny][0] > now.move + 1){
                            MIN[nx][ny][0] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx, ny});
                        } break;
                    case 3:
                        if(board[nx][ny + 1] == 0){
                            if(MIN[nx][ny][1] > now.move + 1){
                                MIN[nx][ny][1] = now.move + 1;
                                q.push({now.move + 1, -now.dir, nx, ny});
                            }
                            
                            if(MIN[nx][ny + 1][1] > now.move + 1){
                                MIN[nx][ny + 1][1] = now.move + 1;
                                q.push({now.move + 1, -now.dir, nx, ny + 1});
                            }
                            
                            if(MIN[nx][ny][0] > now.move + 1){
                                MIN[nx][ny][0] = now.move + 1;
                                q.push({now.move + 1, now.dir, nx, ny});
                            }
                        } break;
                }
            } 
        } else { // 세로 방향
            if(now.x == len - 2 && now.y == len - 1) return now.move;
            
            for(int i = 0; i < 4; i++) {
                int nx = now.x + dir2[i][0];
                int ny = now.y + dir2[i][1];
                
                if(nx < 0 || ny < 0 || nx >= len || ny >= len || board[nx][ny] == 1) continue;
                
                switch(i) {
                    case 0:
                        if(MIN[nx - 1][ny][1] > now.move + 1){
                            MIN[nx - 1][ny][1] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx - 1, ny});
                        } break;
                    case 1:
                        if(board[nx + 1][ny] == 0){
                            if(MIN[nx][ny][0] > now.move + 1){
                                MIN[nx][ny][0] = now.move + 1;
                                q.push({now.move + 1, -now.dir, nx, ny});
                            }
                            
                            if(MIN[nx + 1][ny][0] > now.move + 1){
                                MIN[nx + 1][ny][0] = now.move + 1;
                                q.push({now.move + 1, -now.dir, nx + 1, ny});
                            }
                            
                            if(MIN[nx][ny][1] > now.move + 1){
                                MIN[nx][ny][1] = now.move + 1;
                                q.push({now.move + 1, now.dir, nx, ny});
                            }
                        } break;
                    case 2:
                        if(MIN[nx][ny][1] > now.move + 1){ 
                            MIN[nx][ny][1] = now.move + 1;
                            q.push({now.move + 1, now.dir, nx, ny});
                        } break;
                    case 3:
                        if(board[nx + 1][ny] == 0){
                            if(MIN[now.x][now.y][0] > now.move + 1){
                                MIN[now.x][now.y][0] = now.move + 1;
                                q.push({now.move + 1, -now.dir, now.x, now.y});
                            }
                            
                            if(MIN[now.x + 1][now.y][0] > now.move + 1){
                                MIN[now.x + 1][now.y][0] = now.move + 1;
                                q.push({now.move + 1, -now.dir, now.x + 1, now.y});
                            }
                            
                            if(MIN[nx][ny][1] > now.move + 1){
                                MIN[nx][ny][1] = now.move + 1;
                                q.push({now.move + 1, now.dir, nx, ny});
                            }
                        } break;
                }
            } 
        } 
    } 
}


// 나의 틀린 풀이...... ㅠ 6번 테케만 안 맞는다 .. 다시 풀어보자
#include <string>
#include <vector>
#include <queue>
#include <map>
#include <iostream>
using namespace std;

int N;

struct Point {
    // 왼 or 위
    int y1;
    int x1;
    
    // 오 or 아래
    int y2;
    int x2;
    
    bool operator < (const Point &var) const {
        if (y1 != var.y1) return y1 < var.y1;
        if (x1 != var.x1) return x1 < var.x1;
        if (y2 != var.x2) return y2 < var.y2;
        if (x2 != var.x2) return x2 < var.x2;
    }
};

bool isExist(Point p) {
    if (p.y1 < 0 || p.y1 >= N || p.x1 < 0 || p.x1 >= N) return false;
    if (p.y2 < 0 || p.y2 >= N || p.x2 < 0 || p.x2 >= N) return false;
    
    return true;
}

int bfs(Point start, vector<vector<int>> board) {
    queue<Point> q;
    q.push(start);
        
    map<Point, int> visit;
    visit[start] = 1;
        
    bool check;      // true면 가로, false면 세로
    
    while(!q.empty()) {
        Point curr = q.front();
        q.pop();
        
        int y1 = curr.y1;
        int x1 = curr.x1;
        int y2 = curr.y2;
        int x2 = curr.x2;
        
        if (y2 == N-1 && x2 == N-1) return visit[curr];
        
        if(x2 - x1 == 1) check = true;  // 가로
        else check = false;             // 세로
        
        Point left({y1, x1 - 1, y2, x2 - 1 });      // 0 0 -1 -1
        Point right({y1, x1 + 1, y2, x2 + 1});      // 0 1 0 1
        Point up({y1 - 1, x1, y2 - 1, x2});         // -1 0 -1 0
        Point down({y1 + 1, x1, y2 + 1, x2});  
        
        if(check) {            
            Point r1_up({y2 - 1, x2 - 1, y1, x1});
            Point r2_up({y1 - 1, x1 + 1, y2, x2});
            Point r1_down({y1, x1, y2 + 1, x2 - 1});
            Point r2_down({y2, x2, y1 + 1, x1 + 1});
            
            if (isExist(left) && !visit[left] && board[left.y1][left.x1] == 0) {
                q.push(left);
                visit[left] = visit[curr] + 1;
            }
            
            if (isExist(right) && !visit[right] && board[right.y2][right.x2] == 0) {
                q.push(right);
                visit[right] = visit[curr] + 1;
            }
            
            
            if (isExist(up) && !visit[up] && board[up.y1][up.x1] == 0 && board[up.y2][up.x2] == 0) {
                q.push(up);
                visit[up] = visit[curr] + 1;
                
                if (!visit[r1_up]) {
                    q.push(r1_up);
                    visit[r1_up] = visit[curr] + 1;
                }
                
                if (!visit[r2_up]) {
                    q.push(r2_up);
                    visit[r2_up] = visit[curr] + 1;
                }
                
            }
            
            if (isExist(down) && !visit[down] && board[down.y1][down.x1] == 0 && board[down.y2][down.x2] == 0) {
                q.push(down);
                visit[down] = visit[curr] + 1;
                
                if (!visit[r1_down]) {
                    q.push(r1_down);
                    visit[r1_down] = visit[curr] + 1;
                }
                
                if (!visit[r2_down]) {
                    q.push(r2_down);
                    visit[r2_down] = visit[curr] + 1;
                }
            }
            
        } else {
            Point r1_right({y1, x1, y2 - 1, x2 + 1});
            Point r2_right({y2, x2, y1 + 1, x1 + 1});
            Point r1_left({y1 + 1, x1 - 1, y2, x2});
            Point r2_left({y2 - 1, x2 - 1, y1, x1});
            
            if (isExist(up) && !visit[up] && board[up.y1][up.x1] == 0) {
                q.push(up);
                visit[up] = visit[curr] + 1;
            }
            
            if (isExist(down) && !visit[down] && board[down.y2][down.x2] == 0) {
                q.push(down);
                visit[down] = visit[curr] + 1;
            }
            
            
            if (isExist(left) && !visit[left] && board[left.y1][left.x1] == 0 && board[left.y2][left.x2] == 0) {
                q.push(left);
                visit[left] = visit[curr] + 1;
                
                if (!visit[r1_left]) {
                    q.push(r1_left);
                    visit[r1_left] = visit[curr] + 1;
                }
                
                if (!visit[r2_left]) {
                    q.push(r2_left);
                    visit[r2_left] = visit[curr] + 1;
                }
                
            }
            
            if (isExist(right) && !visit[right] && board[right.y1][right.x1] == 0 && board[right.y2][right.x2] == 0) {
                q.push(right);
                visit[right] = visit[curr] + 1;
                
                if (!visit[r1_right]) {
                    q.push(r1_right);
                    visit[r1_right] = visit[curr] + 1;
                }
                
                if (!visit[r2_right]) {
                    q.push(r2_right);
                    visit[r2_right] = visit[curr] + 1;
                }
            }
            
        }
        
    }
    
    return 0;
    
}

int solution(vector<vector<int>> board) {
    int answer = -1;
    
    N = board.size();
    Point start({0, 0, 0, 1});
    
    answer += bfs(start, board);
    
    return answer;
}