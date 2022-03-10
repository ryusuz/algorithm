// 22.03.10. 멀리 뛰기 (dp)
#include <string>
#include <vector>

using namespace std;

long long solution(int n) {
    long long answer = 0;
    
    int dp[2001];
    dp[1] = 1 % 1234567;
    dp[2] = 2 % 1234567;
    
    for(int i = 3; i <= n; i++) {
        dp[i] = (dp[i-1] + dp[i-2]) % 1234567;
    }
        
    return dp[n];
}