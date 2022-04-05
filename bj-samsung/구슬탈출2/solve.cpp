// 22.04.04. 구슬 탈출2
#include <string>
#include <vector>
#include <utility>
#include <queue>
#include <iostream>
using namespace std;

int N, M;
vector<string> board;
int answer;

void init() {
    N = 0, M = 0, answer = -1;
    board.clear();
}

void Input() {
    scanf("%d %d", &N, &M);
    
    for(int i = 0; i < N; i++) {
        string tmp;
        cin >> tmp;
        board.push_back(tmp);
    }
}

void solution() {
    pair<int, int> red, blue, holl;
    
    for(int i = 0; i < N; i++) {
       for(int j = 0; j < M; j++) {
           if (board[i][j] == 'R') red = make_pair(i, j);
           else if (board[i][j] == 'B') blue = make_pair(i, j);
           else if (board[i][j] == 'O') holl = make_pair(i, j);
        }
    }

    // bfs
    int dp[10][10] = {0};
    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};

    queue<int> q;
    queue<pair<int, int>> rq;
    queue<pair<int, int>> bq;

    q.push(0);
    rq.push(red);
    bq.push(blue);

    bool red_holl = false;
    bool blue_holl = false;

    while (!rq.empty()) {
        int cnt = q.front();

        int ry = rq.front().first;
        int rx = rq.front().second;

        int by = bq.front().first;
        int bx = bq.front().second;

        q.pop();
        rq.pop();
        bq.pop();

        if (cnt >= 10) {
            answer = -1;
            break;
        }

        for (int i = 0; i < 4; i++) {
            int rny = ry + dy[i];
            int rnx = rx + dx[i];

            int bny = by + dy[i];
            int bnx = bx + dx[i];

            // 해당 방향의 벽끝까지 공 굴리기
            while (board[rny][rnx] != '#') {
                if (board[rny][rnx] == 'O') {
                    red_holl = true;
                    break;
                }

                rny += dy[i];
                rnx += dx[i];
            }

            while (board[bny][bnx] != '#') {
                if (board[bny][bnx] == 'O') {
                    blue_holl = true;
                    break;
                }

                bny += dy[i];
                bnx += dx[i];
            }

            if (red_holl && !blue_holl) {
                answer = cnt + 1;
                break;
            }

            if (blue_holl) {
                red_holl = false;
                blue_holl = false;
                continue;
            }

            rny -= dy[i];
            rnx -= dx[i];

            bny -= dy[i];
            bnx -= dx[i];

            // 둘이 겹치면 둘 중 하나를 이동해줘여함
            if (rny == bny && rnx == bnx) {     
                // 벽에 더 멀었던 공을 진행방향 쪽으로 빼줌
                // 겹친다는건 같은 진행방향에 있었다는 뜻. 그럼 y나 x값이 같을거임 y+x의 값이 더 큰애가 멀리 있는거.

                int rdiff = abs(rny - ry) + abs(rnx - rx);
                int bdiff = abs(bny - by) + abs(bnx - bx);

                if (rdiff > bdiff) {
                    rny -= dy[i];
                    rnx -= dx[i];
                } else if (rdiff < bdiff){
                    bny -= dy[i];
                    bnx -= dx[i];
                }
            }
            
            // 최종 공의 상태
            q.push(cnt+1);
            rq.push({rny, rnx});
            bq.push({bny, bnx});
        }

        if (red_holl) break;
    }
}

int main() {
    init();
    Input();

    solution();

    printf("%d \n", answer);
    
    return 0;  
}