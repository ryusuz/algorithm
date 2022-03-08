// 22.03.08. 야근지수
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

long long solution(int n, vector<int> works) {
    long long answer = 0;
    long long sum = 0;
    priority_queue<int> pq;
    
    for(auto w : works) {
        pq.push(w);
        sum += w;
    }
    
    if (sum <= n) return 0;
    
    while (n > 0) {
        int tmp = pq.top();
        pq.pop();
        
        pq.push(tmp-1);
        n--;
    }
    
    while(!pq.empty()) {
        int tmp = pq.top();
        pq.pop();
        answer += tmp * tmp;
    }
     
    return answer;
}

/*
최대한 숫자들을 비슷하게? 만드는게 작은가?
큰 수를 빼주기?

*/