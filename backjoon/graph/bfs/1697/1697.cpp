// 22.05.16. 숨바꼭질
#include <iostream>
#include <queue>
#include <utility>
using namespace std;

int N, M;
int answer;
bool visited[1000001] = {false};

void Input() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> N >> M;

    answer = 0;
}

int main() {
    Input();

    queue<pair<int, int>> q;
    q.push({N, 0});

    while (q.front().first != M) {
        int curr = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (curr - 1 > -1 && !visited[curr - 1]) {
            q.push({curr - 1, cnt + 1});
            visited[curr - 1] =  true;
        }

        if (curr + 1 < 100001 && !visited[curr + 1]) {
            q.push({curr + 1, cnt + 1});
            visited[curr + 1] = true;
        }

        if (curr * 2 < 100001 && !visited[curr * 2]) {
            q.push({curr * 2, cnt + 1});
            visited[curr * 2] = true;
        }
    }

    cout << q.front().second << endl;
    
    return 0;
}