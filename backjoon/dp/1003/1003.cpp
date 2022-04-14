// 22.04.14. 1003 피보나치 함수 (DP)
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Info {
	int zero, one;
};

vector<int> cases;
Info dp[41];
vector<vector<int>> answer;

void Input() {
	int T;
	cin >> T;

	cases = vector<int>(T, 0);
	answer = vector<vector<int>>(T, vector<int> (2, 0));

	for(int i = 0; i < T; i++) {
		cin >> cases[i];
	}
}

int main() {
	Input();

	dp[0] = {1, 0};
	dp[1] = {0, 1};

	for(int i = 2; i < 41; i++) {
		int zero = dp[i-1].zero + dp[i-2].zero;
		int one = dp[i-1].one + dp[i-2].one;
		dp[i] = {zero, one};
	}

	for(int i = 0; i < cases.size(); i++) {
		answer[i][0] = dp[cases[i]].zero;
		answer[i][1] = dp[cases[i]].one;

		cout << answer[i][0] << " " << answer[i][1] << "\n";
	}

	return 0;
}