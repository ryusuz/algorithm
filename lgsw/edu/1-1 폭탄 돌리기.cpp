#include <iostream>
using namespace std;
#define MAXN (100)

int K;//처음 폭탄을 가진 사람 번호
int N;//퀴즈 개수
int T[MAXN+10];//걸린 시간
char Z[MAXN+10];//정답 여부

void InputData(){
    cin >> K;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> T[i] >> Z[i];
    }
}

int solve() {
    cout << "solve" << endl;
    int time = 0;
    int cnt = 0;
    int k = K-1;

    while (cnt < N) {
        k = (k == 8) ? 0 : k;
        cout << k << " ";

        time += T[cnt];
        cout << time << " " << cnt;

        if (time >= 210) break;

        if (Z[cnt] == 'T') {
            k++;
        }

        cnt++;
    }

    return k+1;
}

int main11(){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}
