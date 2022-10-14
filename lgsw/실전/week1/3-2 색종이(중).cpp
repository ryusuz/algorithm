#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N;
int X[100+10];
int Y[100+10];

int miny, minx;
int maxy, maxx;

int board[110][110] = {0};
int round;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}

void setPaper(int y, int x) {
    for(int i = y; i < y + 10; i++) {
        for(int j = x; j < x + 10; j++) {
            board[i][j] = 1;
        }
    }
}

void dfs1(int y, int x) {
    if (y < miny || y > maxy || x < minx || x > maxx) return;

    if (board[y][x] == 1) {
        round++;
        return;
    }

    if (board[y][x] != 0) return;

    board[y][x] = 2;

    for(int i = 0; i < 4; i++) {
        dfs1(y + dy[i], x + dx[i]);
    }
}

void dfs2(int y, int x) {
    if (y < miny || y > maxy || x < minx || x > maxx) return;

    if (board[y][x] == 0) {
        round++;
        return;
    }

    if (board[y][x] == 3) return;

    board[y][x] = 3;


    for(int i = 0; i < 4; i++) {
        dfs2(y + dy[i], x + dx[i]);
    }
}

int solve() {
    round = 0;
    int ret;

    miny = 200; minx = 200;
    maxy = 0; maxx = 0;

    for(int i = 0; i < N; i++) {
        setPaper(Y[i], X[i]);

        miny = min(miny, Y[i] - 1);
        minx = min(minx, X[i] - 1);
        maxy = max(maxy, Y[i] + 10);
        maxx = max(maxx, X[i] + 10);
    }

    dfs1(miny, minx);
    dfs2(miny, minx);

    return round;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}