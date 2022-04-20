// 22.04.20. 경사로
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int N, L;
vector<vector<int>> board;
int answer = 0;

void Input() {
    cin >> N >> L;

    board = vector<vector<int>>(N, vector<int> (N, 0));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }
}

bool check(int a, int n) {
    if (a < 0 || a >= n) return false;
    return true;
}

int solution(vector<int> &v) {
    v.push_back(-1);
    vector<pair<int, int>> v2;

    int cnt = 0;
    for(int i = 1; i < v.size(); i++) {
        if (v[i-1] != v[i]) {
            v2.push_back({v[i-1], cnt+1});
            cnt = 0;
        } else cnt++;
    }

    int vsize = v2.size();

    if (vsize == 1) return 1;

    for(int i = 0; i < v2.size(); i++) {
        // 왼
        if (check(i-1, vsize) && v2[i-1].first > v2[i].first) {
            if (v2[i].second < L) return 0;
            else v2[i].second -= L;
        }

        // 오
        if (check(i+1, vsize) && v2[i].first < v2[i+1].first) {
            if (v2[i].second < L) return 0;
            else v2[i].second -= L;
        }
    }

    return 1;
}

int main() {
    Input();

    // row
    for(int i = 0; i < N; i++) {
        vector<int> v;
        bool possible = true;

        for(int j = 1; j < N; j++) {
            if (abs(board[i][j-1] - board[i][j]) > 1) {
                possible = false;
                break;
            }
        }

        if (possible) answer += solution(board[i]);
    }

    // col
    for(int i = 0; i < N; i++) {
        vector<int> v;
        v.push_back(board[0][i]);
        bool possible = true;

        for(int j = 1; j < N; j++) {
            if (abs(board[j-1][i] - board[j][i]) > 1) {
                v.clear();
                possible = false;
                break;
            } else v.push_back(board[j][i]);
        }
        
        if (possible) answer += solution(v);
    }

    printf("%d \n" , answer);

    return 0;
}
