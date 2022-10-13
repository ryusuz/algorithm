#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
#define MAXN (50)
int R, C;//지도 세로, 가로 크기
char map[MAXN+10][MAXN+10];

struct pnt {
    int y, x;
    char c;
};

pnt S, D;               // s: 화가 d: 굴
queue<pair<pnt, int>> q;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void InputData(){
    cin >> R >> C;
    q = {};

    for (int i = 0; i < R; i++){
        for(int j = 0; j < C; j++) {
            cin >> map[i][j];

            if (map[i][j] == 'S') S = {i, j, 'S'};
            if (map[i][j] == 'D') D = {i, j, 'D'}; 
            if (map[i][j] == '*') {
                pnt p = {i, j, '*'};
                q.push({p, 0});
            }
        }
    }
}

bool check(int y, int x) {
    if (y < 0 || y >= R || x < 0 || x >= C) return false;
    return true;
}

int solve() {
    q.push({S, 0});

    pnt curr, next;
    int cnt;

    while (!q.empty()) {
        curr = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (curr.y == D.y && curr.x == D.x) return cnt;

        for(int i = 0; i < 4; i++) {
            next = {curr.y + dy[i], curr.x + dx[i]};

            if (!check(next.y, next.x) || map[next.y][next.x] == 'X') continue;

            if (curr.c == '*') {         // 홍수
                 if (map[next.y][next.x] == 'D' || map[next.y][next.x] == '*') continue;
                 
                 next.c = '*';
                 map[next.y][next.x] = '*';
                 q.push({next, 0});
            }
            else if (curr.c == 'S') {   // 
                if (map[next.y][next.x] == '*' || map[next.y][next.x] == 'S') continue;

                next.c = 'S';
                map[next.y][next.x] = 'S';
                q.push({next, cnt + 1});

            }
        }
    }

    return -1;
}

int main(){
    int T, ans = -1;
    scanf("%d", &T);
    for (int t=1; t<=T; t++){
        InputData();//입력 받는 부분

        // 여기서부터 작성 
        ans = solve();

        if (ans == -1) cout << "KAKTUS" << endl;//출력 하는 부분
        else cout << ans << endl;
    }
    return 0;
}