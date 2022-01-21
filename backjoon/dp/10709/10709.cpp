// 10709 기상캐스터
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int H, W;
vector<string> map;
int dp[100][100] = { -1 };

void input();

int main() {
	input();
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			dp[i][j] = -1;
		}
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			//cout << "dp check::" << dp[i][j] << endl;
			if (map[i][j] == 'c') {
				//cout << "c::" << i << j << endl;
				//cout << "before dp = " << dp[i][j] << endl;
				dp[i][j] += 1;
				//cout << "after dp = " << dp[i][j] << endl;

				for (int k = j+1; k < W; k++) {
					//cout << "k>>>" << k << "map:: " << map[i][k] << endl;
					if (map[i][k] == 'c') break;
					dp[i][k] = dp[i][k - 1] + 1;
					//cout << "dp :: " << dp[i][k] << endl;
				}
			}

			cout << dp[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}

void input() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> H >> W;
	for (int i = 0; i < H; i++) {
		string tmp = "";
		cin >> tmp;
		map.push_back(tmp);
	}
}