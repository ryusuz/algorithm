//week5-2 소수 찾기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n) {
    int answer = 0;
    int num[n];
    vector<int> prime;
    
    for (int i = 2; i <= n; i++) {
        num[i] = i;
    }
    
    for (int i = 2; i <= n; i++) {
        if (num[i] == 0) continue;
        
        for (int j = i + i; j <= n; j += i) {
            num[j] = 0; 
        }
        
        prime.push_back(i);
        
    }
    
    answer = prime.size();
    
    return answer;
}