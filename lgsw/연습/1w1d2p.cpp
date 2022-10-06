#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
#define INF (1<<30)

int N;//정수개수
int A[MAXN + 10];//입력 정수
int tmp;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> A[i];
    }
}

int getNum(int n) {
    int sum = 0;
    
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }

    return sum;
}

int roofNum(int n) {
    while (n >= 10) {
        n = getNum(n);
    }

    return n;
}

int solve() {
    int maxd = 0;
    int maxv = INF;

    for(int i = 0; i < N; i++) {
        int tmp = roofNum(A[i]);

        if (maxd < tmp || ((maxd == tmp) && (maxv > A[i]))) {
            maxd = tmp;
            maxv = A[i];
        }
    }

    return maxv;

}

int main12(){
    int ans = -1;
    InputData();//입력 받는 부분

    //여기서부터 작성
    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}