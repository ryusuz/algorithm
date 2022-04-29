// 22.04.29. 인구 이동
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int answer;

int N, L, R;
int board[51][51];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

void Input() {
    scanf("%d %d %d", &N, &L, &R);

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            scanf("%d", &board[i][j]);
        }
    }
}

bool check(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= N) return false;
    return true;
}

int checkDiff(int a, int b) {
    int diff = abs(a-b);

    if (diff >= L && diff <= R) return diff;
    return 0;
}

int bfs(int y, int x, vector<vector<bool>> &visited) {
    queue<pair<int, int>> q;
    vector<pair<int, int>> countrys;

    q.push({y, x});
    countrys.push_back({y, x});
    visited[y][x] = true;
    int sum = board[y][x];

    while (!q.empty()) {
        y = q.front().first;
        x = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!check(ny, nx) || checkDiff(board[y][x], board[ny][nx]) == 0) continue;

            if (!visited[ny][nx]) {
                q.push({ny, nx});
                countrys.push_back({ny, nx});
                visited[ny][nx] = true;
                sum += board[ny][nx];
            }
        }
    }
    
    if (countrys.size() == 1) return 0;

    int people = sum / countrys.size();

    for(int i = 0; i < countrys.size(); i++) {
        board[countrys[i].first][countrys[i].second] = people;
    }

    return 1;
}

int main() {
    Input();

    while (1) {
        int move = 0;

        vector<vector<bool>> visited(51, vector<bool> (51, false));

        for(int i = 0; i < N; i++) {
            for(int j = 0; j < N; j++) {
                if (!visited[i][j]) {
                    move += bfs(i, j, visited);
                }
            }
        }
        
        if (move == 0) break;
        answer++;
    }

    printf("%d \n", answer);

    return 0;
}