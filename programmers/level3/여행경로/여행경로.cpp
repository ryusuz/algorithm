// 22/03.08. 여행경로 (DFS)
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <iostream>
using namespace std;

int N;
vector<string> city;
vector<vector<string>> tcks;
vector<bool> visit;

bool dfs(string target, int cnt) {
    if (cnt == N) return true;
    
    for(int i = 0; i < tcks.size(); i++) {
        if (!visit[i] && target == tcks[i][0]) {
            visit[i] = true;
            string next = tcks[i][1];
            city.push_back(next);
            bool ret = dfs(next, cnt + 1);
            
            if(ret) return true;
            
            visit[i] = false;
        }
    }
    
    city.pop_back();
    return false;    
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(), tickets.end());
    
    N = tickets.size();
    tcks = tickets;
    visit = vector<bool>(N, false);
    
    city.push_back("ICN");
    dfs("ICN", 0);
    
    return city;
}