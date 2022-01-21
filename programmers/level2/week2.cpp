// week2 - 더 맵게
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int> scv;
    
    // 최소힙 세팅
    for (int s : scoville) {
        scv.push(-s);
    }

    //최소힙 세팅 한줄로 => priority_queue<int, vector<int>, greater<int>> pq(scoville.begin(), scoville.end());
    
    //cout << -scv.top() << endl;

    while (-scv.top() < K) {
        if (scv.size() == 1) return -1;
        int min1 = -scv.top();
        scv.pop();
        int min2 = -scv.top();
        scv.pop();
        int newS = min1 + min2 * 2;
        //cout << min1 << ", " << min2 << ", " << newS << endl;
        scv.push(-newS);
        answer++;
    }
    
    return answer;
}