// 21.01.16.
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <algorithm>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> id_list, vector<string> report, int k) {
    vector<int> answer;
    
    map<string, int> m;
    for (auto& id : id_list) {
        m[id] = 0;
    }
    
    map<string, vector<string>> repo;
    for (auto& s : report) {
        istringstream iss(s);
        string user1, user2;
        iss >> user1 >> user2;
        
        // user1이 신고한 사람 목록에 없으면 m[user2]++
        if (repo[user1].end() == find(repo[user1].begin(), repo[user1].end(), user2)) {
            m[user2]++;
            repo[user1].push_back(user2);
        }
        
    }
    
    //m == 신고 당한 횟수 , repo[신고자] = {신고한 유저1, 2, 3, ..}
    for(auto& id : id_list) {
        int ans = 0;
        for(auto& user : repo[id]) {
            if (m[user] >= k) ans++;
        }
        answer.push_back(ans);
    }
    return answer;
}