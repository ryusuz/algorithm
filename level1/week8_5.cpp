//week8_6 체육복
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {    
    for (int i = 0; i < reserve.size(); i++) {
        for (int j = 0; j < lost.size(); j++) {
            if (reserve[i] == lost[j]) {
                lost.erase(lost.begin() + j);
                reserve[i] = -1;
            }
        }
    }
    
    int answer = n - lost.size();
    
    for (int l : lost) {
        for (int i = 0; i < reserve.size(); i++) {
            if (reserve[i] == -1) continue;
            
            if (l == reserve[i] - 1) {
                answer++;
                reserve[i] = -1;
                break;
            } else if (l == reserve[i] + 1) {
                answer++;
                reserve[i] = -1;
                break;
            }
        }
    }
    
    return answer;
}