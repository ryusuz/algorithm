#include <iostream>
#include <queue>
using namespace std;

#define MAXN (int)1e2
#define MAXM (int)1e4
#define INF (1<<30)

int N, M;              // 필드(노드) 개수, 경로(가중치) 개수
int A[MAXM + 10];      // 시작 노드
int B[MAXM + 10];      // 도착 노드
int L[MAXM + 10];      // 가중치

int map[MAXN + 10][MAXN + 10];      // 각 경로 가중치 배열
int path[MAXN + 10];                // 경로
int visited[MAXN + 10];              // 누적 가중치

void init() {
    // 가중치 배열 무한값으로 초기화
    for(int i = 0; i < N + 10; i++) {
        for(int j = 0; j < N + 10; j++) {
            map[i][j] = INF;
        }
    }

     // 가중치 최초값 저장
    for(int i = 0; i < M; i++) {
        int s = A[i];
        int e = B[i];
        int d = L[i];

        map[s][e] = (map[s][e] > d) ? d : map[s][e];
        map[e][s] = (map[e][s] > d) ? d : map[e][s];
    }
}

void getPath(int curr) {
    // 누적가중치 배열 초기화
    for(int i = 1; i <= N; i++) {
        visited[i] = INF;
    }

    queue<int> q;

    q.push(curr);          // 출발지 == 1
    visited[curr] = 0;
    path[curr] = 0;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        for(int next = 1; next <= N; next++) {
            if (next == curr || map[curr][next] == INF) continue;

            if (visited[next] > visited[curr] + map[curr][next]) {
                visited[next] = visited[curr] + map[curr][next];
                q.push(next);
                path[next] = curr;
            } 
        }
    }
}

int solve() {
    int ret = 0;
    int org;
    
    // 0. 초기화
    init();
    
    // 1. 농부의 최초 최단 경로 찾기
    getPath(1);
    org = visited[N];
    
    cout << visited[N] << endl;
    
    // 2. 최단 경로를 따라 경로를 2배씩 바꾸고 그때마다 최단 경로 찾기
    int prev, curr = N;
    while (path[curr]) {
        prev = path[curr];

        map[prev][curr] *= 2;
        map[curr][prev] *= 2;

        getPath(1);
        cout << visited[N] << endl;
        ret = max(ret, visited[N]);

        map[prev][curr] /= 2;
        map[curr][prev] /= 2;

        curr = prev;
    }

    return ret - org;
}

void InputData(){
    cin >> N >> M;
    for (int i = 0; i<M; i++){
        cin >> A[i] >> B[i] >> L[i];
    }
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}