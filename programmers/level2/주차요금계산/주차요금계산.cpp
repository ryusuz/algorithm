// 22.02.19. 주차요금계산

#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <map>
#include <cmath>

using namespace std;

int getTime(string in, string out) {
    string h1 = "", h2 = "", m1 = "", m2 = "";
    
    for(int i = 0; i < 5; i++) {
        if (i < 2) {
            h1 += in[i];
            h2 += out[i];
        } else if (i > 2) {
            m1 += in[i];
            m2 += out[i];
        }
    }
    
    int result = (stoi(h2) * 60 + stoi(m2)) - (stoi(h1) * 60 + stoi(m1));
    return result;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    map<string, vector<string>> m;
    
    for(auto& reco : records) {
        istringstream ss(reco);
        string tmp[3];
        
        ss >> tmp[0] >> tmp[1] >> tmp[2];
        
        m[tmp[1]].push_back(tmp[0]);
    }
    
    for(auto& e : m) {
        if (e.second.size() & 1) e.second.push_back("23:59");
        
        int time = 0;
        for(int i = 0; i < e.second.size(); i += 2) {
            time += getTime(e.second[i], e.second[i+1]);
        }
        
        if (time <= fees[0]) answer.push_back(fees[1]);
        else {
            float overfee = float(time - fees[0]) / fees[2];
            int fee = fees[1] + ceil(overfee) * fees[3];
            answer.push_back(fee);
        }
    }
    
    return answer;
}