// 2110 공유기 설치
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int N, C;
vector<int> house;

void input();

int main() {
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();

	int left = 1;
	int right = house[N - 1] - house[0];
	int d = 0, ans = 0;

	while (left <= right) {
		int mid = (left + right) / 2;
		int start = house[0];
		int cnt = 1;

		for (int i = 0; i < N; i++) {
			d = house[i] - start;
			if (mid <= d) {
				++cnt;
				start = house[i];
			}
		}

		if (cnt >= C) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}

	cout << ans;
	return 0;
}

void input() {
	//cin >> N;
	scanf("%d %d", &N, &C);

	for (int i = 0; i < N; i++) {
		int n;
		scanf("%d", &n);
		house.push_back(n);
	}

	sort(house.begin(), house.end());
	
}