// 1018 체스판 다시 칠하기 (bfs 이용)
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

#define MAX 50*50;
int answer = MAX;
int N, M;	// 8 <= N, M <= 50
vector<string> board;
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };

void input();

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	int n = y+8; int m = x+8;
	int count = 0;
	vector<string> cpBoard = board;

	//cout << "[" << y << x << "]" << endl;

	// visit 초기화
	vector<vector<bool>> visit;
	for (int i = 0; i < N; i++) {
		vector<bool> tmp;
		for (int j = 0; j < M; j++) {
			tmp.push_back(false);
		}
		visit.push_back(tmp);
	}

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		char val = cpBoard[y][x];
		q.pop();

		for (int i = 0; i < 2; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			//cout << "hey" << endl;
			if (ny >= n || nx >= m) continue;
			//cout << "here" << endl;
			char nval = cpBoard[ny][nx];

			//cout << "is visit next = " << visit[ny][nx] << endl;
			if (!visit[ny][nx]) {
				//cout << "in!!!" << endl;

				q.push(make_pair(ny, nx));
				visit[ny][nx] = true;

				if (val == nval) {
					//cout << y << x << " = " << val << " /// " <<ny << nx << " = " << nval << endl;
					count++;

					if (val == 'W') cpBoard[ny][nx] = 'B';
					else cpBoard[ny][nx] = 'W';
				}
			}
		}
	}

	//cout << count << endl << endl;
	return count;
}

int main() {
	input();
	
	for (int i = 0; i <= N-8; i++) {
		for (int j = 0; j <= M - 8; j++) {
			if (board[i][j] == 'B') {
				answer = min(answer, bfs(i, j));
				board[i][j] = 'W';
				answer = min(answer, bfs(i, j) + 1);
			}
			else {
				answer = min(answer, bfs(i, j));
				board[i][j] = 'B';
				answer = min(answer, bfs(i, j) + 1);
			}
		}
	}

	cout << answer;

	return 0;
}

void input() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		board.push_back(s);
	}
}