#include <iostream>
#include <utility>
#include <vector>
using namespace std;

#define MAXN (9)

int sudoku[MAXN][MAXN];

int N;
bool flag;
vector<pair<int, int>> blank;

void init() {
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            if (sudoku[i][j] == 0) blank.push_back({i, j});
        }
    }

    N = blank.size();
    flag = false;
}

bool check(int n, int y, int x) {
    for(int i = 0; i < 9; i++) {
        if (i != x && sudoku[y][i] == n) return false;
    
        if (i != y && sudoku[i][x] == n) return false;
    }

    int ny = (y / 3) * 3;
    int nx = (x / 3) * 3;

    for(int i = ny; i < ny + 3; i++) {
        for(int j = nx; j < nx + 3; j++) {
            if (y == i && x == j) continue;

            if (sudoku[i][j] == n) return false;
        }
    }

    return true;
}

void dfs(int cnt) {
    if (cnt == N) {
        flag = true;
        return;
    }

    int y = blank[cnt].first;
    int x = blank[cnt].second;

    for(int i = 1; i <= 9; i++) {
        sudoku[y][x] = i;

        if (check(i, y, x)) {
            dfs(cnt + 1);
        }

        if (flag) return;
        sudoku[y][x] = 0;
    }
}

void solve() {
    init();
    dfs(0);
}

void InputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cin >> sudoku[r][c];
        }
    }
}

void OutputData(){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            cout << sudoku[r][c] << " ";
        }
        cout << endl;
    }
}

int main(){
    InputData();//입력받는 부분

    //여기서부터 작성
    solve();

    OutputData();//출력하는 부분
    return 0;
}