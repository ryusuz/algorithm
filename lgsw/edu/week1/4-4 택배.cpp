#include <iostream>
#include <algorithm>
using namespace std;

int N, C, M;
int S[10000+10];
int E[10000+10];
int NUM[10000+10];

struct T {
    int s, e, w;
};

T info[10000+10];
bool visited[10000+10] = {false};
int wsum[10000+10] = {0};

void InputData(){
    cin >> N >> C;
    cin >> M;
    for (int i=0; i<M; i++){
        cin >> S[i] >> E[i] >> NUM[i];
        info[i] = {S[i], E[i], NUM[i]};
    }
}

bool cmp(T a, T b) {
    if (a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}

int solve() {
    int cnt = 0;

    sort(info, info + M, cmp);

    for(int i = 0; i < M; i++) {
        int maxc = 0;
        T curr = info[i];

        for(int j = curr.s; j < curr.e; j++) {
            maxc = max(maxc, wsum[j]);
        }

        int w = min(curr.w, C - maxc);
        cnt += w;

        for(int j = curr.s; j < curr.e; j++) {
            wsum[j] += w;
        }
    }

    return cnt;
}

int main(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}