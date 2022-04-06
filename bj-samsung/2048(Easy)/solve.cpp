// 22.04.04. 2048
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int answer;
int N;
vector<vector<int>> b;

void Input() {
    answer = 0;

    scanf("%d", &N);

    for(int i = 0; i < N; i++) {
        vector<int> tmp;

        for(int j = 0; j < N; j++) {
            int n;
            scanf("%d", &n);
            tmp.push_back(n);
        }

        b.push_back(tmp);
    }
}

int findMax(vector<vector<int>> &board) {
    int max = 0;

    for(auto &v : board) {
        for(auto &n : v) {
            if (max < n) max = n;
        }
    }

    return max;
}

vector<vector<int>> moveU(vector<vector<int>> board) {
    for(int j = 0; j < N; j++) {
        int idx = 0;
        vector<bool> check(N, false);

        for(int i = 0; i < N; i++) {
            if (board[i][j] == 0) continue;

            int block = board[i][j];
            board[i][j] = 0;

            if (idx == 0) {
                board[idx++][j] = block;
                continue;
            }

            if (check[idx-1]) {
                board[idx++][j] = block;
                continue;
            }

            if (check[idx]) {
                board[idx++][j] = block;
                continue;
            }

            if (board[idx-1][j] != block) {
                board[idx++][j] = block;
                continue;
            }

            board[idx-1][j] = block * 2;
            check[idx-1] = true;
        }
    }

    return board;
}

vector<vector<int>> moveD(vector<vector<int>> board) {
    for(int j = 0; j < N; j++) {
        int idx = N-1;
        vector<bool> check(N, false);

        for(int i = N-1; i >= 0; i--) {
            if (board[i][j] == 0) continue;

            int block = board[i][j];
            board[i][j] = 0;

            if (idx == N-1) {
                board[idx--][j] = block;
                continue;
            }

            if (check[idx+1]) {
                board[idx--][j] = block;
                continue;
            }

            if (check[idx]) {
                board[idx--][j] = block;
                continue;
            }

            if (board[idx+1][j] != block) {
                board[idx--][j] = block;
                continue;
            }

            board[idx+1][j] = block * 2;
            check[idx+1] = true;
        }
    }

    return board;
}

vector<vector<int>> moveL(vector<vector<int>> board) {
    for(int i = 0; i < N; i++) {
        int idx = 0;
        vector<bool> check(N, false);

        for(int j = 0; j < N; j++) {
            if (board[i][j] == 0) continue;

            int block = board[i][j];
            board[i][j] = 0;

            if (idx == 0) {
                board[i][idx++] = block;
                continue;
            }

            if (check[idx-1]) {
                board[i][idx++] = block;
                continue;
            }

            if (check[idx]) {
                board[i][idx++] = block;
                continue;
            }

            if (board[i][idx-1] != block) {
                board[i][idx++] = block;
                continue;
            }

            board[i][idx-1] = block * 2;
            check[idx-1] = true;
        }
    }

    return board;
}

vector<vector<int>> moveR(vector<vector<int>> board) {
    for(int i = 0; i < N; i++) {
        int idx = N-1;
        vector<bool> check(N, false);

        for(int j = N-1; j >= 0 ; j--) {
            if (board[i][j] == 0) continue;

            int block = board[i][j];
            board[i][j] = 0;

            if (idx == N-1) {
                board[i][idx--] = block;
                continue;
            }

            if (check[idx+1]) {
                board[i][idx--] = block;
                continue;
            }

            if (check[idx]) {
                board[i][idx--] = block;
                continue;
            }

            if (board[i][idx+1] != block) {
                board[i][idx--] = block;
                continue;
            }

            board[i][idx+1] = block * 2;
            check[idx+1] = true;
        }
    }

    return board;
}

void dfs(int depth, vector<vector<int>> board) {
    answer = max(findMax(board), answer);

    if (depth == 5) {
        
        return;
    }

    dfs(depth + 1, moveU(board));
    dfs(depth + 1, moveD(board));
    dfs(depth + 1, moveL(board));
    dfs(depth + 1, moveR(board));
}

int main() {
    Input();

    dfs(0, b);

    printf("%d \n", answer);

    return 0;
}