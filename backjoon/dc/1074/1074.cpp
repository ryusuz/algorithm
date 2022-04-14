// 22.04.14. 1074 Z
#include <iostream>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

int N, r, c;
int answer = 0;

void Input() {
	cin >> N >> r >> c;
}

int main() {
	Input();
	
	int standard = pow(2, N);

	while (N > 0) {
		standard /= 2;
		int y, x;

		if (r < standard && c < standard) {
			answer += (standard * standard) * 0;
			y = 0, x = 0;
		} else if (r < standard && c >= standard) {
			answer += (standard * standard) * 1;
			y = 0, x = standard;
		} else if (r >= standard && c < standard) {
			answer += (standard * standard) * 2;
			y = standard, x = 0;
		} else if (r >= standard && c >= standard) {
			answer += (standard * standard) * 3;
			y = standard, x = standard;
		}

		r -= y, c -= x;
		N--;
		
	}

	cout << answer << '\n';

}