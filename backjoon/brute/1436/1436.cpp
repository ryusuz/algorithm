// 1436 영화감독 숌
#include <iostream>
#include <string>
using namespace std;

int N;
int answer;

void input();

int main() {
	input();

	int series = 1;
	int num = 666;

	while (series < N) {
		string snum = to_string(++num);
		if (snum.find("666") != string::npos) series++;
	}

	cout << num;

	return 0;
}

void input() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

	cin >> N;
}