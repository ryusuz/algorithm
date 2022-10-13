#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int S, E;//출발 정류장 번호, 도착 정류장 번호
void InputData(){
    cin >> S >> E;
}

bool isPrime(int n) {
    for(int i = 2; i * i <= n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

int getNum(int num, int i, int j) {
    int rest, ret;

    if (i == 0) {
        if (j== 0) return -1;

        rest = num % 1000;
        ret = (1000 * j) + rest;
    }

    else if (i == 1) {
        rest = (num / 1000) * 1000 + (num % 100);
        ret = (100 * j) + rest;
    }

    else if (i == 2) {
        rest = (num / 100) * 100 + (num % 10);
        ret = (10 * j) + rest;
    }

    else if (i == 3) {
        rest = (num / 10) * 10;
        ret = rest + j;
    }

    return ret;
}


int solve() {
    queue<pair<int, int>> q;
    bool visit[10010] = {false};

    q.push({S, 0});
    visit[S] = true;

    int curr, next, cnt;

    while (!q.empty()) {
        curr = q.front().first;
        cnt = q.front().second;
        q.pop();

        if (curr == E) return cnt;

        for(int i = 0; i < 4; i++) {
            for(int j = 0; j <= 9; j++) {
                next = getNum(curr, i, j);

                if (next == -1 || !isPrime(next) || visit[next]) continue;

                q.push({next, cnt + 1});
                visit[next] = true;
            }
        }
        cout << endl;
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