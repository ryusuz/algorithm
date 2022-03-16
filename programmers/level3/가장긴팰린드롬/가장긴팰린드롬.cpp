// 22.03.15. 가장 긴 팰린드롬 (DP)
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int solution(string s)
{
    int answer = 1;
    int len = s.size();
        
    vector<vector<int>> dp(len, vector<int> (len, 0));
    
    for(int i = 0; i < len; i++) {
        dp[i][i] = 1;
    }
    
    for(int i = 0; i < len - 1; i++) {
        if(s[i] == s[i+1]) {
            dp[i][i+1] = 1;
            answer = 2;
        }
    }
    
    for(int k = 3; k <= len; k++) {
        for(int i = 0; i <= len-k; i++) {
            int j = i + k - 1;
            
            if (s[i] == s[j] && dp[i+1][j-1] == 1) {
                dp[i][j] = 1;
                answer = max(answer, k);
            }
        }
    }

    return answer;
}