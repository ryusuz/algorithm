// 22.05.15.
#include <iostream>
#include <queue>
using namespace std;

int N, M, V;
int graph[1001][1001] = {0};
bool visited[1001] = {false};

void Input() {
    cin >> N >> M >> V;

    int a, b;
    for(int i = 0; i < M; i++) {
        cin >> a >> b;

        graph[a][b] = 1;
        graph[b][a] = 1;
    }
}

void bfs() {
    queue<int> q;
    bool visit[1001] = {false};

    q.push(V);
    visit[V] = true;

    while (!q.empty()) {
        int v = q.front();
        q.pop();

        cout << v << " ";

        for(int next = 1; next <= N; next++) {
            if (graph[v][next] == 0) continue;

            if (!visit[next]) {
                visit[next] = true;
                q.push(next);
                //cout << "   next :: " << next << endl;
            }
        }
    }
    cout << endl;
}

void dfs(int v) {
    cout << v << " ";
    visited[v] = true;

    for(int next = 1; next <= N; next++) {
        if (graph[v][next] == 0) continue;

        if (!visited[next]) dfs(next);
    }
}

int main() {
    Input();

    dfs(V);
    cout << endl;

    bfs();

    return 0;
}