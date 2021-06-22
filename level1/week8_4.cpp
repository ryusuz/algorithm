//week8-4 K번째 수
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    
    for (int c = 0; c < commands.size(); c++) {
        int i = commands[c][0] - 1;
        int j = commands[c][1] - 1;
        int k = commands[c][2] - 1;
        vector<int> tmp;
        
        for(int a = i; a <= j; a++) {
            tmp.push_back(array[a]);
        }
        
        sort(tmp.begin(), tmp.end());
        
        answer.push_back(tmp[k]);
        
        
    }
    
    return answer;
}