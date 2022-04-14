// 22.04.14. 1012 유기농 배추
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int T, N, M, K;
vector<vector<int>> board;
vector<vector<int>> visit;
vector<int> answer;

void setBoard() {
	board.clear();
	visit.clear();
	board = visit = vector<vector<int>> (N, vector<int> (M, 0));

	for(int i = 0; i < K; i++) {
		int x, y;
		cin >> x >> y;
		board[y][x] = 1;		
	}
}

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});

	int dy[4] = {-1, 1, 0, 0};
	int dx[4] = {0, 0, -1, 1};

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || nx < 0 || ny >= N || nx >= M) continue;

			if (board[ny][nx] == 1 && !visit[ny][nx]) {
				q.push({ny, nx});
				visit[ny][nx] = 1;
			}
		}
	}

	return 1;
}

int solution() {
	int ret = 0;

	for(int i = 0; i < N; i++) {
		for(int j = 0; j < M; j++) {
			if (board[i][j] == 1 && !visit[i][j]) {
				ret += bfs(i, j);		
			}	
		}
	}

	return ret;
}

int main() {
	cin >> T;

	for(int i = 0; i < T; i++) {
		cin >> M >> N >> K;
		setBoard();
		answer.push_back(solution());
	}

	for(int i = 0; i < T; i++) {
		cout << answer[i] << '\n';
	}
}