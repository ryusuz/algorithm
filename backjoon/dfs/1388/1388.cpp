//1388 바닥 장식
#include <vector>
#include <string>
#include <stack>
#include <iostream>

using namespace std;
int n, m;

vector<vector<bool>> isVisit;

struct point {
	int x, y;
};

int dfs(vector<string> floor, int px, int py) {
	stack<point> st;
	st.push({ px, py });

	while (!st.empty()) {
		int x = st.top().x;
		int y = st.top().y;
		//cout << st.top().x << st.top().y << endl;

		char cur = floor[x][y];
		//cout << "???" << endl;
		st.pop();

		int nextX = x;
		int nextY = y;
		
		//cout << x << " << x , x+1 >> " << x + 1 << "::: n = " << n << endl;
		
		if (cur == '-' && y + 1 < m) {
			nextY += 1;
			//cout << "in (-) ::: xy = " << nextX << nextY << endl;
		}
		else if (cur == '|' && x + 1 < n) {
			nextX += 1;
			//cout << "in (|)xy = " << nextX << nextY << endl;
		}
		else break;

		char next = floor[nextX][nextY];
		//cout << ">>>>> dfs:::nextX, nextY, next ::" << nextX << nextY << " " << next << endl;

		// cur 2,2 -> next 3,2
		if (cur != next) break;
		else {
			st.push({ nextX, nextY });
			isVisit[nextX][nextY] = true;
			//cout << ">>>>> dfs::cur == next :: " << cur << next << endl;
		}
	}

	return 1;
}


int main() {
	// input
	cin >> n >> m;

	vector<string> floor;
	for (int i = 0; i < n; i++) {
		string tmp = "";
		cin >> tmp;
		floor.push_back(tmp);
	}

	// isVisit 초기화
	for (int i = 0; i < n; i++) {
		vector<bool> v;
		for (int j = 0; j < m; j++) v.push_back(false);
		isVisit.push_back(v);
	}

	// output
	int answer = 0;
	for (int i = 0; i < floor.size(); i++) {
		for (int j = 0; j < floor[0].size(); j++) {
			//cout << "main (" << i << j << ") :: " << floor[i][j] << " ::isVisit? => " << isVisit[i][j];
			if (!isVisit[i][j]) {
				//cout << " >>>> begin dfs!!! ::: " << i << j << endl;
				answer += dfs(floor, i, j);
			}
			//cout << endl;
		}
	}
	cout << answer << endl;

	return 0;
}