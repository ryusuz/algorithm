#include <iostream>
using namespace std;

#define MAXH (5)
#define MAXW (9)
#define INF (1<<30)

char map[MAXH+2][MAXW+2];
int solremain, solmove;

int pin;
int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void InputData(){
    for (int h=1; h<=MAXH; h++){
        cin >> &map[h][1];
    }
}

bool check(int y, int x) {
    if (y < 1 || y > MAXH || x < 1 || x > MAXW) return false;
    return true;
}

void dfs(int cnt) {
    if (cnt < solremain) solremain = cnt;

    for(int y = 1; y <= MAXH; y++) {
        for(int x = 1; x <= MAXW; x++) {
            if (map[y][x] != 'o') continue;

            // 이동할 경우
            for(int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (!check(ny, nx) || map[ny][nx] != 'o') continue;         // 옆칸에 핀이 없으면 넘김

                int nny = ny + dy[i];
                int nnx = nx + dx[i];

                if (!check(nny, nnx) || map[nny][nnx] != '.') continue;     // 옆옆칸이 빈공간이 아니면 넘김

                map[y][x] = '.';
                map[ny][nx] = '.';
                map[nny][nnx] = 'o';

                dfs(cnt - 1);

                map[nny][nnx] = '.';
                map[ny][nx] = 'o';
                map[y][x] = 'o';
            }
        }
    }
}

void solve() {
    pin = 0;

    for(int i = 1; i <= MAXH; i++) {
        for(int j = 1; j <= MAXW; j++) {
            if (map[i][j] == 'o') pin++;
        }
    }

    solremain = pin;

    dfs(pin);

    solmove = pin - solremain;
}

int main(){
    int T;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        solve();

        cout << solremain << " " << solmove << endl;//출력하는 부분
    }
    return 0;
}