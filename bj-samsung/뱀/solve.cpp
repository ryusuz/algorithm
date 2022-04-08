// 22. 04.08. 뱀
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

struct Info {
    int time;
    char dir;
};

struct Point {
    int y, x;
};

int N, K, L;
vector<Info> infos;
vector<string> board;

void Input() {
    cin >> N >> K;

    N += 2;

    for(int i = 0; i < N; i++) {
        string tmp = "";
        for(int j = 0; j < N; j++) tmp += '.';
        board.push_back(tmp);
    }
    
    // 사과
    for(int i = 0; i < K; i++) {
        int y, x;

        cin >> y >> x;
        board[y][x] = 'A';
    }

    cin >> L;
    for(int i = 0; i < L; i++) {
        int time;
        char dir;

        cin >> time >> dir;
        infos.push_back({time, dir});
    }
}

bool check(int y, int x) {
    if (y <= 0 || x <= 0 || y >= N-1 || x >= N-1) return false;
    return true;
}

int changeDir(int dir, char info) {
    switch (dir) {
        case 0:
            if (info == 'L') return 2;
            return 3;

        case 1:
            if (info == 'L') return 3;
            return 2;

        case 2:
            if (info == 'L') return 1;
            return 0;

        case 3:
            if (info == 'L') return 0;
            return 1;
    }

    return dir;   
}

int main() {
    Input();

    int answer = 0;

    board[1][1] = '#';  // 뱀의 위치
    Point head = {1, 1};
    Point tail = {1, 1};

    queue<Point> q;
    q.push(head);

    int dy[4] = {-1, 1, 0, 0};
    int dx[4] = {0, 0, -1, 1};
    int dir = 3;                // 상하좌우

    int idx = 0;    // 회전방향 인덱스

    while (1) {
        // 시간 증가
        answer++;

        // 한칸 앞으로
        head.y += dy[dir];
        head.x += dx[dir];

        if (!check(head.y, head.x) || board[head.y][head.x] == '#') break;

        q.push(head);

        if (board[head.y][head.x] == '.') {
            board[tail.y][tail.x] = '.';
            q.pop();
            tail.y = q.front().y;
            tail.x = q.front().x;
        }

        board[head.y][head.x] = '#';

        if (answer == infos[idx].time) {
            dir = changeDir(dir, infos[idx].dir);
            idx++;
        }

    }

    cout << answer << endl;
    
    return 0;
}