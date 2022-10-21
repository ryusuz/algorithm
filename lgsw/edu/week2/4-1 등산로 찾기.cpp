#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define INF (1<<30)
#define MAXN (102)

int N;                              //산 크기
int eh, ew;                         //목적지 위치 세로, 가로
int map[MAXN][MAXN];

int visited[MAXN][MAXN];            // 누적 가중치
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void init() {
    // 누적 가중치 초기화
    for(int i = 0; i <= N+1; i++) {
        for(int j = 0; j <= N+1; j++) {
            visited[i][j] = INF;
        }
    }
}

bool check(int y, int x) {
    if (y < 0 || y > N+1 || x < 0 || x > N+1) return false;
    return true;
}

int getCost(int curr, int next) {
    if (curr > next) return (curr - next) * (curr - next);  // 오르막
    if (curr < next) return next - curr;                    // 내리막
    return 0;
}

void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = 0;

    int ny, nx;

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if (!check(ny, nx)) continue;

            int cost = getCost(map[y][x], map[ny][nx]);

            if (visited[ny][nx] > visited[y][x] + cost) {
                visited[ny][nx] = visited[y][x] + cost;
                q.push({ny, nx});
            }
        }
    }
}   

int solve() {
    init();

    // 1. 목적지에서 출발
    bfs(eh, ew);

    // 2. 목적지에서 최단 경로로 가기 때문에 산의 바깥지역은 모두 같은 값이 됨.
    return visited[0][0];
}

void InputData(){
    cin >> N;
    cin >> eh >> ew;
    for (int h=1; h<=N; h++){
        for (int w=1; w<=N; w++){
            cin >> map[h][w];
        }
    }
}

int main(){
    int ans = -1;
    InputData();//입력 받는 부분

    //여기서부터 작성
    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}