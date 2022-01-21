//week8-2 위장(해시)
#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 1;
    
    // 1. 해시 초기화
    unordered_map<string, int> m;
    
    for (auto& elem : clothes) {
        m[elem[1]] += 1;
    }
    
    for (auto& elem : m) {
        answer *= elem.second + 1;
    }
    
    
    return answer - 1;
}