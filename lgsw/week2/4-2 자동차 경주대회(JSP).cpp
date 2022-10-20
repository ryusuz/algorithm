#include <iostream>
#include <queue>
using namespace std;

#define MAXN (100)
#define INF (1<<30)

int L;//정비를 받지 않고 갈수있는 최대거리
int N;//정비소 개수
int dist[MAXN+10];//정비소사이거리
int times[MAXN+10];//정비시간

int visited[MAXN+10];   // 누적 가중치
int path[MAXN+10];

int t, cnt;
int sol[MAXN+10];

void init() {
    t = 0;
    cnt = 0;

    for(int i = 1; i <= N+1; i++) {
        visited[i] = INF;
        path[i] = 0;
    }
}

void bfs(int curr) {
    queue<int> q;
    q.push(curr);
    visited[curr] = 0;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        int d = 0;
        for(int next = curr + 1; next <= N+1; next++) {
            d += dist[next];

            if (d > L) break;

            if (visited[next] > visited[curr] + times[next]) {
                visited[next] = visited[curr] + times[next];
                q.push(next);
                path[next] = curr;
            }
        }
    }
}

void getPath(int n, int idx) {
    if (path[n] == 0) {
        return;
    }
    
    cnt++;
    getPath(path[n], idx + 1);
    sol[cnt - idx] = path[n];
}

void solve() {
    init();

    bfs(0);

    t = visited[N + 1];
    getPath(N + 1, 0);
}

void print() {
    cout << t << "\n";

    if (t == 0) return;

    cout << cnt << "\n";
    
    for(int i = 1; i <= cnt; i++) {
        cout << sol[i] << " ";
    }
    cout << "\n";
}

void InputData(){
    cin >> L;
    cin >> N;
    
    for (int i=1; i<=N+1; i++){
        cin >> dist[i];
    }

    for (int i=1; i<=N; i++){
        cin >> times[i];
    }
}

int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    solve();
    print();

    return 0;
}