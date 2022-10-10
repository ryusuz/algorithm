#include <iostream>
using namespace std;

int N;//색종이 수
int X[100+10];
int Y[100+10];

int miny, minx;
int maxy, maxx;

int board[110][110] = {0};

void InputData() {
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> X[i] >> Y[i];
    }
}

void setPaper(int y, int x) {
    for(int i = y; i < y + 10; i++) {
        for(int j = x; j < x + 10; j++) {
            board[i][j] = 1;
        }
    }
}

int solve() {
    int ret;

    miny = 200; minx = 200;
    maxy = 0; maxx = 0;

    for(int i = 0; i < N; i++) {
        setPaper(Y[i], X[i]);

        miny = min(miny, Y[i] - 1);
        minx = min(minx, X[i] - 1);
        maxy = max(maxy, Y[i] + 10);
        maxx = max(maxx, X[i] + 10);
    }

    for(int i =  miny; i < maxy; i++) {
        for(int j = minx; j < maxx; j++) {
            cout << board[i][j];
        }
        cout << endl;
    }
    cout << endl;

    return ret;
}

int main() {
    int ans = -1;
    InputData();//입력받는 부분
    
    //여기서부터 작성
    ans = solve();
    
    cout << ans << endl;//출력하는 부분
    return 0;
}