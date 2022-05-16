// 22.05.16. 나는야 포켓몬 마스터 이다솜
#include <iostream>
#include <string>
#include <map>
using namespace std;

int N, M;
map<string, int> names;
string nums[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    string tmp;

    for(int i = 1; i <= N; i++) {
        cin >> tmp;

        names[tmp] = i;
        nums[i] = tmp;
    }

    for(int i = 0; i < M; i++) {
        cin >> tmp;

        if (isalpha(tmp[0])) cout << names[tmp] << '\n';
        else cout << nums[stoi(tmp)] << '\n';
    }

    return 0;
}