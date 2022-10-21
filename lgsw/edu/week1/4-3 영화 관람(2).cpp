#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)

int N;//영화수

struct DATA{
    int s, e;
};

DATA A[MAXN + 10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i].s >> A[i].e;
    }
}

bool cmp(DATA a, DATA b) {
    if (a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}

int solve() {
    int cnt = 1;
    int e = 0;

    sort(A, A+N, cmp);

    int idx;
    for(idx = 0; idx < N; idx++) {
        if (A[idx].e - A[idx].s >= 2) {
            e = A[idx].e;
            break;
        }
    }

    if (!e) return 0;

    for(int i = idx; i < N; i++) {
        if (e > A[i].s || A[i].e - A[i].s < 2) continue;

        cnt++;
        e = A[i].e;
    }

    return cnt;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int ans = -1;
	InputData();//입력받는 부분

	//여기서부터 작성
    ans = solve();

	cout << ans << "\n";//출력하는 부분
	return 0;
} 