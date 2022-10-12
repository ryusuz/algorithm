#include <iostream>
#include <algorithm>
using namespace std;
#define MAXN ((int)1e5)
#define MAXM ((long long)1 << 30)

int N;//개수
int F[MAXN + 10];


void InputData(){
	cin >> N;
	for (int i=0; i<N; i++){
		cin >> F[i];
	}
}

int bs (int idx) {  // 가장 
    int ret;
    int s = idx, e = N - 1;

    while (s <= e) {
        int mid = (s + e) / 2;

        if (F[idx] * 10 >= F[mid] * 9) {
            // 검사해야함 => upper 찾기
            ret = mid;
            s = mid + 1;
        } else {
            // 줄여줘야함
            e = mid - 1;
        }
    }

    return ret;
    
}

long long solve() {
    long long ret = 0;

    sort(F, F + N);

    for(int i = 0; i < N; i++) {
        ret += (bs(i) - i);
    }

    return ret;
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long ans = -1;

	InputData();// 입력받는 부분

	// 여기서부터 작성
    ans = solve();

	cout << ans << "\n";// 출력하는 부분
	return 0;
}
