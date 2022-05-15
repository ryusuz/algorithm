// 16173 점프왕 쩰리 (BFS)
#include <string>
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

int n, a[64][64];
int dx[2] = { 1, 0 };
int dy[2] = { 0, 1 };
bool isVisit[64][64];

struct jump {
	int x, y;
};

void bfs() {
	queue<jump> q;
	q.push({ 0, 0 });
	isVisit[0][0] = true;

	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		q.pop();

		int curSize = a[x][y];	// 현재 위치에서 점프할 수 있는 크기

		// 마지막 위치(n-1, n-1)에 도달하면 성공! 리턴하기
		if (curSize == -1) {
			cout << "HaruHaru" << endl;
			return;
		}

		for (int i = 0; i < 2; i++) {
			int nextX = x + dx[i] * curSize;
			int nextY = y + dy[i] * curSize;

			// 배열 인덱스 넘어가지 않도록 예외처리
			if (nextX < 0 || nextX >= n || nextY < 0 || nextY >= n) continue;

			if (!isVisit[nextX][nextY]) {
				q.push({ nextX, nextY });
				isVisit[nextX][nextY] = true;

			}
		}
	}

	cout << "Hing" << endl;
}

int main() {
	// input
	//cout << "크기: ";
	cin >> n;

	//cout << "맵: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}

	//output
	bfs();

	return 0;
}
