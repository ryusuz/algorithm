// week16-2 게임 맵 최단거리
#include<vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int dx[4] = {-1, 1, 0 , 0};
int dy[4] = {0, 0, -1, 1};

int solution(vector<vector<int> > maps)
{
    int answer = 0;
    int n = maps.size();
    int m = maps[0].size();
    vector<vector<int>> dist(n, vector<int>(m, -1)); // default : 0
    
    // bfs
    queue<pair<int, int>> q;
    q.push(make_pair(0,0));
    dist[0][0] = 1;
    
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        
        if (y == n-1 && x == m-1) break;
        
        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            
            if (ny < 0 || ny > n-1 || nx < 0 || nx > m-1) continue;
            
            if (maps[ny][nx] == 0) continue;
            
            if (dist[ny][nx] == -1 || dist[ny][nx] > dist[y][x] + 1) {
                q.push(make_pair(ny, nx));
                dist[ny][nx] = dist[y][x] + 1;
            }
        }
    }
        
    return dist[n-1][m-1];
}