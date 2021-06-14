// week8-1 예산
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> d, int budget) {
    int answer = 0;
    int tmp = 0;
    // 예산이 작은 애들부터 차례로 더해서 budget되면 되자나..?
    
    sort(d.begin(), d.end());
    
    for (int n : d) {
        tmp += n;
        if (tmp > budget) break;
        answer++;
    }
    
    return answer;
}