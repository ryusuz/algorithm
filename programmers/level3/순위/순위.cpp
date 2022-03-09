// 22.03.09. 순위 (플로이드 와샬)
#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<bool>> graph(n+1, vector<bool>(n+1, false));
    
    // 그래프 생성
    for(auto r : results) {
        int winner = r[0];
        int loser = r[1];
        
        graph[winner][loser] = true;
    }
    
    // 플로이드 와샬 알고리즘 적용
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            for(int k = 1; k <= n; k++) {
                if (graph[j][i] && graph[i][k]) graph[j][k] = true;
            }
        }
    }
    
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for(int j = 1; j <= n; j++) {
            if(i == j) continue;

            if(graph[i][j] || graph[j][i]) cnt++;
        }
        if (cnt == n-1) answer++;
    }

    return answer;
}