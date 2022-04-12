// 22.04.08. 퇴사
#include <vector>
#include <iostream>
#include <string>
#include <iostream>
using namespace std;

struct Info {
    int time;
    int cost;
};

int N;
Info info[16];
int answer = 0;

void Input() {
   cin >> N;

    info[0] = {0, 0};
    for(int i = 1; i <= N; i++) {
        int t, p;
        cin >> t >> p;
        info[i] = {t, p};
    }
}

void dfs(int cost, int day) {
    if (day + info[day].time >= N + 1) {
        if (day + info[day].time == N+1) cost += info[day].cost;
        answer = max(answer, cost);
        return;
    }

    for(int i = day + info[day].time; i <= N; i++) {
        dfs(cost + info[day].cost, i);
    }
}

int main() {
    Input();

    for(int i = 1; i <= N; i++)
        dfs(0, i);

    cout << answer << endl;
}