// 22.04.19. 로봇청소기
#include <string>
#include <iostream>
#include <vector>

using namespace std;

int N, M;
int y, x, d;
int board[50][50];

int answer = 0;

int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};

void Input() {
    cin >> N >> M;
    cin >> y >> x >> d;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    answer = 0;
}

bool check(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) return false;
    return true;
}

int main() {
    Input();

    while (board[y][x] != 1 || !check(y, x)) {
        if (board[y][x] == 0) {
            answer++;
            board[y][x] = 2;
        }

        for(int i = 0; i < 4; i++) {
            int ny, nx;

            d = (d == 0) ? 3 : d - 1;

            ny = y + dy[d];
            nx = x + dx[d];

            if (!check(ny, nx)) continue;

            if (board[ny][nx] == 0 || i == 4) {
                y = ny;
                x = nx;
                break;
            }

            // 후진
            if (i == 3) {
                int back = (d == 0 || d == 1) ? d + 2 : d - 2;
                y += dy[back];
                x += dx[back];
            }
        }
    }

    printf("%d \n", answer);

    return 0;
}