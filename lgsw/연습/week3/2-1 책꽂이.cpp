#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (20)
#define INF (1<<30)

int N, B;              // 소, 책꽂이 높이
int H[MAXN + 10];      // 각 소의 키

int sol;
int presum[MAXN + 10];  // 누적합을 구해서 남은 sum값이 목표값보다 작으면 가치지기!

void dfs(int idx, int sum) {
    if (B > sum + presum[N] - presum[idx-1]) return;
    
    if (sum >= B) {
        sol = min(sol, sum);
        return;
    }

    for(int i = idx + 1; i <= N; i++) {
        dfs(i, sum + H[i]);
    }
}

int solve() {
    int ret;
    sol = INF;

    for(int i = 1; i <= N; i++) {
        presum[i] = presum[i-1] + H[i];
    }

    dfs(0, 0);

    return sol - B;
}

void InputData(){
    cin >> N >> B;
    for (int i=1; i<=N; i++){
        cin >> H[i];
    }
}

int main (){
    int T, ans = -1;
    cin >> T;
    for (int t=1; t<=T; t++){
        InputData();//입력받는 부분

        //여기서부터 작성
        ans = solve();

        cout << ans << endl;
    }
    return 0;
}