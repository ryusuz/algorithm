//week11-4 나누어 떨어지는 숫자 배열
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    for (auto& num : arr) {
        if (num % divisor == 0) answer.push_back(num);
    }
    
    if (answer.size() == 0) answer.push_back(-1);
    else sort(answer.begin(), answer.end());
    
    return answer;
}

/// ==  return answer.empty() ? vector<int> (1, -1) : answer;