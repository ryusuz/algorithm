// 22.03.07. 디스크 컨트롤러 (힙)

#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct cmp {
    bool operator()(vector<int> a, vector<int> b) {
        return a[1] > b[1];
    }
};

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    int idx = 0;
    int end = 0;
    
    priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
    sort(jobs.begin(), jobs.end());
    
    while (idx < jobs.size() || !pq.empty()) {
        if (idx < jobs.size() && jobs[idx][0] <= end) {
            pq.push(jobs[idx++]);
            continue;
        }
        
        if (!pq.empty()) {
            end += pq.top()[1];
            answer += end - pq.top()[0];
            pq.pop();
        } else {
            end = jobs[idx][0];
        }
    }
    return answer / jobs.size();
}