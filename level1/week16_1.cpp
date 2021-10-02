// week16-1 복서 정렬하기(위클리 6주차)
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool cmp(vector<float> a, vector<float> b) {
    if (a[0] == b[0]) {
        if (a[1] == b[1]) {
            if (a[2] == b[2]) return a[3] < b[3];
            else return a[2] > b[2];
        } else {
            return a[1] > b[1];
        }
    } else {
        return a[0] > b[0];
    }
}

vector<int> solution(vector<int> weights, vector<string> head2head) {
    vector<int> answer;
    vector<vector<float>> info;
    
    for (int i = 0; i < head2head.size(); i++) {
        float lose = 0, win = 0;
        float heavy = 0;
        
        for (int j = 0; j < head2head[0].size(); j++) {
            if (i == j) continue;
            
            if (head2head[i][j] == 'L') lose++;
            else if (head2head[i][j] == 'W') {
                win++;
                if (weights[i] < weights[j]) heavy++;
            }
            
        }
        
        float rate = 0;
        if (win+lose > 0) {
            rate = win / (win + lose);
        } 
        vector<float> tmp = {rate, heavy, (float)weights[i], (float) i+1};
        info.push_back(tmp);
    }
    
    sort(info.begin(), info.end(), cmp);
    
    for(auto& elem : info) {
        answer.push_back(elem[3]);
    }
    
    
    return answer;
}


