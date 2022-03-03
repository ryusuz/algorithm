// 22.03.03.
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<vector<int>> routes) {
    int answer = 1;
    sort(routes.begin(), routes.end());
    
    int tmp = routes[0][1];
    for(auto rt : routes) {
        if (tmp < rt[0]) {
            answer++;
            tmp = rt[1];
        }
        
        if (tmp >= rt[1]) tmp = rt[1];
    }
    
    return answer;
}