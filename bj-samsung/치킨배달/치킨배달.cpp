#include <iostream>
#include <vector>
#include <utility>
#include <climits>
using namespace std;

int N, M, K;
int board[51][51];
vector<pair<int, int>> stores;
vector<pair<int, int>> houses;
vector<int> storesVisit;
int answer;

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};

void Input() {
    cin >> N >> M;
    K = 0;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> board[i][j];

            if(board[i][j] == 2) stores.push_back({i, j});

            if(board[i][j] == 1) houses.push_back({i, j});
            
        }
    }
    
    K = stores.size();
    storesVisit = vector<int> (K);
    answer = INT_MAX;
}

bool check(int y, int x) {
    if (y < 0 || x < 0 || y >= N || x >= N) return false;
    return true;
}

int getCount() {
    int ret = 0;

    for(int i = 0; i < houses.size(); i++) {
        int dist = INT_MAX;
        pair<int, int> house = houses[i];
        
        for(int j = 0; j < K; j++) {
            if (storesVisit[j]) continue;

            pair<int, int> store = stores[j];

            int ydiff = abs(house.first - store.first);
            int xdiff = abs(house.second - store.second);

            dist = min(dist, ydiff + xdiff);
        }

        ret += dist;
    }

    return ret;
}

void dfs(int cnt, int idx) {
    if (cnt == 0) {
        answer = min(answer, getCount());
        return;
    }

    for(int i = idx; i < K; i++) {
        pair<int, int> tmp = stores[i];

        storesVisit[i] = true;
        dfs(cnt - 1, i + 1);
        storesVisit[i] = false;
    }
}

int main() {
    Input();

    for(int i = 1; i <= M; i++) {
        dfs(K-i, 0);
    }

    cout << answer << '\n';

    return 0;
}