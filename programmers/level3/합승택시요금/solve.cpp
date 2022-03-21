// 22.03.21. 합승택시요금 (플로이드 와샬)
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    int answer = 0;
    
    vector<vector<int>> dp(n+1, vector<int> (n+1, 0));
    
    for(auto f : fares) {
        dp[f[0]][f[1]] += f[2];
        dp[f[1]][f[0]] += f[2];
    }
    
    for(int j = 1; j < n+1; j++) {          // 거치는 애
        for(int i = 1; i < n+1; i++) {      // 시작  
            for(int k = 1; k < n+1; k++) {  // 종료
                if (i == k) continue;
                
                if (dp[i][j] && dp[j][k]) {
                    if (dp[i][k] == 0 || dp[i][k] > dp[i][j] + dp[j][k]) {
                        dp[i][k] = dp[i][j] + dp[j][k];
                    }
                }
                    
            }
        }
    }
    
    answer = dp[s][a] + dp[s][b];
    
    for(int j = 1; j < n+1; j++) {
        if (!dp[s][j]) continue;
        
        int tmp = dp[s][j] + dp[j][a] + dp[j][b];
        
        if (answer > tmp) answer = tmp;
    }
    
    return answer;
}
