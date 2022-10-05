#include <iostream>
#include <map>
using namespace std;

int N, P;
map<int, int> m;

void InputData(){
    cin >> N >> P;
}

int solve() {
    int n = N;
    int ret = 0;

    while (1) {
        n = (n * N) % P;
        m[n]++;

        if (m[n] == 3) break;
    }
    
    for(auto it : m) {
        if (it.second > 1) ret++;
    }
    
    return ret;
}

int main111(){
    int ans = -1;
    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();
    
    cout << ans << endl;// 출력하는 부분
    return 0;
}