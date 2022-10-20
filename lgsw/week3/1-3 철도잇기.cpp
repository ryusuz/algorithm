#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (50)
int N, M, K;            //철도역수, 철도수, 추가로 연결시킬수있는 철도수
int S[MAXN + 10];
int E[MAXN + 10];

int map[MAXN + 10][MAXN + 10];    // 0: 연결 안됨, 1: 연결 됨
int group[MAXN + 10];
bool visited[MAXN + 10];

int city;

void init() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            map[i][j] = 0;
        }
    }

    for(int i = 0; i < M; i++) {
        map[S[i]][E[i]] = map[E[i]][S[i]] = 1;
    }
}

void floodFill(int s, int e) {
    if (map[s][e] == 0 || map[s][e] == 2) return;   // 연결 안 되어있거나 이미 방문했다면 리턴

    map[s][e] = 2;
    if (!visited[e]) {                              // 방문한 도시 카운트
        city++;
        visited[e] = true;
    }

    for(int i = 1; i <= N; i++) {
        floodFill(e, i);
    }
}

int solve() {
    /*
    1. 연결된 도시 그룹 형성 및 도시 개수 체크
    2. 도시가 많은 순으로 그룹 정렬
    3. 연결 가능한 철도 수만큼 돌면서 연결, 그룹 도시 개수 더하기
    */

    int ret = 0;

    init();

    int cnt = 0;

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if (i == j) continue;

            if (map[i][j] == 1) {
                city = 1;
                visited[i] = true;

                floodFill(i, j);
                group[cnt++] = city;
            }
        }
    }

    for(int i = 1; i <= N; i++) {
        if (!visited[i]) group[cnt++] = 1;      // 연결 없이 혼자인 도시들 체크
    }

    sort(group, group + cnt, greater<int>());

    for(int i = 0; i <= K; i++) {
        ret += group[i];
    }

    return ret;
}

void InputData() {
    cin >> N >> M >> K;
    for (int i = 0; i < M; i++) {
        cin >> S[i] >> E[i];
    }
}

int main() {
	int ans = -1;
    InputData();//입력받는 부분

	// 여기서부터 작성
	ans = solve();

    cout << ans << "\n";// 출력하는 부분
    return 0;
}