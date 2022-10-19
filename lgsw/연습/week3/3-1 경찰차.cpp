#include <iostream>
using namespace std;

#define MAXW (20)
#define INF (1<<30)

int N;//도로의 개수
int W;//사건의 개수

struct POS{
	int r, c;//세로, 가로
};

POS pos[MAXW+10];//사건 좌표
int sol;

void InputData() {
	cin >> N;
	cin >> W;
	for (int i=0; i<W; i++){
		cin >> pos[i].r >> pos[i].c;
	}
}

int getDist(POS a, POS b) {
    return abs(a.r - b.r) + abs(a.c - b.c);
}

void dfs(int idx, int dist, POS p1, POS p2) {         // 사건 위치, 거리, 경찰차1, 경찰차2
    if (dist >= sol) return;

    if (idx >= W) {
        sol = dist;
        return;
    }

    int d1 = getDist(p1, pos[idx]);
    int d2 = getDist(p2, pos[idx]);

    dfs(idx + 1, dist + d1, pos[idx], p2);
    dfs(idx + 1, dist + d2, p1, pos[idx]);
}

int solve() {
    int ret = 0;
    sol = INF;

    POS p1 = {1, 1};
    POS p2 = {N, N};

    dfs(0, 0, p1, p2);

    return sol;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	//여기서부터 작성
    ans = solve();

	cout << ans << "\n";//출력하는 부분
	return 0;
}