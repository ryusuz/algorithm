#include <iostream>
using namespace std;
#define MAXN ((int)1e3)
int N;

void InputData(){
    cin >> N;
}

int getNums(int n) {
    int ret = 0;

    while (n > 0) {
        ret += ((n % 10) * (n % 10));
        n /= 10;
    }

    return ret;
}

bool roofNum(int n) {
    int used[MAXN + 10] = {0};
    
    while (used[n] == 0) {
        used[n]++;
        n = getNums(n);
        
        if (n == 1) return true;
    }
    
    return false;
}

int solve() {
    for(int i = N; i >= 1; i--) {
        if (roofNum(i)) return i;
    }
    
    return 1;
}

int main112(){
    int ans = -1;
    InputData();//입력받는 부분

    //여기서부터 작성
    ans = solve();

    cout << ans << endl;//출력하는 부분
    return 0;
}