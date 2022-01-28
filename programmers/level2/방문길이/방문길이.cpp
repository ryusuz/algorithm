// 21.01.28. 방문 길이
#include <string>
#include <iostream>
using namespace std;

int solution(string dirs) {
    int answer = 0;
    bool visit[11][11][4] = {false}; // U:0 D:1 L:2 R:3
    
    int y = 5, x = 5;
    int ny, nx, dir, sdir;
    for(auto& d : dirs) {
        ny = y, nx = x;
        
        if (d == 'U') {
            dir = 0;
            sdir = 1;
            ny--;
        } else if (d == 'D') {
            dir = 1;
            sdir = 0;
            ny++;
        } else if (d == 'L') {
            dir = 2;
            sdir = 3;
            nx--;
        } else {
            dir = 3;
            sdir = 2;
            nx++;
        }
        
        if (nx < 0 || ny < 0 || nx > 10 || ny > 10) continue;
        
        if(!visit[y][x][dir] && !visit[ny][nx][sdir]) answer++;
        
        visit[y][x][dir] = true, visit[ny][nx][sdir] = true;
        y = ny, x = nx;
        
    }
    
    
    return answer;
}


//// set을 이용한 풀이
#include <string>
#include <set>
using namespace std;
int toIdx(char ch){
    switch(ch){
        case 'R': return 0;
        case 'L': return 1;
        case 'U': return 2;
        case 'D': return 3;
    }
}

int solution(string dirs) {
    char ch;
    int answer = 0,i, x=0,y=0,ty,tx,dy[]={0,0,1,-1},dx[]={1,-1,0,0},idx,a,b;
    set<pair<int,int>> ans;
    for(i=0;i<dirs.length();i++) {
        ch = dirs[i];
        idx = toIdx(ch);
        tx = x + dx[idx], ty = y + dy[idx];
        if(!(-5 <= ty && ty <= 5 && -5 <= tx && tx <= 5)) continue;
        a = x*10000+y;
        x = tx, y = ty;
        b = x*10000+y;
        if(ans.find({a,b}) == ans.end() && ans.find({b,a}) == ans.end())
            ans.insert({a,b});
    }
    return answer = (int)ans.size();
}