// 기존 코드
#include <iostream>
using namespace std;

int N; // 모눈종이의 가로,세로 크기
char paper[302][302]; //모눈종이
int sx, sy; //특정좌표의 x위치와 y위치

void InputData(void) {
	cin >> N >> sx >> sy;
	for (int i = 1; i <= N; i++){
		cin >> &paper[i][1];
	}
}

int main(void) {
	
	int ans = -1;
	InputData(); // 입력함수	

	// 코드를 작성하세요
	
	cout << ans << endl;
	return 0;
}


// 제출코드 (30점)
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int N; // 모눈종이의 가로,세로 크기
char paper[302][302]; //모눈종이
int sx, sy; //특정좌표의 x위치와 y위치

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int miny, minx;
int maxy, maxx;

void InputData(void) {
	cin >> N >> sx >> sy;
	for (int i = 1; i <= N; i++){
		cin >> &paper[i][1];
	}
}

bool check(int y, int x) {
	if (y < 1 || y > N || x < 1 || x > N) return false;
	return true;
}

int bfs(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});
	paper[y][x] = '#';
	
	miny = N+10; minx = N+10;
	maxy = 0; maxx = 0;
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
				
		miny = (y < miny) ? y : miny;
		minx = (x < minx) ? x : minx;
		
		maxy = (y > maxy) ? y : maxy;
		maxx = (x > maxx) ? x : maxx;
		
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (!check(ny, nx) || paper[ny][nx] != '*') continue;
			
			q.push({ny, nx});
			paper[ny][nx] = '#';
		}
	}
	
	if (sy < miny) return 0;
	if (sx < minx) return 0;
	
	if (sy > maxy) return 0;
	if (sx > maxx) return 0;
	
	return 1;
}

int solve() {
	int ret = 0;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if (paper[i][j] == '*') {
				ret += bfs(i, j);
			}
		}
	}
	
	return ret;
}

int main(void) {
	
	int ans = -1;
	InputData(); // 입력함수	

	// 코드를 작성하세요
	ans = solve();
	
	cout << ans << endl;
	return 0;
}


// 90점 코드
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

int N; // 모눈종이의 가로,세로 크기
char paper[302][302]; //모눈종이
int sx, sy; //특정좌표의 x위치와 y위치

int dy[4] = {0, 1, 0, -1};
int dx[4] = {1, 0, -1, 0};

int miny, minx;
int maxy, maxx;

void InputData(void) {
	cin >> N >> sx >> sy;
	for (int i = 1; i <= N; i++){
		cin >> &paper[i][1];
	}
}

bool check(int y, int x) {
	if (y < 0 || y > N+1 || x < 0 || x > N+1) return false;
	return true;
}

bool isInside(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});
	
	bool visited[302][302] = {false};
	visited[y][x] = true;
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		
		if (y == 0 || x == 0) return false;
				
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (!check(ny, nx) || visited[ny][nx] || paper[ny][nx] == '#') continue;
			
			visited[ny][nx] = true;
			q.push({ny, nx});
		}
	}
	
	return true;
}

void change(int y, int x) {
	queue<pair<int, int>> q;
	q.push({y, x});
	paper[y][x] = '+';
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (!check(ny, nx) || paper[ny][nx] != '#') continue;
			
			q.push({ny, nx});
			paper[ny][nx] = '+';
		}
	}
}

int bfs(int r, int c) {
	
	int y = r; int x = c;
	queue<pair<int, int>> q;
	q.push({y, x});
	paper[y][x] = '#';
	
	while (!q.empty()) {
		y = q.front().first;
		x = q.front().second;
		q.pop();
		
		for(int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			
			if (!check(ny, nx) || paper[ny][nx] != '*') continue;
			
			q.push({ny, nx});
			paper[ny][nx] = '#';
		}
	}
	
	bool flag = isInside(sy, sx);
	change(r, c);
	
	if (!flag) return 0;
	return 1;
}

int solve() {
	int ret = 0;
	
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			if (paper[i][j] == '*') {
				ret += bfs(i, j);	
			}
		}
	}
	
	return ret;
}

int main(void) {
	
	int ans = -1;
	InputData(); // 입력함수	

	// 코드를 작성하세요
	ans = solve();
	
	cout << ans << endl;
	return 0;
}