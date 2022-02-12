// 22.02.12 카펫
#include <string>
#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    int size = brown + yellow;
    
    for(int i = yellow; i > 0; i--) {
        int yw = i;
        int yh = yellow / i;
        
        int bw = yw+2;
        int bh = yh+2;
            
        int bnum = (yw+2)*2 + yh*2;
        
        if (bnum == brown && size == bw * bh) {
            answer.push_back(bw);
            answer.push_back(bh);
            break;
        }
    }
    
    return answer;
}