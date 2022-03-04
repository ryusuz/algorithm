// 22.03.04. 등굣길
#include <string>
#include <vector>

using namespace std;

// m == x, n == y
int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    
    for(auto p : puddles) {
        dp[p[1]][p[0]] = -1;
    }
    
    dp[1][1] = 1;
    
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++) {
            int a = 0;
            int b = 0;
            
            if(dp[i][j] == -1) continue;
            
            if(dp[i-1][j] != -1) a = dp[i-1][j];
            
            if(dp[i][j-1] != -1) b = dp[i][j-1];
            
            dp[i][j] += (a+b) % 1000000007;
        }
    }
    
    return dp[n][m];
}