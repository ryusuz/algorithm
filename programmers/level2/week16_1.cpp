// week16-1 행렬 테두리 회전하기
#include <string>
#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

vector<vector<int>> map;

int dx[2] = {1, 0};
int dy[2] = {0, 1};
int R, C;

vector<int> solution(int rows, int columns, vector<vector<int>> queries) {
    vector<int> answer;
    C = rows;
    R = columns;
    int startX, startY, endX, endY;
    
    int num = 1;
    for (int i = 0; i < C; i++) {
        vector<int> tmp;
        for (int j = 0; j < R; j++) {
            tmp.push_back(num++);
        }
        map.push_back(tmp);
    }
    
    for (auto& q : queries) {
        int min = C*R;
        
        startY = q[0] - 1;
        startX = q[1] - 1;
        endY = q[2] - 1;
        endX = q[3] - 1;
        
        queue<int> nums;
        nums.push(min);
        int curY = startY;
        int curX = startX;
        
        // 오른쪽
        while(curX < endX) {
            nums.push(map[startY][curX]);
            map[startY][curX] = nums.front();
            
            if (map[startY][curX] < min) min = map[startY][curX];

            nums.pop();
            curX++;
        }
        
        // 아래
        while(curY < endY) {
            nums.push(map[curY][endX]);
            map[curY][endX] = nums.front();
            if (map[curY][endX] < min) min = map[curY][endX];
            
            nums.pop();
            curY++;
        }
        
        // 왼쪽
        while(curX > startX) {
            nums.push(map[endY][curX]);
            map[endY][curX] = nums.front();
            
            if (map[endY][curX] < min) min = map[endY][curX];

            nums.pop();
            curX--;
        }
        
        // 위
        while(curY >= startY) {
            nums.push(map[curY][startX]);
            map[curY][startX] = nums.front();

            if (map[curY][startX] < min) min = map[curY][startX];

            nums.pop();
            curY--;
        }
        
        answer.push_back(min);
        
        
    }
 
    return answer;
}