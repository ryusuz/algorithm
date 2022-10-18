#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>
using namespace std;

#define MAX (100)
int M, N, K;//세로크기, 가로크기, 직사각형 개수
int sx[MAX+10];
int sy[MAX+10];
int ex[MAX+10];
int ey[MAX+10];

int sol[MAX * MAX];//각 영역 넓이 저장용

int map[MAX][MAX] = {0};
bool visited[MAX][MAX] = {false};

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void draw(int ly, int lx, int ry, int rx) {
    for(int i = ly; i < ry; i++) {
        for(int j = lx; j < rx; j++) {
            map[i][j] = 1;
        }
    }
}

bool check(int y, int x) {
    if (y < 0 || y >= M || x < 0 || x >= N) return false;
    return true;
}
// 1. bfs 활용
int bfs(int y, int x) {
    int cnt = 1;

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while(!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!check(ny, nx) || map[ny][nx] == 1 || visited[ny][nx]) continue;

            q.push({ny, nx});
            visited[ny][nx] = true;
            cnt++;
        }
    }

    return cnt;
}

// 2. flood fill 사용
void floodFill(int y, int x) {
    if (y < 0 || y >= MAXH || x < 0 || x >= MAXW) return;
    

}

int solve() {
    int cnt = 0;

    // 1. 직사각형 그리기
    for(int i = 0; i < K; i++) {
        draw(sy[i], sx[i], ey[i], ex[i]);
    }

    // 2. 구역 구하기 (bfs)
    for(int i = 0; i < M; i++) {
        for(int j = 0; j < N; j++) {
            if (map[i][j] == 0 && !visited[i][j]) {
                sol[cnt++] = bfs(i, j);
            }
        }
    }

    // flood fill
    /*
    
    
    */

    sort(sol, sol + cnt);

    return cnt;
}

void InputData(){
    cin >> M >> N >> K;
    for (int i=0; i<K; i++){
        cin >> sx[i] >> sy[i] >> ex[i] >> ey[i];
    }
}

void OutputData(int ans){
    cout << ans << endl;
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

int main(void){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = solve();

    OutputData(ans);//출력하는 부분
    return 0;
}