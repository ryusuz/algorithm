// 22.03.20. 외벽 점검
#include <string>
#include <vector>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = 0;
    int dp[200][200] = {0};
    
    int N = weak.size();
    int M = dist.size();
    
    int max_dist = dist[M-1];
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (weak[i] <= weak[j]) {
                if (weak[j] - weak[i] <= max_dist)
                    dp[i][j] = weak[j] - weak[i];
            } else {
                if (n - weak[i] + weak[j] <= max_dist)
                    dp[i][j] = n - weak[i] + weak[j];
            }
        }
    }
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (dp[i][j] != 0) cout << weak[i] << "~" << weak[j] << " :: " << dp[i][j] << endl;
        }
    }
    
    return answer;
}

/*
디피?

1~1 1~5 1~6 1~10
5~1 5~5 5~6 5~10
6~1 6~5 6~6 6~10
10~1 10~5 10~6 10~10


*/
