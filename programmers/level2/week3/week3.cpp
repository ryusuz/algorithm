// week3 - 배달
#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <climits>

using namespace std;
int INF = INT_MAX;

// N = 마을 개수, K = 최대 배달 시간, road = 두 마을 간 거리가 담긴 2차원 배열
// 최단 경로가 K 이하인 애들만 리턴 => 다익스트라 알고리즘

int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    
    vector<pair<int, int>> graph[N + 1];         // 그래프, pair 클래스 사용, 정점(마을) 크기 + 1만큼 선언
    int short_dist[N+1];                         // 최단경로비용 배열
    
    for (int i = 0; i < N+1; i++) {
        short_dist[i] = INF;
    }
    
    priority_queue<pair<int, int>> pq;           // 우선수위 큐를 이용해서 다익스트라 알고리즘 구현
    
    // 그래프에 데이터들 삽입
    for (int row = 0; row < road.size(); row++) {
        int vilage1 = road[row][0];
        int vilage2 = road[row][1];
        int distance = road[row][2];
                
        graph[vilage1].push_back(make_pair(vilage2, distance));
        graph[vilage2].push_back(make_pair(vilage1, distance));
        
    }
    
    pq.push(make_pair(0, 1));         // 시작노드(1)의 거리는 0, 큐에 삽입
    short_dist[1] = 0;                // 노드1까지의 최단경로비용은 0
    
    while(!pq.empty()) {
        int here = pq.top().second;     // 현재 노드(마을)위치
        int dist = -pq.top().first;   // 현재 노드까지의 거리비용 <<우선순위 큐에 음수로 들어가있어서(내림차순이라) - 붙여줌
        pq.pop();
        //cout << "[ here = " << here << " ::: dist = " << dist << " ]"<< endl;
        
        if (short_dist[here] < dist) continue; // 지금까지의 경로보다 최단경로배열의 값이 더 작으면 아래 과정 패스
        
        for (int i = 0; i < graph[here].size(); i++) {
            int next = graph[here][i].first;                // 다음 방문할 마을(노드)
            int next_dist = graph[here][i].second + dist;   // 다음 마을까지의 거리
            //cout << endl << "next = " << next << " ::: dist = " << next_dist << endl;
            
            if (short_dist[next] > next_dist) {
                //cout << "before :: short dist = " << short_dist[next] << endl;
                short_dist[next] = next_dist;                // 짧은 경로로 갱신
                //cout << "after :: short dist = " << short_dist[next] << endl;
                pq.push(make_pair(-next_dist, next));        // 우선순위 큐에 최단 경로 삽입, 기본이 내림차순이라 - 붙여줌
                //cout << "pq top node = " << pq.top().second << "::: dist = " << -pq.top().first << endl;
            }
            
        }
        cout << endl;
    }
    
    // 최단경로비용이 K 이하인 애들만 pick
    for (int d : short_dist) {
        
        if (d <= K) {
            //cout << "i = " << i << " :::: d = " << short_dist[i] << endl;
            answer++;
        }
    }
    
    return answer;
}