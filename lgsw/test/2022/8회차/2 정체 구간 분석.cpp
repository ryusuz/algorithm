// 기존 코드
#include <iostream>
using namespace std;

int N; // 차량 수
int T; // 측정 시간(분단위)
int G[100000 + 10]; // 차량 구간 번호
int S[100000 + 10]; // 차량 속도(분당)

void InputData()
{
	cin >> N >> T;
	for (int i = 0; i < N; i++){
		cin >> G[i] >> S[i];
	}
}

int main()
{
	int sol = -1;
	InputData(); // 입력 함수
	
	// 코드를 작성하세요

	
	cout << sol << endl; // 정답 출력
	return 0;
}


// 제출코드 (70/100)
#include <iostream>
#include <algorithm>
using namespace std;

#define MAXN (100000)

int N; // 차량 수
int T; // 측정 시간(분단위)
int G[100000 + 10]; // 차량 구간 번호
int S[100000 + 10]; // 차량 속도(분당)

struct car{
	int g, s, n;
};

car info[MAXN+10];
int group[MAXN+10];

void InputData()
{
	cin >> N >> T;
	for (int i = 0; i < N; i++){
		cin >> G[i] >> S[i];
	}
}

bool cmp(car a, car b) {
	return a.g > b.g;
}

int solve() {
	int ret = 0;
	
	for(int i = 0; i < N; i++) {
		info[i] = {G[i], S[i], i};
		group[i] = 1;
	}
	
	sort(info, info + N, cmp);
	
	for(int i = 0; i < N; i++) {
		int pos = info[i].g + (info[i].s * T);
		
		if (i != 0 && pos >= info[i-1].g) {
			pos = info[i-1].g;
			group[info[i-1].n]++;
			group[info[i].n]--;
			
			info[i].n = info[i-1].n;
		}
		
		info[i].g = pos;
	}
	
	ret = *max_element(group, group + N);

	return ret;
}

int main()
{
	int sol = -1;
	InputData(); // 입력 함수
	
	// 코드를 작성하세요
	sol = solve();
	
	cout << sol << endl; // 정답 출력
	return 0;
}