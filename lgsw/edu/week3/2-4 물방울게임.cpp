#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (100)
#define INF (1<<30)

int A;              // 유저
int N;              // 필드 물방울 수
int W[MAXN+10];     // 필드 물방울 크기 배열

int sol;

void dfs(int sum, int idx, int cnt) {
    if (cnt >= sol) {
        return;
    }

    if (idx >= N) {
        sol = cnt;
        return;
    }

    if (sum > W[idx]) dfs(sum + W[idx], idx + 1, cnt);
    else {
        if (sum > 1) dfs(sum + sum - 1, idx, cnt + 1);          // 생성
        dfs(A, N, cnt + N - idx);                               // 제거 (여기서 제거하면 뒤에는 모두 제거하는게 좋음 - 가지치기) (시간: 3)
        // dfs(sum, idx + 1, cnt + 1);                            가지치기 안 한 제거 방법 (시간: 24)
    }
}

int solve() {
    sol = N;

    sort(W, W + N);

    dfs(A, 0, 0);

    return sol;
}

void InputData(){
    cin >> A >> N;
    for (int i=0; i<N; i++){
        cin >> W[i];
    }
}

int main(){
    int t, T, ans = -1;
    cin >> T;
    for (t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        ans = solve();

        cout << "Case #" << t << ": " << ans << endl;//출력하는 부분
    }
    return 0;
}