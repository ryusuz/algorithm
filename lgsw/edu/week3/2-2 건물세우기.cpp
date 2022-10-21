#include <iostream>
#include <utility>
using namespace std;

#define MAXN (10)
#define INF (1<<30)

int N;
int cost[MAXN+10][MAXN+10];
int solpath[MAXN+10];//답 경로

int sol;
int path[MAXN + 10];
bool visited[MAXN + 10];

void init() {
    for(int i = 0; i < N; i++) {
        path[i] = 0;
        visited[i] = false;
    }
}

void dfs(int curr, int cnt, int sum) {
    if (sum >= sol) return;

    if (cnt >= N) {
        sol = sum;

        for(int i = 0; i < N; i++) {
            solpath[i] = path[i];
        }

        return;
    }

    for(int i = 0; i < N; i++) {
        if (visited[i]) continue;

        path[curr] = i+1;

        visited[i] = true;
        dfs(curr + 1, cnt + 1, sum + cost[curr][i]);
        visited[i] = false;
    }
}

int solve() {
    sol = INF;

    init();
    dfs(0, 0, 0);

    return sol;
}

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cin >> cost[i][j];
        }
    }
}

void OutputData(int sol){
    cout << sol << endl;
    for (int i=0; i<N; i++){
        cout << solpath[i] << " ";
    }
    cout << endl;
}

int main(){
    int ans = -1;

    InputData();//입력받는 부분

    //여기서부터 작성
    ans = solve();

    OutputData(ans);//출력하는 부분
    return 0;
}