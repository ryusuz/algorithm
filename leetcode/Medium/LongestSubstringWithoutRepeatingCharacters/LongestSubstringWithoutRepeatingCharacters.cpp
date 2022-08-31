#include <iostream>
#include <map>
#include <string>
#include <algorithm>

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int answer = 0;
        
        map<char, int> m;
        
        for(int i = 0; i < s.size(); i++) {
            m[s[i]]++;
            
            for(int j = i+1; j < s.size(); j++) {
                if (m.find(s[j]) == m.end()) {
                    m[s[j]]++;
                    continue;
                }

                answer = max(answer, m.size());
                m.clear();
                break;
            }
        }
        
        answer = max(answer, m.size());
        
        return answer;
    }

    int max(int a, int b) {
        if (a > b) return a;
        return b;
    }
    
};