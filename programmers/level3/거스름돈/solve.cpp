// 22.03.18. 거스름돈
#include <string>
#include <vector>
#include <iostream>
using namespace std;

const int MOD = 1000000007;

int solution(int n, vector<int> coins) {
    // 동전으로 N원을 만드는 방법의 수
    vector<int> dp(n + 1);
    
    // 0원을 만드는 방법의 수 : 1 (아무동전도 사용하지 않는 것)
    dp[0] = 1;
    
    // [N]원을 만드는 방법의 수 += [N - x]원을 만드는 방법의 수 (x = 코인)
    for (int coin : coins) {
        cout << "coin :: " << coin << endl;
        for (int i = coin; i <= n; ++i) {
            dp[i] += dp[i - coin]; 
            dp[i] %= MOD;
        }
    }
    
    return dp[n];
}