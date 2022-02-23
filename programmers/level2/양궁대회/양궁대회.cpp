// 22.02.23. 양궁대회
#include <string>
#include <vector>
using namespace std;

vector<int> answer(1, -1);
int maxDiff;

bool isBetter(vector<int> &ryan) {
    for(int i = 10; i >= 0; i--) {
        if(ryan[i] > answer[i]) return true;
        else if (ryan[i] < answer[i]) return false;
    }
}

void calScore(vector<int> &ryan, vector<int> &apeach) {
    int ryan_score = 0, apeach_score = 0;
    
    for(int i = 0; i < 11; i++) {
        if(ryan[i] > apeach[i]) ryan_score += (10 - i);
        else if(apeach[i] > 0) apeach_score += (10 - i);
    }
    
    int diff = ryan_score - apeach_score;
    
    if(diff > 0 && diff >= maxDiff) {
        if(diff == maxDiff && !isBetter(ryan)) return;
        
        maxDiff = diff;
        answer = ryan;
    }
}

void dfs(int idx, int arrows, vector<int> &ryan, vector<int> &apeach) {
    if (idx == 11 || arrows == 0) {
        ryan[10] += arrows;
        calScore(ryan, apeach);     // 점수 계산
        ryan[10] -= arrows;
        
        return;
    }
    
    if (apeach[idx] < arrows) {
        ryan[idx] = apeach[idx] + 1;
        dfs(idx + 1, arrows - ryan[idx], ryan, apeach);
        ryan[idx] = 0;
    }
    
    dfs(idx + 1, arrows, ryan, apeach);
}

vector<int> solution(int n, vector<int> info) {
    vector<int> ryan(11, 0);
    
    dfs(0, n, ryan, info);
    
    return answer;
}