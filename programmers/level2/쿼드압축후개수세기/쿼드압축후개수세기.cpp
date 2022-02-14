// 22. 02. 14. 쿼드압축후개수세기 (분할정복)
#include <string>
#include <vector>
#include <iostream>
using namespace std;

void dfs(int x, int y, int size, vector<vector<int>> &arr, vector<int> &answer) {
    bool zero = true, one = true;
    
    for(int i = x; i < x+size; i++) {
        for(int j = y; j < y+size; j++) {
            if (arr[i][j] == 1) zero = false;
            if (arr[i][j] == 0) one = false;
        }
    }
    
    if(zero) {
        answer[0]++;
        return;
    }
    
    if(one) {
        answer[1]++;
        return;
    }
        
    dfs(x, y, size/2, arr, answer);
    dfs(x, y + size/2, size/2, arr, answer);
    dfs(x + size/2, y, size/2, arr, answer);
    dfs(x + size/2, y + size/2, size/2, arr, answer);
}

vector<int> solution(vector<vector<int>> arr) {
    vector<int> answer(2, 0);
    
    dfs(0, 0, arr.size(), arr, answer);
    
    
    return answer;
}