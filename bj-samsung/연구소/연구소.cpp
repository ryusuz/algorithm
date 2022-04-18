// 22.04.18. 연구소
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int N, M;
vector<vector<int>> board;
int answer = 0;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void Input() {
    board = vector<vector<int>> (8, vector<int> (8, 0));

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            cin >> board[i][j];
        }
    }
}

int bfs(vector<vector<int>> &nboard) {
    int ret = 0;

    queue<pair<int, int>> q;
    
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (nboard[i][j] == 2) q.push({i, j});
        }
    }

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

            if (nboard[ny][nx] == 0) {
                q.push({ny, nx});
                nboard[ny][nx] = 2;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (nboard[i][j] == 0) ret++;
        }
    }

    return ret;
}

void dfs(int y, int x, int cnt, vector<vector<int>> nboard) {
    if (cnt == 3) {
        answer = max(answer, bfs(nboard));
        return;
    }

    for(int i = y; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (nboard[i][j] == 0) {
                nboard[i][j] = 1;
                dfs(i, j, cnt + 1, nboard);
                nboard[i][j] = 0;
            }
        }
    }
}

int main() {
    Input();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j++) {
            if (board[i][j] == 0) {
                board[i][j] = 1;
                dfs(i, j, 1, board);
                board[i][j] = 0;
            }
        }
    } 

    printf("%d \n", answer);
}