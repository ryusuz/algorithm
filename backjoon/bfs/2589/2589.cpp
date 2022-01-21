// 2589 보물섬
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int c, r;
vector<string> map;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int bfs(int a, int b) {
	queue<pair<int, int>> q;
	vector<vector<bool>> isVisit;
	int dist[50][50] = { -1 };
	int maxDist = -1;

	for (int i = 0; i < c; i++) {
		vector<bool> v;
		for (int j = 0; j < r; j++) {
			v.push_back(false);
		}
		isVisit.push_back(v);
	}

	q.push(make_pair(a, b));
	isVisit[a][b] = true;

	while (!q.empty()) {
		int col = q.front().first;
		int row = q.front().second;
		char cur = map[col][row];
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nextC = col + dx[i];
			int nextR = row + dy[i];

			if (nextC < 0 || nextC >= c || nextR < 0 || nextR >= r) continue;
			char next = map[nextC][nextR];
			if (!isVisit[nextC][nextR] && cur == next) {
				q.push(make_pair(nextC, nextR));
				isVisit[nextC][nextR] = true;
				dist[nextC][nextR] = dist[col][row] + 1;
				maxDist = max(dist[nextC][nextR], maxDist);
			}
		}

	}

	return maxDist;
}

int main() {
	cin >> c >> r;
	for (int i = 0; i < c; i++) {
		string tmp = "";
		cin >> tmp;
		map.push_back(tmp);
	}

	int answer = 0;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (map[i][j] == 'L') {
				answer = max(answer, bfs(i, j));
			}
		}
	}

	cout << answer << endl;
	return 0;
}