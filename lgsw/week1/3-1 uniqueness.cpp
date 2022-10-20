#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int N;
char S[10000+10][20+10];

map<string, vector<int>> m;
map<string, bool> check;

void InputData(){
    cin >> N;
    for (int i=1; i<=N; i++){
        cin >> S[i];
    }
}

void solve() {
    int cnt = 0;

    for(int i = 1; i <= N; i++) {
        m[S[i]].push_back(i);
        check[S[i]] = false;
    }

    for(int i = 1; i <= N; i++) {
        if (check[S[i]]) continue;

        check[S[i]] = true;

        if (m[S[i]].size() == 1) {
            cnt++;
            continue;
        }


        cout << S[i] << " ";
        for(int j = 0; j < m[S[i]].size(); j++) {
            cout << m[S[i]][j] << " ";
        }
        cout << endl;
    }

    // for(auto it : m) {
    //     if (it.second.size() == 1) {
    //         cnt++;
    //         continue;
    //     }

    //     cout << it.first << " ";

    //     for(auto v : it.second) {
    //         cout << v << " ";
    //     }
    //     cout << '\n';
    // }

    if (cnt == m.size()) cout << "unique" << '\n';
}

int main131(){
    InputData();// 입력받는 부분

    // 여기서부터 작성
    solve();

    return 0;
}