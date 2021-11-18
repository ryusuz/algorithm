// 네트워크 21.11.18.

#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

void bfs(int node, vector<vector<int>> &graph, vector<bool> &visit) {
    queue<int> q;
    q.push(node);
    visit[node] = true;

    while (!q.empty()) {
        node = q.front();
        q.pop();        
        
        for(int i = 0; i < graph[node].size(); i++) {
            int next = graph[node][i];

            if (!visit[next]) {
                q.push(next);
                visit[next] = true;
        
            }
         }
    }
    
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    vector<bool> visit(n, false);
    vector<vector<int>> graph(n+1);
    
    for(int i = 0; i < computers.size(); i++) {
        for (int j = 0; j < computers[0].size(); j++) {
            if (i == j) continue;
            
            if (computers[i][j] == 1) {
                graph[i+1].push_back(j+1);
            }
        }
    }
    
    for(int i = 1; i < graph.size(); i++) {
        if (!visit[i]) {
            bfs(i, graph, visit);
            answer++;
        }
    }

    return answer;
}

////////////////////////////////////////////
#include <string>
#include <vector>

using namespace std;

void DFS(int from, int n, vector<int> &visited, vector<vector<int>> &computers) {

    for (int i = 0; i < n; i++) {
        if (from != i && computers[from][i] == 1 && visited[i] == 0) {
            visited[i] = 1;
            DFS(i, n, visited, computers);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {

    int network = 0;
    vector<int> visited(n, 0);

    for (int i = 0; i <n; i++) {
        if (visited[i] == 1) {
            continue;
        }

        // visit node and start DFS
        network++;
        visited[i] = 1;

        DFS(i, n, visited, computers);
    }

    return network;
}