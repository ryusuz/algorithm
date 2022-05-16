// 22.05.16. 종이의 개수
#include <iostream>
#include <queue>
using namespace std;

int N;
int board[2200][2200];

int answer[3] = {0};

void Input() {
    ios_base::sync_with_stdio(0);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

void dfs(int n, int y, int x) {
    int var = board[y][x];
    bool check = true;

    for(int i = y; i < y + n; i++) {
        for(int j = x; j < x + n; j++) {
            if (var != board[i][j]) {
                check = false;
                break;
            }
        }
    }

    if (check)  answer[var + 1]++;
    else {
        for(int i = y; i < y + n; i += n/3) {
            for(int j = x; j < x + n; j += n/3) {
                dfs(n/3, i, j);
            }
        }
    }
}

int main() {
    Input();

    int cnt = 1;

    dfs(N, 0, 0);

    for(int i = 0; i < 3; i++) {
        cout << answer[i] << endl;
    }

    return 0;
}