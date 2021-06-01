// week1 - 다리를 지나는 트럭
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    int sum = 0;
    int idx = 0;
    queue<int> bridge;
    
    while(1) {
        answer++;
        if (bridge.size() == bridge_length) {
            sum -= bridge.front();
            bridge.pop();
        }
        
        if (sum + truck_weights[idx] <= weight) {
            // 마지막 원소면
            if(idx == truck_weights.size() - 1) {
                answer += bridge_length;
                break;
            }
            
            bridge.push(truck_weights[idx]);
            sum += truck_weights[idx];
            idx++;
        } else {
            bridge.push(0);
        }
    }
    
    return answer;
}
