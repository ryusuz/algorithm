#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;
// 0우 1좌 2하 3상
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct point {
    int x, y;
};

int bfs(vector<string> room, int px, int py) {
    queue<point> q;
    bool isVisit[5][5] = {false};
    
    q.push({px, py});
    isVisit[px][py] = true;
    
    //cout << "point : [" << px << ", " << py << "]" << endl;
    
    while (!q.empty()) {
        int x = q.front().x;
        int y = q.front().y;
        q.pop();

        // 상하좌우 확인
        for (int i = 0; i < 4; i++) {
            int nextX = x + dx[i];
            int nextY = y + dy[i];
            if (nextX < 0 || nextX > 4 || nextY < 0 || nextY > 4) continue;
            
            int dist = abs(px-nextX) + abs(py-nextY);
            if (dist > 2) break;
            
            char next = room[nextX][nextY];
            //cout << i << " cur = " << x << y << "::: next = " << nextX << nextY << ":::" << next << endl;

            if (!isVisit[nextX][nextY] && next != 'X') {

                if (next == 'O') {
                    q.push({nextX, nextY});
                    isVisit[nextX][nextY] = true;
                } else if (next == 'P') return -1;
            }
        }
    }
    
    return 0;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    
    int idx = 0;
    for (auto& room : places)  {
        //cout << "room " << ++idx << endl;
        int result = 0;
        
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (room[i][j] == 'P') {
                    result = bfs(room, i, j);
                    if (result == -1) {
                        i = 5;
                        break;
                    }
                }
            }
                        
        }
        //cout << endl;

        if (result == -1) answer.push_back(0);
        else answer.push_back(1);
    }
    return answer;
}