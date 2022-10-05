#include <iostream>
#include <stdio.h>
using namespace std;

int N;
double D[10000+10];

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> D[i];
    }
}

double solve() {
    double maxn = D[0];
    
    for(int i = 1; i < N; i++) {
        D[i] = max(D[i], D[i-1] * D[i]);
        maxn = max(maxn, D[i]);
    }

    return maxn;
}

int main21(){
    double ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();


    printf("%.3lf\n", ans);// 출력하는 부분
    return 0;
}