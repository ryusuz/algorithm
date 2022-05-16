// 5866 카드 놓기
#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

int n, k;
vector<int> cards;
int answer;
bool visited[11] = { false };
set<string> comb;

void input();

auto recursion(int x, int cnt, string s) {
	if (cnt == k) return comb.insert(s);

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			recursion(i, cnt + 1, s + to_string(cards[i]));
			visited[i] = false;
		}
	}
}

int main() {
	input();

	recursion(0, 0, "");
	cout << comb.size();

	return 0;
}

void input() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		cards.push_back(num);
	}
}