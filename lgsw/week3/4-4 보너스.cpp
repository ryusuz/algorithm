#include <iostream>
#include <algorithm>
using namespace std;

int N, M;
int s[100+10];
int e[100+10];
int in[10+10];

int graph[10+10][10+10];

void InputData(){
    cin >> N >> M;
    for (int i=0; i<M; i++){
        cin >> s[i] >> e[i];
    }
    for (int i=1; i<=N; i++){
        cin >> in[i];
    }
}

void OutputData(){
    for (int i=1; i<=N; i++){
        cout << in[i] << " ";
    }
    cout << endl;
}

void init() {
    for(int i = 0; i < M; i++) {
        graph[s[i]][e[i]] = 1;
    }
}

bool check() {
    for(int i = 1; i <= N; i++) {
        for(int j = 1; j <= N; j++) {
            if (!graph[i][j]) continue;

            if (in[i] <= in[j]) return false;
        }
    }

    return true;
}

void solve() {
    init();

    sort(in, in + N+1);

    do {
        if (check()) break;
    } while (next_permutation(in, in + N+1));

    
}

int main(){
    InputData();//입력받는 부분

    // 여기서부터 작성
    solve();

    OutputData();// 출력하는 부분
    return 0;
}