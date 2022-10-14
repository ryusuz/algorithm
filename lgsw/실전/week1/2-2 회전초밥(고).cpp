#include <iostream>
#include <map>
using namespace std;

int N, D, K, C;
int A[3000000+10];
int check[3000+10] = {0};

void InputData(){
    cin >> N >> D >> K >> C;
    for (int i=0; i<N ; i++){
        cin >> A[i];
    }
}

int solve() {
    int ret;
    int cnt = 1;
    check[C] = 1;

    for(int i = 0; i < K; i++) {
        int var = A[i % N];

        if (!check[var]++) cnt++;

        cout << var << "[" << check[var] << "] ";
    }
    cout << " :: " << cnt << endl;

    ret = cnt;

    int s = 0;
    for(int i = K; i < N + K; i++) {
        if (check[A[s++]]-- == 1) cnt--;

        if (!check[A[i % N]]++) cnt++;

        // for(int j = s; j <= i; j++) {
        //     cout << A[j] << "[" << check[A[j]] << "] ";
        // }
        // cout << " :: " << cnt << endl;

        ret = max(ret, cnt);
    }

    return ret;
}


int main122(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}