#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <iostream>
using namespace std;
typedef pair<int, int> pr;

bool cmp(pr a, pr b) {
    if (a.first > b.first) return a > b;
    else if (a.first == b.first) return a.second < b.second;
}

bool cmp2(pair<int, string> a, pair<int, string> b) {
    if (a.first > b.first) return a > b;
    else if (a.first == b.first) return a < b;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, vector<pr>> m;
    vector<pair<int, string>> sums;
    
    for(int i = 0; i < plays.size(); i++) {
        m[genres[i]].push_back({plays[i], i});
    }
    
    for(auto& it : m) {
        sort(it.second.begin(), it.second.end(), cmp);
        int sum = 0;
        for(auto& i : it.second) {
            sum += i.first;
        }
        sums.push_back({sum, it.first});
        
    }
    
    sort(sums.begin(), sums.end(), cmp2);
        
    for(auto& s : sums) {
        string genre = s.second;
        
        for(int i = 0; i < 2; i++) {
            answer.push_back(m[genre][i].second);
            if (m[genre].size() == 1) break;
        }
    }
    
    return answer;
}