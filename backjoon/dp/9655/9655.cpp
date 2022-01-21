// 9655 돌 게임
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	string answer = (N % 2 == 0) ? "CY" : "SK";
	cout << answer;

	return 0;
}

