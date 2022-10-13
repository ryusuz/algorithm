#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAXN (100)
int W, H;//지도의 가로 세로 크기
char map[MAXN+10][MAXN+10];//지도 정보('1':저글링, '0':빈곳)
int sw, sh;//시작위치 가로 세로 좌표

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int t;
int cnt;

struct pnt {
    int y, x, t;
};

void InputData(){
    cin >> W >> H;
    for (int i=1; i<=H; i++){
        cin >> &map[i][1];
    }
    cin >> sw >> sh;
}

bool check(int y, int x) {
    if (y < 1 || y > H || x < 1 || x > W) return false;
    return true;
}

int kill(int y, int x) {
    int ret;
    queue<pnt> q;
    bool visit[MAXN + 10][MAXN+10] = {false};
    
    q.push({y, x, 3});
    visit[y][x] = true;
    map[y][x] = '2';

    int ny, nx, t;

    while (!q.empty()) {
        y = q.front().y;
        x = q.front().x;
        t = q.front().t;
        q.pop();

        for(int i = 0; i < 4; i++) {
            ny = y + dy[i];
            nx = x + dx[i];

            if (!check(ny, nx) || visit[ny][nx] || map[ny][nx] == '0') continue;

            q.push({ny, nx, t + 1});
            visit[ny][nx] = true;
            map[ny][nx] = '2';
            ret = t + 1;
        }
    }

    return t;
}

int save() {
    int ret = 0;

    for(int i = 1; i <= H; i++) {
        for(int j = 1; j <= W; j++) {
            if (map[i][j] == '1') ret++;
        }
    }

    return ret;
}

int main(){
    InputData();//입력 받는 부분

    //여기서부터 작성
    cout << kill(sh, sw) << "\n" << save() << "\n";

    return 0;
}