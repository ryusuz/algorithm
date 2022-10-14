#include <iostream>
#include <algorithm>
using namespace std;
#define MAXNM ((int)1e5)

int N, M;                   //소마리수, 잔디구간 개수
long long A[MAXNM+10];      //잔디 구간 시작
long long B[MAXNM+10];      //잔디 구간 끝

struct Info {
    long long s, e;
};

Info grass[MAXNM + 10];

void InputData(){
	cin >> N >> M;
	for (int i=0 ; i<M ; i++){
		cin >> A[i] >> B[i];
        grass[i] = {A[i], B[i]};
	}
}

bool cmp(Info a, Info b) {
    return a.s < b.s;
}

bool check(int m) {
    long long cnt = 0;
    long long pos = grass[0].s;

    for(int i = 0; i < M; i++) {
        if (pos < grass[i].s) pos = grass[i].s;

        if (pos > grass[i].e) continue;

        long long cow = (grass[i].e - pos) / m;     // 현재 위치에서 해당 구역 끝까지 배치할 수 있는 소의 수
        cnt += (cow + 1);                           // pos 위치의 소도 포함해야함
        pos += ((cow * m) + m);                     // 다음 pos로 갱신

        // while (pos <= grass[i].e) { // 시간 초과
        //     cnt++;
        //     pos += m;
        // }
    }

    return cnt < N;
}

long long solve() {
    long long ret = 0;

    sort(grass, grass + M, cmp);

    long long s = 1;
    long long e = grass[M-1].e - grass[0].s;  // 가장 끝과 가장 앞의 차이

    while (s <= e) {
        long long mid = (s + e) / 2;

        // 적거나 같을 때 갱신 해줬을 때 25퍼, 크거나 같을 때 갱신했더니 75퍼임
        if (check(mid)) {   // 소가 적으면 => 거리 줄이기
            e = mid - 1;
        } else {            // 소가 많아도 상관없음
            ret = mid;
            s = mid + 1;
        }
    }

    return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long ans = -1;
	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = solve();

	cout << ans << "\n";// 출력하는 부분
	return 0;
}