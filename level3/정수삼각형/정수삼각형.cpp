// 정수삼각형 21.11.18.

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    int dp[500][500] = {0,};
    dp[0][0] = triangle[0][0];
    
    for (int i = 0; i < triangle.size()-1; i++) {
        for (int j = 0; j < triangle[i].size(); j++) {
            int left = dp[i][j] + triangle[i+1][j];
            if (dp[i+1][j] < left) dp[i+1][j] = left;
            
            int right = dp[i][j] + triangle[i+1][j+1];
            if (dp[i+1][j+1] < right) dp[i+1][j+1] = right;
        }
    }
    
    for (int i = 0; i < triangle[triangle.size()-1].size(); i++) {
        //cout << dp[triangle.size()-1][i] << endl;
        
        if (answer < dp[triangle.size()-1][i]) {
            answer = dp[triangle.size()-1][i];
        }
    }
    return answer;
}