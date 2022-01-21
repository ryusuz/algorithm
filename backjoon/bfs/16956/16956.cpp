// 16956 늑대와 양 (bfs)
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int r, c;
vector<string> pasture;
vector<vector<bool>> isVisit;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};

int bfs(int i, int j) {
	// 인접한 곳에 양이 있는지 보기
	isVisit[i][j] = true;

	int col = i;
	int row = j;
	char cur = pasture[col][row];

	for (int i = 0; i < 4; i++) {
		int nextC = col + dx[i];
		int nextR = row + dy[i];

		if (nextC < 0 || nextC >= c || nextR < 0 || nextR >= r) continue;

		char next = pasture[nextC][nextR];
		if (next == 'S') return 0;

		if (!isVisit[nextC][nextR]) {
			if (next == '.') {
				pasture[nextC][nextR] = 'D';
			}
		}
	}

	return 1;
}

int main() {
	//enter input and initialization
	cin >> c >> r;
	for (int i = 0; i < c; i++) {
		string tmp;
		cin >> tmp;
		pasture.push_back(tmp);

		vector<bool> v;
		for (int j = 0; j < r; j++) {
			v.push_back(false);
		}
		isVisit.push_back(v);
	}

	int answer = 1;
	for (int i = 0; i < c; i++) {
		for (int j = 0; j < r; j++) {
			if (pasture[i][j] == 'W') {
				answer = bfs(i, j);
				if (answer == 0) break;
			}
		}
	}

	// output
	cout << answer << endl;
	for (auto& str : pasture) {
		if (answer == 0) break;
		cout << str << endl;
	}

	return 0;
}
