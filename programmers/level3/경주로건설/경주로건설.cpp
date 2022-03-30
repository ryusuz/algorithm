// 22.03.24. 경주로 건설
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int dr[4]={0,1,0,-1};
int dc[4]={1,0,-1,0};
int visited[30][30]={0,};
int cost[30][30]={0,};

int n;
int st=0; int co=0;
int sum=0;
int minv=2100000000;
int tsum;
vector<vector<int>> tboard;

void dfs(int r,int c,int d,int tsum) {
    
    if(cost[r][c]!=0 && (tsum>cost[r][c]) ) return;
    if(tsum<=cost[r][c]) cost[r][c]=tsum;
    
    if(r==n-1 && c==n-1)
    {
        if(minv>tsum) 
            minv=tsum;
        return;
    }
    
    for(int i=0;i<4;i++)
    {
        int nr=r+dr[i];
        int nc=c+dc[i];
        
        if((nr>=0 && nr <=n-1) && (nc>=0 && nc<=n-1))
        if(tboard[nr][nc]!=1 && visited[nr][nc]==0)
        {
            visited[nr][nc]=1;
           if(d==i) {
            dfs(nr,nc,d,tsum+100);
           }
            else {
                if(!(r==0 && c==0))
                 tsum+=500;
                dfs(nr,nc,i,tsum+100);
                if(!(r==0 && c==0))
                    tsum-=500;
            }
            visited[nr][nc]=0;
           
        }
    }
}

int solution(vector<vector<int>> board) {
    int answer = 0;
    tboard=board;
    n=board.size();
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cost[i][j]=2100000000;
    visited[0][0]=1;
    dfs(0,0,0,0);
   
    answer=minv;
    return answer;
} 






// dfs
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
    }
    if (y == N-1 && x == N-1) {
        answer = (answer > cost) ? cost : answer;
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