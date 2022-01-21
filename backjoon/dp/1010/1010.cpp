// 1010 다리 놓기 (DP)
#include <vector>
#include <iostream>
using namespace std;

int dp[31][31];
int n, m;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	for (int i = 0; i < 31; i++) dp[1][i] = i;

	for (int i = 2; i < 31; i++) {
		for (int j = i; j < 31; j++) {
			for (int k = j; k >= i; k--) {
				dp[i][j] += dp[i - 1][k - 1];
			}
		}
	}

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		cout << dp[n][m] << "\n";
	}

	return 0;
}