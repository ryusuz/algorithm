// 22.04.21. 톱니바퀴
#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int answer;
int K;
string tire[4];
vector<vector<int>> info;
bool connect[3];

void Input() {
    for(int i = 0; i < 4; i++) cin >> tire[i];
    
    cin >> K;
    info = vector<vector<int>> (K, vector<int> (2, 0));

    for(int i = 0; i < K; i++) cin >> info[i][0] >> info[i][1];
}

void checkTire() {
    connect[0] = (tire[0][2] != tire[1][6]) ? true : false;
    connect[1] = (tire[1][2] != tire[2][6]) ? true : false;
    connect[2] = (tire[2][2] != tire[3][6]) ? true : false;
}

void rotate(int idx, int d, bool visit[]) {
    string t = tire[idx];

    if (d == 1) {
        tire[idx][0] = t[7];

        for(int i = 1; i < 8; i++) tire[idx][i] = t[i-1];
    } else {
        tire[idx][7] = t[0];

        for(int i = 0; i < 7; i++) tire[idx][i] = t[i+1];
    }

    visit[idx] = true;

    int prev = (idx - 1 < 0) ? -1 : idx - 1;
    int next = (idx + 1 > 3) ? -1 : idx + 1;

    
    if (!visit[prev] && prev > -1 && connect[prev]) rotate(prev, -d, visit);
    
    if (!visit[next] && next > -1 && connect[next - 1]) rotate(next, -d, visit);
}


int main() {
    Input();

    for(int i = 0; i < K; i++) {
        int target = info[i][0] - 1;
        checkTire();            // 각 지점 맞닿아 있는지 확인

        bool visit[4] = {false};
        rotate(target, info[i][1], visit);
    }

    for(int i = 0; i < 4; i++) answer += (tire[i][0] == '0') ? 0 : pow(2, i);
    
    printf("%d \n", answer);

    return 0;
}