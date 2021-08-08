//week11-21 평균 구하기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

double solution(vector<int> arr) {
    double answer = 0;
    
    for (auto& num : arr) {
        answer += num;
    }
    
    return answer / arr.size();
}