// 22.03.17. 불량 사용자 (set, dfs)
#include <string>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

vector<string> user;
vector<string> banned;
vector<bool> visit;
set<string> s;

void dfs(int idx) {
    if (idx == banned.size()) {
        string res = "";
        
        for(int i = 0; i < user.size(); i++) {
            if (visit[i]) {
                res += user[i];
            }
        }
        
        s.insert(res);
        return;
    }
    
    for(int i = 0; i < user.size(); i++) {
        bool check = true;
        
        if (visit[i]) continue;
        
        if (user[i].size() != banned[idx].size()) continue;
        
        for(int j = 0; j < user.size(); j++) {
            if (banned[idx][j] == '*') continue;
            
            if (banned[idx][j] != user[i][j]) {
                check = false;
                break;
            }
        }
        
        if (check) {
            visit[i] = true;
            dfs(idx+1);
            visit[i] = false;
        }
    }
}

int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    
    user = user_id;
    banned = banned_id;
    visit = vector<bool> (banned.size(), false);
    
    dfs(0);
    
    return s.size();
}