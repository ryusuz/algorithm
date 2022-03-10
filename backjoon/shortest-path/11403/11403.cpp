// 22.03.10. 11403 경로 찾기 (플로이드 와샬)
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int N;
vector<vector<int>> graph;

void solution() {
    int answer = 0;

    for(int i = 0; i < N; i++) {            // 거쳐가는 노드
        for(int j = 0; j < N; j++) {        // 출발 노드
            for(int k = 0; k < N; k++) {    // 도착 노드
                if(graph[j][i]&&graph[i][k]) graph[j][k] = 1;
            }
        }
    }

    
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        vector<int> v;

        for(int j = 0; j < N; j++) {
            int tmp;
            cin >> tmp;
            v.push_back(tmp);
        }
        graph.push_back(v);
    }

    solution();

    for(auto& v : graph) {
        for(auto n : v) {
            cout << n << " ";
        }
        cout << endl;
    }

    return 0;
}