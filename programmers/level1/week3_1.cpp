// week3-1 음양더하기
#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    while (!absolutes.empty()) {
        bool is_positive = signs.back();
        signs.pop_back();
        
        if (is_positive) {
            answer += absolutes.back();
            absolutes.pop_back();
        } else {
            answer -= absolutes.back();
            absolutes.pop_back();
        }
    }
    
    return answer;
}