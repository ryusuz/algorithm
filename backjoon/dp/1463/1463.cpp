// 22.05.16.
#include <iostream>
using namespace std;

int N;
int dp[1000001] = {0};

int main() {
    cin >> N;

    dp[2] = 1;
    dp[3] = 1;

    for(int i = 4; i <= N; i++) {
        int tmp = dp[i-1] + 1;

        if (i % 2 == 0) tmp = min(tmp, dp[i / 2] + 1);
        
        if (i % 3 == 0) tmp = min(tmp, dp[i / 3] + 1);
        
        dp[i] = tmp;
    }

    cout << dp[N] << endl;

    return 0;
}