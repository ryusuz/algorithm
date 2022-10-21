#include <iostream>
#include <queue>
using namespace std;

#define MAXH (12)
#define MAXW (6)

char map[MAXH+2][MAXW+2];

int dy[4] = {1, -1, 0, 0};
int dx[4] = {0, 0, 1, -1};

int cnt;
char curr;

void InputData(){
    for (int i=1; i<=MAXH; i++){
        cin >> &map[i][1];
    }
}

void checkColor(int y, int x) {
    if (y < 1 || y > MAXH || x < 1 || x > MAXW) return;

    if (map[y][x] == '.' || curr != map[y][x]) return;
    
    cnt++;

    map[y][x] = '*';

    for(int i = 0; i < 4; i++) {
        checkColor(y + dy[i], x + dx[i]);
    }
}

void setColor(int y, int x) {
    if (y < 1 || y > MAXH || x < 1 || x > MAXW) return;

    if (map[y][x] != '*') return;

    map[y][x] = curr;

    for(int i = 0; i < 4; i++) {
        setColor(y + dy[i], x + dx[i]);
    }
}

void downColor(int y, int x) {    
    int cnt = 0;

    for(int i = MAXH; i > 0; i--) {
        if (map[i][x] == '.') {
            cnt++;
            continue;
        }

        if (cnt != 0) {
            map[i + cnt][x] = map[i][x];
            map[i][x] = '.';
        }
    }
    
}

int solve() {
    /*
    1. 가장 아랫줄부터 차례로 확인하기
    2. 상하좌우 4개 이상 연결돼있다면 터뜨리고 '.'으로 바꾸기 (연쇄 +1)
    3. 빈 공간에 맞춰 뿌요 내리기
    4. 터지는게 없을 때까지 1~3 반복
    */
    int ret = 0;
    bool flag = false;

    while (1) {
        // 1. 바닥부터 터뜨릴 뿌요 있는지 확인
        for(int i = MAXH; i > 0; i--) {
            for(int j = 1; j <= MAXW; j++) {
                if (map[i][j] == '.') continue;

                cnt = 0;
                curr = map[i][j];
                checkColor(i, j);                   // 연속된 개수 체크

                if (cnt > 3) {
                    curr = '.';
                    flag = true;
                }

                setColor(i, j);                     // 원래대로 돌려놓거나 터뜨리거나
            }
        }

        // 2. 터뜨렸다면 연쇄 +1
        if (flag) ret++;
        else break;

        // 3. 뿌요 내리기
        for(int i = MAXW; i > 0; i--) {
            downColor(0, i);
        }

        flag = false;
    }

    return ret;
}

int main(){
    int T, t, ans = -1;
    cin >> T;

    for (t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        ans = solve();

        cout << ans << endl;//출력하는 부분
    }
    return 0;
}