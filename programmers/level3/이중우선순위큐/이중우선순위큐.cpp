// 22.03.14. 이중우 우선순위 큐 (우선순위 큐)
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    
    priority_queue<int> max_pq;
    priority_queue<int> min_pq;
    vector<int> v;
    
    int put = 0, del = 0;
    
    for(auto n : operations) {
        if (put - del == 0) {
            while (!max_pq.empty()) max_pq.pop();
            while (!min_pq.empty()) min_pq.pop();
        }
        
        if (n[0] == 'I') {
            int num = stoi(n.substr(2));
            
            max_pq.push(num);
            min_pq.push(-num);
            
            put++;
                        
        } else {
            if (put - del == 0) continue;
            
            if (n[2] == '1') max_pq.pop();
            else min_pq.pop();
            
            del++;
        }
    }
    
    if (put - del == 0) return {0, 0};
    
    answer.push_back(max_pq.top());
    answer.push_back(-min_pq.top());
    
    return answer;
}