#include <iostream>
#include <algorithm>
#include <numeric>

using namespace std;

#define MAX_N (100000)

int N, M;
int need[MAX_N];

void Input_Data(void) {
	cin >> N >> M;
	for (int i = 0; i < N;i++) {
		cin >> need[i];
	}
}

bool check(int m) { 
    int k = 1;
    int money = m;

    for(int i = 0; i < N; i++) {
        // 인출
        if (need[i] > money) {
            k++;
            money = m;
        }

        // 사용
        money -= need[i];
    }

    return (k <= M);
}

int solve() { 
    int ret;   
    int s = *max_element(need, need + N);
    int e = accumulate(need, need + N, 0);

    while (s <= e) {
        int mid = (s + e) / 2;

        if (check(mid)) {    // 작거나 같으면 금액을 줄여도 됨 (작으면 억지로 한번더 인출하면 됨)
            e = mid - 1;
            ret = mid;
        } else {
            s = mid + 1;
        }
    }
    
    return ret;
}

int main(void) {
	ios_base::sync_with_stdio();
	cin.tie(nullptr);
	cout.tie(nullptr);
	int sol = -1;

	// 입력 받는 부분
	Input_Data();

	// 여기서부터 작성
    sol = solve();

	// 출력하는 부분
	cout << sol << '\n';

	return 0;
}