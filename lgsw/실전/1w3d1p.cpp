#include <iostream>
using namespace std;

char str[100000+10];

void InputData(){
    cin >> str;
}

int solve() {
    int cnt = 0;
    int flag = 0;

    int idx = 0;
    while (str[idx] == '(' || str[idx] == ')') {
        char c = str[idx++];

        if (c == '(') flag++;
        else flag--;

        if (flag < 0) {
            cnt++;
            flag = 1;
        }
    }

    if (flag > 0) cnt += (flag / 2);

    return cnt;
}

int main131(){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    ans = solve();

    cout << ans << endl;// 출력하는 부분
    return 0;
}