#include <iostream>
using namespace std;

int W;//사용할 금액
int A[6];//각 동전 개수(갖고 있는)
int sol[6];//답

bool flag;
int max_cnt;
int presum[6];
int coin[6] = {500, 100, 50, 10, 5, 1};

void InputData(){
	cin >> W;
	for (int i=0; i<6; i++){
		cin >> A[i];
	}
}

void OutputData(int ans){
	cout << ans << "\n";
	for (int i=0; i<6; i++){
		cout << sol[i] << " ";
	}
	cout << "\n";
}

void dfs(int cnt, int idx, int sum, int c[]) {
    if (sum > W) {
        flag = true;
        return;
    }

    if (idx >= 6 && sum == W) {
        if (cnt > max_cnt) {
            max_cnt = cnt;
            for(int i = 0; i < 6; i++) {
                sol[i] = c[i];
            }
        }
        return;
    }

    // 에러
    for(int i = 1; i <= A[idx]; i++) {
        c[idx] = i;
        dfs(cnt + i, idx + 1, sum + coin[idx] * i, c);
        c[idx] = 0;

        if (flag) break;
    }

    if (flag) {
        flag = false;
        dfs(cnt, idx + 1, sum, c);
    }

}

int solve() {
    flag = false;
    max_cnt = 0;

    presum[0] = A[0];
    for(int i = 1; i < 6; i++) {
        presum[i] = presum[i-1] + A[i];
    }

    int c[6] = {0};
    dfs(0, 0, 0, c);

    return max_cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;

	InputData();//입력받는 부분

	//여기서부터 작성
    ans = solve();

	OutputData(ans);//출력하는 부분
	return 0;
}