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

//다른 사람 풀이
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> temp;

    for(int i = 0; i < commands.size(); i++) {
        temp = array;
        sort(temp.begin() + commands[i][0] - 1, temp.begin() + commands[i][1]);
        answer.push_back(temp[commands[i][0] + commands[i][2]-2]);
    }

    return answer;
}