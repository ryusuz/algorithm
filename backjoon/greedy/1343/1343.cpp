// 1343 폴리오미노
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

void input();
string board;
string answer;
queue<char> q;

int main() {
	input();
	int cnt = 0;

	for (int i = 0; i < board.size();) {
		if (board[i] == '.') {
			answer += '.';
			i += 1;

			continue;
		}

		int cnt = 0;

		for (int j = i; j < board.size() && board[j] == 'X'; j++) {
			cnt++;
		}

		i += cnt;

		if (cnt % 2 == 1) {
			cout << -1;
			return 0;
		}

		while (1) {
			if (cnt >= 4) {
				answer += "AAAA";
				cnt -= 4;
			}
			else if (cnt == 2) {
				answer += "BB";
				cnt -= 2;
			}
			else {
				break;
			}
		}
	}

	cout << answer;

	return 0;
}

void input() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> board;
}