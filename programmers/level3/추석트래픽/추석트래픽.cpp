// 22.03.01. 추석트래픽
#include <string>
#include <vector>
#include <utility>
#include <algorithm>
#include <iostream>
using namespace std;

int solution(vector<string> lines) {
    int answer = 0;

    vector<pair<int, int>> times;
    
    for(auto& line : lines) {
        int h = stoi(line.substr(11, 2)) * 3600 * 1000;
        int m = stoi(line.substr(14, 2)) * 60 * 1000;
        int s = stoi(line.substr(17, 2)) * 1000 + stoi(line.substr(20, 3));
        
        int end = h + m + s;
        int start = end - stof(line.substr(24)) * 1000 + 1;
        
        times.push_back({start, end});
    }
        
    for(int i = 0; i < times.size(); i++) {
        int tm = times[i].second + 1000;
        int cnt = 0;
        
        for(int j = i; j < times.size(); j++) {
            if(times[j].first < tm) cnt++;
        }
        
        if (cnt > answer) answer = cnt;
    }
    
    return answer;
}