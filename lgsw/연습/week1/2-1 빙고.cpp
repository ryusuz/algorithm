#include <iostream>
using namespace std;

int A[5+10][5+10];
int B[25+10];
int ans;

void InputData(){
    for (int i=0; i<5; i++){
        for (int j=0; j<5; j++){
            cin >> A[i][j];
        }
    }
    for (int i=0; i<25; i++){
        cin >> B[i];
    }
}

bool check(int y, int x) {
    // y줄 확인
    int cnt = 0;
    for(int i = 0; i < 5; i++) {
        if (A[i][x] == 0) cnt++;
        else break;
    }

    if (cnt == 5) ans++;
    if (ans == 3) return true;
    cnt = 0;

    // x줄 확인
    for(int i = 0; i < 5; i++) {
        if (A[y][i] == 0) cnt++;
        else break;
    }

    if (cnt == 5) ans++;
    if (ans == 3) return true;

    cnt = 0;
    
    // 대각선 확인
    for(int i = 0; i < 5; i++) {
        if (A[i][i] == 0) cnt++;
        else break;
    }

    if (cnt == 5) ans++;
    if (ans == 3) return true;

    cnt = 0;

    int j = 4;
    for(int i = 0; i < 5; i++) {
        if (A[i][j--] == 0) cnt++;
        else break;
    }

    if (cnt == 5) ans++;
    if (ans == 3) return true;

    return false;
}

int solve() {
    ans = 0;

    for(int k = 0; k < 25; k++) {
        //findNum(B[i]);
        int y, x;

        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                if (A[i][j] == B[k]) {
                    A[i][j] = 0;
                    y = i;
                    x = j;
                }
            }
        }

        cout << "[" << B[k] << "]" << endl;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 5; j++) {
                cout << A[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        
        if (check(y, x)) {
            return B[k];
        }

    }

    return -1;
}

int main(){
    int ret = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ret = solve();

    cout << ret << endl;// 출력하는 부분
    return 0;
}