// 프린터 21.10.12.
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<int> priorities, int location) {
    int answer = 0;
    queue<pair<int, int>> q;
    
    int i = 0;
    for (auto& prio : priorities) {
        q.push(make_pair(prio, i++));
    }
    
    sort(priorities.begin(), priorities.end(), greater<>());
    
    while (!q.empty()) {
        if (q.front().first == priorities[0]) {
            priorities.erase(priorities.begin());
            answer++;
            
            if (location == q.front().second) break;
            q.pop();
        } else {
            q.push(q.front());
            q.pop();
        }
    }

    return answer;
}