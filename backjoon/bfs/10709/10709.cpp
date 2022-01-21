// 10709 기상캐스터
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int H, W;
vector<string> map;
vector<vector<bool>> visit;
vector<vector<int>> dp;

void input();

void bfs(int i, int j) {
	queue<pair<int, int>> q;
	q.push(make_pair(i, j));
	visit[i][j] = true;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (x + 1 < 0 || x + 1 >= W) continue;

		if (map[y][x + 1] == '.') {
			q.push(make_pair(y, x + 1));
			visit[y][x + 1] = true;
			dp[y][x + 1] = dp[y][x] + 1;
		}

	}
}

int main() {
	input();
	for (int i = 0; i < H; i++) {
		vector<bool> tmp;
		vector<int> tmp2;
		for (int j = 0; j < W; j++) {
			tmp.push_back(false);
			tmp2.push_back(-1);
		}
		visit.push_back(tmp);
		dp.push_back(tmp2);
	}

	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!visit[i][j] && map[i][j] == 'c') {
				dp[i][j] = 0;
				bfs(i, j);
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