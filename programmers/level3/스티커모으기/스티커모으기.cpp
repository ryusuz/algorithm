#include <iostream>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> sticker)
{
    int answer = 0;
    
    int N = sticker.size();
    vector<int> sums(3, 0);
    
    if (N & 1) {
        for(int i = 0; i < N - 2; i += 2) sums[0] += sticker[i];
        
        for(int i = 1; i < N - 1; i += 2) sums[1] += sticker[i];
           
        for(int i = 2; i < N; i += 2) sums[2] += sticker[i];
        
    } else {        
        for(int i = 0; i < N; i++) {
            if (i & 1) sums[0] += sticker[i];
            else sums[1] += sticker[i];
        }
    }
    
    answer = *max_element(sums.begin(), sums.end());
    
    return answer;
}

/*
완탐 불가능.
최대한 많이 떼어내는게 좋을까? ==> 아닌 듯


*/