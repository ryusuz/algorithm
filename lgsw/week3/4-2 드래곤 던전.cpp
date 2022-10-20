#include <iostream>
#include <queue>
#include <utility>
using namespace std;

#define MAX_SIZE (30)

int L, R, C;
char map[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10];

struct pnt {
    int z, y, x;
};

pnt S;
int dy[] = {1, -1 ,0 ,0, 0, 0};
int dx[] = {0, 0, 1, -1, 0, 0};
int dz[] = {0, 0, 0, 0, 1, -1};

bool InputData(){
    cin >> L >> R >> C;

    if ((L == 0) && (R == 0) && (C == 0)) return false;

    for (int l=0; l<L;l++){
        for (int r=0; r<R; r++){
            cin >> map[l][r];

            for(int c = 0; c < C; c++) {
                if (map[l][r][c] == 'S') S = {l, r, c};
            }
        }
    }

    return true;
}

bool check(pnt p) {
    if (p.z < 0 || p.z >= L || p.y < 0 || p.y >= R || p.x < 0 || p.x >= C) return false;
    return true;
}

int bfs(pnt curr) {
    int z = curr.z, y = curr.y, x = curr.x;

    queue<pair<pnt, int>> q;
    q.push({curr, 0});

    bool visited[MAX_SIZE+10][MAX_SIZE+10][MAX_SIZE+10] = {false};
    visited[z][y][x] = true;

    pnt next;
    int nz, ny, nx;
    int cnt;

    while (!q.empty()) {
        curr = q.front().first;
        cnt = q.front().second;
        q.pop();

        z = curr.z; y = curr.y; x = curr.x;

        if (map[z][y][x] == 'E') return cnt;

        for(int i = 0; i < 6; i++) {
            next = {curr.z + dz[i], curr.y + dy[i], curr.x + dx[i]};
            nz = next.z; ny = next.y; nx = next.x;
            
            if (!check(next) || visited[nz][ny][nx] || map[nz][ny][nx] == '#') continue;

            q.push({next, cnt + 1});
            visited[nz][ny][nx] = true;
        }
    }

    return -1;
}

int main(){
    int ans = -1;
    while(InputData()){

        //여기서부터 작성
        ans = bfs(S);

        if (ans == -1) cout << "Trapped!" << endl;
        else cout << "Escaped in " << ans << " minute(s)." << endl;
    }
    return 0;
}