// 삼각달팽이 21.10.12.
#include <string>
#include <vector>
#include <iostream>
using namespace std;

// 0 1 2 3 (숫자 연속) 4 3 2
// 0 1 2 3 4 (숫자 연속) 5 4 3 2 3 (숫자 연속)
// 0 1 2 3 4 5 (숫자 연속) 6 5 4 3 2 3 4 (숫자 연속) 5
int dy[3] = {1, 0, -1};
int dx[3] = {0, 1, -1};

vector<int> solution(int n) {
    vector<int> answer;
    vector<vector<int>> tmp(n, vector<int>(n, 0));
    
    int var = 1;
    int y = -1, x = 0;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n-i; j++) {
            y += dy[i%3];
            x += dx[i%3];
            tmp[y][x] = var++;
        }
    }
    
    for (auto& v : tmp) {
        for (auto e : v) {
            if (e != 0) answer.push_back(e);
        }
    }
    
    return answer;
}