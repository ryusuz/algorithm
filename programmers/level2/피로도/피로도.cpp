// 22.02.19. 피로도
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int solution(int k, vector<vector<int>> dungeons) {
    int answer = -1;
    vector<int> idx(dungeons.size(), 0);
    
    for(int i = 0; i < idx.size(); i++) {
        idx[i] = i;
    }
    
    do {
        int hp = k;
        int cnt = 0;
        for(int i = 0; i < dungeons.size(); i++) {
            //cout << dungeons[idx[i]][0] << " " << dungeons[idx[i]][1] << endl;
            
            if (hp < dungeons[idx[i]][0]) break;
            
            hp -= dungeons[idx[i]][1];
            cnt++;
        }
        //cout << endl;
        
        answer = max(answer, cnt);
            
    } while (next_permutation(idx.begin(), idx.end()));
    
    return answer;
}