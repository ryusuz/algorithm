// 22.03.10. 11404 플로이드 
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int N, M;
vector<vector<int>> info;
int graph[101][101];

void input() {
    cin >> N >> M;  // 도시 개수, 버스 개수

    for(int i = 0; i < M; i++) {
        vector<int> tmp(3, 0);
        cin >> tmp[0] >> tmp[1] >> tmp[2];  // 시작도시, 도착도시, 가중치
        info.push_back(tmp);
    }
}

void solution() {
    // 그래프 생성
    for(int i = 0; i < M; i++) {
        int c1 = info[i][0];
        int c2 = info[i][1];
        int w = info[i][2];

        int tmp = graph[c1][c2];

        if (tmp == 0 || tmp > w) graph[c1][c2] = w;
    }

    // 플로이드 와샬
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            for(int k = 1; k <= N; k++) {
                if (j == k) continue;

                if (graph[j][i] && graph[i][k]) {
                    int tmp = graph[j][i] + graph[i][k];

                    if (graph[j][k] == 0 || graph[j][k] > tmp) graph[j][k] = tmp;
                }
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            cout << graph[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    input();
    solution();
    
    return 0;
}