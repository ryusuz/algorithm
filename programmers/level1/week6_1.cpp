// week6-1 실패율
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    int people = stages.size();     // 사용자 수
    vector<int> count(N);
    vector<double> fail(N);
    
    // 각 스테이지별 클리어하지 못한 사람 수
    for (int stage : stages) {
        if (stage == N + 1) continue;
        count[stage - 1] += 1;
    }
    
    //스테이지 별 실패율
    for(int i = 0; i < N; i++) {
        if(count[i] == 0) fail[i] = 0;
        else fail[i] = (double)count[i] / people;
        people -= count[i];
    }
    
    while (answer.size() < N) {
        double max = *max_element(fail.begin(), fail.end());
        int max_index = max_element(fail.begin(), fail.end()) - fail.begin();

        answer.push_back(max_index + 1);
        
        fail[max_index] = -1;  
    }
    
    return answer;
}