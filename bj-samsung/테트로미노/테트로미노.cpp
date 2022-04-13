// 22.04.13. 테트로미노
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

struct Point {
    int y, x;
};

int N, M;
int answer = 0;
vector<vector<int>> board;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};
bool visit[501][501] = {false};

void Input() {
    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        vector<int> tmp;
        for(int j = 0; j < M; j++) {
            int num;
            cin >> num;
            tmp.push_back(num);
        }
        board.push_back(tmp);
    }
}

bool check(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= M) return false;
    return true;
}

void dfs(int depth, int cost, int y, int x) {
    if (depth == 4) {
        answer = max(answer, cost);
        return;
    }

    for(int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (!check(ny, nx) || visit[ny][nx]) continue;

        visit[ny][nx] = true;
        dfs(depth + 1, cost + board[ny][nx], ny, nx);
        visit[ny][nx] = false;
    }

    if (x-1 >= 0 && x+1 < M && y-1 >= 0 && y < N) {  // ㅗ
        answer = max(answer, board[y][x-1] + board[y][x] + board[y][x+1] + board[y-1][x]);
    }

    if (x-1 >= 0 && x+1 < M && y >= 0 && y + 1 < N) {  // ㅜ
        answer = max(answer, board[y][x-1] + board[y][x] + board[y][x+1] + board[y+1][x]);
    }

    if (x >= 0 && x+1 < M && y-1 >= 0 && y+1 < N) {   // ㅏ
        answer = max(answer, board[y-1][x] + board[y][x] +  board[y+1][x] + board[y][x+1]);
    }

    if (x-1 >= 0 && x < M && y-1 >= 0 && y+1 < N) {
        answer = max(answer, board[y][x-1] + board[y][x] + board[y+1][x] + board[y-1][x]);
    }

}

int main() {
    Input();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            visit[i][j] = true;
            dfs(1, board[i][j], i, j);
            visit[i][j] = false;
        }
    }

    cout << answer << endl;
}