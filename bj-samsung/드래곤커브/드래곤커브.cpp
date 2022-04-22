// 22.04.22. 드래곤커브
#include <iostream>
#include <vector>
using namespace std;

struct DC {
    int x, y, d, g;
};

struct Point {
    int y, x;
};

int N;
int board[101][101];
vector<DC> info;

int dy[4] = {0, -1, 0, 1};
int dx[4] = {1, 0, -1 ,0};

int answer = 0;

void Input() {
    cin >> N;

    for(int i = 0; i < N; i++) {
        DC dc;

        cin >> dc.x >> dc.y >> dc.d >> dc.g;

        info.push_back(dc);
    }
}

bool check(int y, int x) {
    if (y < 0 || x < 0 || y > 100 || x > 100) return false;
    return true;
}

Point rotate(Point p) {
    int y = p.x;
    int x = -p.y;

    return {y, x};
}

void curve(int cnt, int gen, vector<Point> &points) {
    if (cnt == gen) return;
    
    Point end = points[points.size() - 1];
    Point endr = rotate(end);

    int ydiff = end.y - endr.y;
    int xdiff = end.x - endr.x;

    // 드래곤 커브 만들기
    for(int i = points.size() - 2; i >= 0; i--) {
        Point pr = rotate(points[i]);
        pr = {pr.y + ydiff, pr.x + xdiff};

        if (!check(pr.y, pr.x)) return;


        points.push_back(pr);
        board[pr.y][pr.x] = 1;
    }

    curve(cnt + 1, gen, points);
}

int checkSquare(int y, int x) {
    if (!check(y, x+1) || board[y][x+1] != 1) return 0;
    if (!check(y+1, x) || board[y+1][x] != 1) return 0;
    if (!check(y+1, x+1) || board[y+1][x+1] != 1) return 0;
    return 1;
}

int main() {
    Input();

    for(int i = 0; i < N; i++) {
        vector<Point> points;
        points.push_back({info[i].y, info[i].x});
        board[info[i].y][info[i].x] = 1;
        
        int ny = info[i].y + dy[info[i].d];
        int nx = info[i].x + dx[info[i].d];

        if (!check(ny, nx)) continue;

        points.push_back({ny, nx});
        board[ny][nx] = 1;
        curve(0, info[i].g, points);
    }

    for(int i = 0; i < 100; i++) {
        for(int j = 0; j < 100; j++) {
            if (board[i][j] == 1) {
                answer += checkSquare(i, j);
            }
        }
    }

    printf("%d \n", answer);

    
    return 0;
}
