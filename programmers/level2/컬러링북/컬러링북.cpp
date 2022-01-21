// week15-2 카카오프렌즈 컬러링북

#include <vector>
#include <queue>
#include <utility>
#include <iostream>
using namespace std;

vector<vector<bool>> isVisit;
vector<vector<int>> cpPicture;
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int c, r;

int bfs(int i, int j) {
    int count = 1;
    queue<pair<int, int>> q;
    q.push(make_pair(i, j));
    isVisit[i][j] = true;
    
    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        int cur = cpPicture[curY][curX];
        q.pop();
        
        for (int i = 0; i < 4; i++) {
            int nextY = curY + dy[i];
            int nextX = curX + dx[i];

            if (nextY < 0 || nextY >= c || nextX < 0 || nextX >= r) continue;

            int next = cpPicture[nextY][nextX];
            if (!isVisit[nextY][nextX] && cur == next) {
                q.push(make_pair(nextY, nextX));
                isVisit[nextY][nextX] = true;
                count++;
            }
        }
    }
    //cout << "count = " << count << endl;
    return count;
}

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    
    // isVisit 초기화
    for (int i = 0; i < picture.size(); i++) {
        vector<bool> tmp1;
        for (int j = 0; j < picture[0].size(); j++) {
            tmp1.push_back(false);
        }
        isVisit.push_back(tmp1);
    }
    
    // bfs
    for (int i = 0; i < picture.size(); i++) {
        for (int j = 0; j < picture[0].size(); j++) {
            if (!isVisit[i][j] && picture[i][j] != 0) {
                cout << "[" << i << "][" << j << "] ::: " << picture[i][j]; 
                max_size_of_one_area = max(max_size_of_one_area, bfs(i, j));
                number_of_area++;
            }
        }
    }
    
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    
    return answer;
}

