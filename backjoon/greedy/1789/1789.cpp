// 1789 뒤집기
#include <vector>
#include <string>
#include <queue>
#include <iostream>
using namespace std;

void input();
string S;
int answer;

int main() {
	input();
	int zeros = 0, ones = 0;

	if (S[0] == '0') zeros++;
	else ones++;

	for (int i = 1; i < S.size(); i++) {
		if (S[i - 1] != S[i]) {
			if (S[i] == '0') zeros++;
			else ones++;
		}
	}

	answer = min(zeros, ones);
	cout << answer;

	return 0;
}

void input() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> S;
}