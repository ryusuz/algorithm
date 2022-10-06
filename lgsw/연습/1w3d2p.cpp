#include <iostream>
using namespace std;

int K;              // 면적당 참외 개수
int ds[6+10];       // 방향 (동서남북 1234)
int lens[6+10];     // 길이

void InputData(){
    cin >> K;
    for (int i=0 ; i<6 ; i++){
        cin >> ds[i] >> lens[i];
    }
}

int solve() {
    int total, rest;
    for(int i = 0; i < 6; i++) {
        if ((ds[i] == ds[(i + 2) % 6]) && (ds[(i + 1) % 6] == ds[(i + 3) % 6])) {
            total = lens[(i+4) % 6] * lens[(i+5) % 6];
            rest = lens[(i+1) % 6] * lens[(i+2) % 6];
            break;
        }
    }

    return (total - rest) * K;
}

int main132(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}