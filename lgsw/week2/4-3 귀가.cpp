#include <iostream>
#include <queue>
#include <cctype>
using namespace std;

#define INF (1<<30)

int P;
char N1[10000+10];
char N2[10000+10];
int L[10000+10];

char farm;
int sol;

int map[128][128];
int visited[128];
int Z;

void setMap() {
    // INF로 초기화
    for(int i = 0; i < 128; i++) {
        for(int j = 0; j < 128; j++) {
            map[i][j] = INF;
        }
    }

    for(int i = 0; i < 128; i++) {
        visited[i] = INF;
    }

    // 거리 최초 갱신
    for(int i = 0; i < P; i++) {
        int n1 = N1[i] - 0;
        int n2 = N2[i] - 0;
        int dist = L[i];

        map[n1][n2] = (map[n1][n2] > dist) ? dist : map[n1][n2];
        map[n2][n1] = (map[n2][n1] > dist) ? dist : map[n2][n1];
    }
}

void solve() {
    Z = 90;
    sol = INF;

    setMap();

    // 목적지에서 출발
    queue<int> q;
    q.push(Z);
    visited[Z] = 0;

    int curr;

    while (!q.empty()) {
        curr = q.front();
        q.pop();

        for(int next = 65; next < 123; next++) {
            if (map[curr][next] == INF) continue;

            if (visited[next] > visited[curr] + map[curr][next]) {
                visited[next] = visited[curr] + map[curr][next];
                q.push(next);
            } 
        }
    }

    for(int i = 65; i < 90; i++) {
        if (visited[i] == INF) continue;

        if (visited[i] < sol) {
            sol = visited[i];
            farm = i;
        }
    }
    
}

void InputData(){
    cin >> P;
    for (int i=0; i<P; i++){
        cin >> N1[i] >> N2[i] >> L[i];
    }
}

int main(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    solve();

    cout << farm << " " << sol << endl;// 출력하는 부분
    return 0;
}