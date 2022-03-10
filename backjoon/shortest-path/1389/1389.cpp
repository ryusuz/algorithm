// 22.03.10. 1389 케빈 베이컨의 6단계 법칙 (플로이드-와샬)
#include <vector>
#include <string>
#include <climits>
#include <iostream>
using namespace std;

int N, M;
int relationship[5001][2];
int graph[5001][5001];
int answer;

void solution() {
    vector<int> kevin(N+1, 0);

    // 그래프 생성
    for(int i = 0; i < M; i++) {
        int p1 = relationship[i][0];
        int p2 = relationship[i][1];

        graph[i][i] = 0;
        graph[p1][p2] = 1;
        graph[p2][p1] = 1;
    }

    // 플로이드-와샬
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

    int min = INT_MAX;
    for(int i = 1; i <= N; i++) {
        int sum = 0;
        for(int j = 1; j <= N; j++) {
            sum += graph[i][j];
        }

        kevin[i] = sum;

        if (sum < min) min = sum;
    }

    for(int i = 1; i <= N; i++) {
        if (kevin[i] == min) {
            answer = i;
            break;
        }
    }
}

int main() {
    cin >> N >> M;

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < 2; j++)
            cin >> relationship[i][j];
    }

    solution();

    cout << answer << endl;

    return 0;
}