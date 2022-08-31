class Solution {
public:
    string longestPalindrome(string s) {
        int len = 1;        
        string ans;
        
        bool dp[1001][1001] = {false};
        
        for(int i = 0; i < s.size(); i++) {
            dp[i][i] = true;
            ans = s[i];
        }
        
        for(int i = 0; i < s.size() - 1; i++) {
            if (s[i] == s[i+1]) {
                dp[i][i+1] = true;
                len = 2;
                ans = s.substr(i, 2);
            }
        }
        
        for(int i = 3; i <= s.size(); i++) {
            for(int st = 0; st < s.size() - i + 1; st++) {
                int end = st + i - 1;

                if (dp[st + 1][end - 1] && s[st] == s[end]) {
                    dp[st][end] = true;
                    
                    if (len < i) {
                        len = i;
                        ans = s.substr(st, len);

                    }
                }
            }
        }
                
        return ans;
        
        
    }
};