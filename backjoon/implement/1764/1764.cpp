// 22.05.16. 듣보잡
#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

int N, M;
int answer;
map<string, int> m;
vector<string> names;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    string name;

    for(int i = 0; i < N; i++) {
        cin >> name;
        m[name]++;
    }

    for(int i = 0; i < M; i++) {
        cin >> name;
        m[name] ++;
    }

    for(auto s : m) {
        if (s.second > 1) {
            answer++;
            names.push_back(s.first);
        }
    }

    cout << answer << endl;
    for(int i = 0; i < names.size(); i++) {
        cout << names[i] << endl;
    }

    return 0;
}