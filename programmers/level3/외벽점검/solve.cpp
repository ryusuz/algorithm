// 22.03.20. 외벽 점검 (순열 + 원형탐색 배열 확장)
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(int n, vector<int> weak, vector<int> dist) {
    int answer = -1;
    int W = weak.size();
    int D = dist.size();
    
    sort(dist.begin(), dist.end());
    
    for(int i = 0; i < W; i++)
        weak.push_back(weak[i] + n);
    
    for(int i = 0; i < D; i++) { // 투입한 친구
        for(int j = 0; j < W; j++) { // 시작 지점 선택
            vector<int> temp;
        
            for(int k = D - 1 - i; k < D; k++)
                temp.push_back(dist[k]);
            
            do {
                int idx = 0;
                
                for(int k = 0; k <= i; k++) { // 친구 투입
                    int start = weak[j + idx] + temp[k];                   
                    
                    while(weak[j + idx + 1] <= start) idx++;
            
                    idx++;
                }


                if(idx >= W) return i + 1;
                
            }while(next_permutation(temp.begin(), temp.end()));
        }
    }
    
    return answer;
}



// 내 풀이 틀림
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
