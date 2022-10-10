#include <iostream>
#include <algorithm>
using namespace std;
#define MAXT (int)1e4

int N;
int S[MAXT+10];
int E[MAXT+10];
int present;
int absent;

struct T {
    int s, e;
};

T info[MAXT+10];

void InputData(void){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> S[i] >> E[i];
        info[i] = {S[i], E[i]};
    }
}

bool cmp(T a, T b) {
    if (a.s == b.s) return a.e < b.e;
    return a.s < b.s;
}

void solve() {
    int s, e;

    sort(info, info+N, cmp);

    s = info[0].s;
    e = info[0].e;
    present = e - s;
    absent = 0;

    for(int i = 1; i < N; i++) {
        if (e < info[i].s) {
            present = max(present, e - s);
            absent = max(absent, info[i].s - e);
            s = info[i].s;
            e = info[i].e;
            continue;
        }

        if (e < info[i].e) e = info[i].e;
    }

    present = max(present, e-s);

}

int main1(void){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    solve();

    cout << present << " " << absent << endl;// 출력하는 부분
    return 0;
}