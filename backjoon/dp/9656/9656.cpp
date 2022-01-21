// 9656 돌 게임2
#include <vector>
#include <string>
#include <iostream>
using namespace std;

int N;

int main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	
	cin >> N;
	string answer = (N % 2 == 0) ? "SK" : "CY";
	cout << answer;

	return 0;
}

