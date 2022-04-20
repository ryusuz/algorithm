// 22.04.20. 주사위 굴리기
#include <iostream>
#include <vector>
using namespace std;

vector<int> answer;
int N, M, K;
int y, x;
vector<vector<int>> board;
vector<int> orders;

int dice[6] = {0};

int dy[4] = {0, 0, -1, 1};
int dx[4] = {1, -1, 0, 0};

void Input() {
    cin >> N >> M >> y >> x >> K;

    board = vector<vector<int>> (N, vector<int> (M, 0));
    orders = vector<int> (K, 0);
    answer = vector<int> (K, 0);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }

    for(int i = 0; i < K; i++) {
        cin >> orders[i];
    }    
}

bool check(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) return false;
    return true;
}

void copyDice(int y, int x) {
    if (board[y][x] == 0) {
        board[y][x] = dice[5];
        return;
    }

    dice[5] = board[y][x];
    board[y][x] = 0;
}

void rollDice(int d) {
    int d0, d1, d2, d3, d4, d5;
    d0 = dice[0], d1 = dice[1], d2 = dice[2];
    d3 = dice[3], d4 = dice[4], d5 = dice[5];
    
    if (d == 0) {           // 오른
        dice[0] = d3;
        dice[2] = d0;
        dice[5] = d2;
        dice[3] = d5;
    } else if (d == 1) {    // 왼
        dice[0] = d2;
        dice[2] = d5;
        dice[5] = d3;
        dice[3] = d0;
    } else if (d == 2) {    // 위
        dice[0] = d4;
        dice[4] = d5;
        dice[5] = d1;
        dice[1] = d0;
    } else {                // 아래
        dice[0] = d1;
        dice[1] = d5;
        dice[5] = d4;
        dice[4] = d0;
    }

    printf("%d \n", dice[0]);
}

int main() {
    Input();

    for(int i = 0; i < K; i++) {
        int d = orders[i] - 1;
        int ny = y + dy[d];
        int nx = x + dx[d];

        if (!check(ny, nx)) continue;

        rollDice(d);
        copyDice(ny, nx);
        y = ny, x = nx;
    }

    return 0;
}
