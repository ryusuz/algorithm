#include <iostream>
using namespace std;

int N;
int W[20 + 10];

int sol;

void InputData(){
    cin >> N;
    for (int i=1 ; i<= N ; i++){
        cin >> W[i];
    }

    W[0] = 0;
    W[N+1] = 0;
}

bool check(int n1, int n2) {
    int n1r, n2r;

    while (n1 > 0 || n2 > 0) {
        n1r = n1 % 10;
        n2r = n2 % 10;

        n1 /= 10;
        n2 /= 10;

        if (n1r + n2r > 9) return false;
    } 

    return true;
}

void dfs(int cnt, int idx, int sum) {
    if (sol >= cnt + N - idx) return;       // 남은 소를 모두 태워도 sol보다 작으면 가지치기

    if (!check(sum , W[idx])) return;

    sum += W[idx];

    if (idx >= N+1) {
        sol = max(cnt, sol);
        return;
    }

    for(int i = idx + 1; i <= N+1; i++) {
        dfs(cnt + 1, i, sum);
    }
}

int solve() {
    sol = 0;

    dfs(0, 0, 0);

    return sol - 1;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}