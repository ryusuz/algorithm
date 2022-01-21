// 21.11.11 주식가격

#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    for (int i = 0; i < prices.size()-1; i++) {
        int cur = prices[i];
        int ans = 0;
        for (int j = i+1; j < prices.size(); j++) {
            ans++;
            if (cur > prices[j]) break;
        }
        
        answer.push_back(ans);
    }
    
    answer.push_back(0);
    
    return answer;
}