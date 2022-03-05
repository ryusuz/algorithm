// 22.03.05. 최고의 집합
#include <string>
#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
        
    if (n > s) return {-1};
    
    // 비슷한 값들끼리 모여있어야 값이 가장 큼
    
    for(int i = 0; i < n; i++) answer.push_back(s / n);
    
    for(int i = 1; i <= s % n; i++) answer[n - i]++;
    
    return answer;
}