#include <iostream>
using namespace std;

int N;
int grids[500+10][500+10];

int goal;
int cnt;

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int tmp[500+10][500+10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> grids[i][j];
        }
    }
}

void copyMap() {
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            tmp[i][j] = grids[i][j];
        }
    }
}

void floodfill(int y, int x, int m, int prev) {
    if (y < 0 || y >= N || x < 0 || x >= N) return;

    if (tmp[y][x] == -1) return;

    if (abs(tmp[y][x] - prev) > m) return;

    int curr = tmp[y][x];
    tmp[y][x] = -1;
    cnt++;

    if (cnt >= goal) return;

    for(int i = 0; i < 4; i++) {
        floodfill(y + dy[i], x + dx[i], m, curr);
    }
}

bool check(int m) {
    copyMap();

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            if (tmp[i][j] == -1) continue;

            cnt = 0;
            floodfill(i, j, m, tmp[i][j]);

            if (cnt >= goal) return true;
        }
    }

    return false;
}

int solve() {
    goal = (N * N / 2 ) + (N * N % 2);

    int ret;
    int s = 0;
    int e = (int)1e6;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (check(mid)) {
            ret = mid;
            e = mid - 1;
        } else {
            s = mid + 1;
        }
    }

    return ret;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout <<  ans << endl;// 출력하는 부분
    return 0;
}