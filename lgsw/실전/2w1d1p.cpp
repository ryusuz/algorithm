#include <iostream>
#include <string>
#include <queue>

using namespace std;

#define MAX_N (300000)

int N, K;
string name[MAX_N + 10];

queue<int> q[21];

long long solve() {
    long long cnt = 0;

    for(int i = 0; i < N; i++) {
        int len = name[i].length();

        while (!q[len].empty() && i - q[len].front() > K) q[len].pop();

        cnt += q[len].size();
        q[len].push(i);
    }

    return cnt;
}

// int lens[21] = {0};

// int solve() {
// 	int len;
// 	int cnt = 0;
// 	queue<int> q;

// 	for(int i = 0; i <= K; i++) {
// 		len = name[i].length();
// 		lens[len]++;
// 		q.push(len);

// 		if (lens[len] > 1) cnt += (lens[len] - 1);
// 	}

// 	for(int i = K+1; i < N; i++) {
// 		// 맨앞 빼줌
// 		lens[q.front()]--;
// 		q.pop();

// 		// 하나 추가
// 		len = name[i].length();
// 		lens[len]++;
// 		q.push(len);

// 		if (lens[len] > 1) cnt+= (lens[len] - 1);
// 	}

// 	return cnt;
// }

void Input_Data(void) {
	string str;
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> name[i];
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	long long sol = -1;

	// 입력 받는 부분
	Input_Data();

	// 여기서부터 작성
	sol = solve();

	// 출력하는 부분
	cout << sol << '\n';

	return 0;
}