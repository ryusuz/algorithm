// 22.02.15. h-index
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) { 
    int answer = citations.size();
    
    sort(citations.begin(), citations.end());
    
    for(int i = 0; i < citations.size(); i++) {
        if (citations[i] >= answer) break;
        answer--;
    }
    
    return answer;
}
