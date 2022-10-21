#include <iostream>
#include <queue>
#include <utility>

using namespace std;
#define MAXN (100)

int N;

int K;
int R[MAXN+10];
int C[MAXN+10];

int L;
int X[MAXN+10];
char CMD[MAXN+10];

char map[MAXN+10][MAXN+10];

int dy[] ={-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

void InputData(){
    cin >> N;
    cin >> K;
    for (int i=0; i<K; i++){
        cin >> R[i] >> C[i];
    }
    cin >> L;
    for (int i=0; i<L; i++){
        cin >> X[i] >> CMD[i];
    }
}

void setMap() {
    for(int i = 0; i <= N+1; i++) {
        map[i][0] = '#';
        map[0][i] = '#';
        map[i][N+1] = '#';
        map[N+1][i] = '#';
    }

    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            map[i][j] = '.';
        }
    }

    for(int i = 0; i < K; i++) {
        map[R[i]][C[i]] = 'A';
    }
}

int getDist(int d, char c) {
    if (d == 0) {           // 상
        if (c == 'L') return 2;
        else return 3;
    }

    if (d == 1) {           // 하
        if (c == 'L') return 3;
        else return 2;
    }

    if (d == 2) {           // 좌
        if (c == 'L') return 1;
        else return 0;
    }

    if (d == 3) {           // 우
        if (c == 'L') return 0;
        return 1;
    }

    return -1;
}

int solve() {
    int ret = 0;

    setMap();

    pair<int, int> head = {1, 1};
    map[1][1] = 'S';

    queue<pair<int, int>> q;
    q.push(head);

    int d = 3;  // 우
    int y, x;

    int i = 0, time = 0;
    while (1) {
        time = X[i];
        ret++;

        y = q.front().first;        // 꼬리
        x = q.front().second;

        int ny = head.first + dy[d];
        int nx = head.second + dx[d];

        if (map[ny][nx] == '#' || map[ny][nx] == 'S') return ret;

        if (map[ny][nx] != 'A') {
            q.pop();                // 꼬리 자르기
            map[y][x] = '.';
        }

        map[ny][nx] = 'S';          // 머리 내밀기
        head = {ny, nx};
        q.push(head);
        

        if (ret == time) {
            d = getDist(d, CMD[i]);
            i++;
        }
    }

    return -1;
}

int main(){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}