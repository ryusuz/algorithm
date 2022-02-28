// 22.02.28. 가장 먼 노드 (그래프)
#include <string>
#include <vector>
#include <unordered_map>
#include <queue>
#include <algorithm>
#include <iostream>

using namespace std;

int solution(int n, vector<vector<int>> edge) {
    unordered_map<int, vector<int>> graph;
    
    for(auto& v : edge) {
        graph[v[0]].push_back(v[1]);
        graph[v[1]].push_back(v[0]);
    }
    
    int gsize = graph.size();
    
    vector<int> dist(gsize + 1, 20000);    
    vector<bool> visit(gsize + 1, false);
    
    queue<int> q;
    q.push(1);
    
    dist[0] = 0;
    dist[1] = 0;
    visit[1] = true;

    while(!q.empty()) {
        int curr = q.front();
        q.pop();

        for(int i = 0; i < graph[curr].size(); i++) {
            int next = graph[curr][i];
            int d = dist[curr] + 1;
        
            if (dist[next] > d) dist[next] = d;

            if (!visit[next]) {
                q.push(next);
                visit[next] = true;
            }
        }
    }
    
    int answer = 0;
    int max = *max_element(dist.begin(), dist.end());

    for(int i = 1; i < dist.size(); i++)
        if (dist[i] == max) answer++;
    
    return answer;
}