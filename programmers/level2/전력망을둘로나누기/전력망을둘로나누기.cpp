// 22.02.19. 전력망을 둘로 나누기

#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<bool> visited;
bool graph[101][101] = {false};


int dfs(int curr, int n) {
    if (visited[curr]) return 0;
    visited[curr] = true;
        
    int ret = 1;
    for(int next = 1; next <= n; next++) {
        if (!graph[curr][next]) continue;
        
        ret += dfs(next, n);
    }
    
    return ret;
    
}
int solution(int n, vector<vector<int>> wires) {
    int answer = n;
    
    // 그래프 초기화, 간선이 n-1개이므로 인접행렬그래프 => 서로에게 가는 방법 유일함
    for(int i = 0; i < wires.size(); i++) {
        int u = wires[i][0];
        int v = wires[i][1];
        graph[u][v] = graph[v][u] = true;
    }
        
    for(int i = 0; i < wires.size(); i++) {
        int u = wires[i][0];
        int v = wires[i][1];
        graph[u][v] = graph[v][u] = false;  // 간선 끊음
        
        vector<int> count;
        visited = vector<bool>(n+1, false);
        
        for(int j = 1; j <= n; j++) {
            int cnt = dfs(j, n);
            
            if(!cnt) continue;
            count.push_back(cnt);
        }
        
        answer = min(answer, abs(count[0] - count[1]));
        graph[u][v] = graph[v][u] = true;
        
    }
    
    return answer;
}