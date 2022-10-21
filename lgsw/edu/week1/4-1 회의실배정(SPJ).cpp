#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int ID[500+10];
int S[500+10];
int E[500+10];
int sol[500+10];

struct Info {
    int id, s, e;
};

Info mt[500+10];
vector<vector<int>> arr;

void InputData(){
    cin >> N;
    for (int i=0; i<N; i++){
        cin >> ID[i] >> S[i] >> E[i];

        mt[i] = {ID[i], S[i], E[i]};
    }
}

void OutputData(int ans){
    cout << ans << endl;
    for (int i=0; i<ans; i++){
        cout << sol[i] << " ";
    }
    cout << endl;
}

bool cmp(Info a, Info b) {
    if (a.e == b.e) return a.s < b.s;
    return a.e < b.e;
}

int solve() {
    int cnt;
    int maxc = 0;
    int idx = 0;
    
    sort(mt, mt + N, cmp);

    for(int i = 0; i < N; i++) {
        cnt = 1;
        Info curr = mt[i];

        vector<int> v;
        v.push_back(curr.id);

        for(int j = i+1; j < N; j++) {
            Info next = mt[j];

            if (curr.e > next.s) continue;
            
            v.push_back(next.id);
            curr = next;
            cnt++;
        }

        if (cnt > maxc) {
            maxc = cnt;
            idx = i;
        }

        arr.push_back(v);       
    }

    for(int i = 0; i < maxc; i++) {
        sol[i] = arr[idx][i];
    }

    return maxc;
}

int main1(){
    int ans = -1;

    InputData();// 입력받는 부분

    //여기서부터 작성
    ans = solve();

    OutputData(ans);// 출력하는 부분
    return 0;
}