// week16-4 skt 대비 문제 풀이 3번

/*
N*M 사이즈의 맵이주어지고, 뭐 있으면 #, 없으면 . 로 된 스트링 맵
(0,0)은 항상 비어있고, 여기가 시작점
U => 위로 D 아래로 L 왼쪽 R 오른쪽
.으로 된 곳만 갈 수 있음. 최종 좌표 리턴
*/
#include <vector>
#include <iostream>
#include <string>
#include <queue>
#include <utility>
using namespace std;

int N, M;

pair<int, int> get_point(char M, int y, int x) {
	switch (M) {
		case 'L':
			return make_pair(y, x - 1);
		case 'R':
			return make_pair(y, x + 1);
		case 'U':
			return make_pair(y - 1, x);
		case 'D':
			return make_pair(y + 1, x);
	}
}

vector<int> solution(vector<string> board, string moves) {
	if (moves == "") return { 0,0 };
	
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	int mIdx = 0;

	int y, x;

	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		char var = board[y][x];
		q.pop();

		while (mIdx < moves.size()) {
			pair<int, int> next = get_point(moves[mIdx++], y, x);
			int ny = next.first;
			int nx = next.second;

			if (ny < 0 || ny > N - 1 || nx < 0 || nx > M - 1) continue;
			if (board[ny][nx] == '#') continue;

			q.push(next);
			break;
		}
	}

	return { y, x };
}