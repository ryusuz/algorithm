// 22.01.21. 방금 그 곡
#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <utility>
#include <algorithm>
using namespace std;

int calTime(string start, string end) {
    vector<int> times;  // 시작 시, 시작 분, 끝 시, 끝 분
    string stmp;
    
    istringstream s1(start);
    while(getline(s1, stmp, ':')) {
        times.push_back(stoi(stmp));
    }
    
    istringstream s2(end);
    while(getline(s2, stmp, ':')) {
        times.push_back(stoi(stmp));
    }
    
    int stime, etime;
    stime = times[0] * 60 + times[1];
    etime = times[2] * 60 + times[3];
    
    return etime - stime;
}

string replaceHash(string str) {
    string hashes[5] = {"C#", "D#", "F#", "G#", "A#"};
    string change[5] = {"c", "d", "f", "g", "a"};
    
    for(int i = 0; i < 5; i++) {
        if (str.find(hashes[i]) == string::npos) continue;
        
        while (str.find(hashes[i]) != string::npos)
            str.replace(str.find(hashes[i]), hashes[i].size(), change[i]);
    }
    
    return str;
}

bool cmp(pair<int, string> a, pair<int, string> b) {
    return a.first > b.first;
}

string solution(string m, vector<string> musicinfos) {   
    //map<string, int> info;
    vector<pair<int, string>> info;
    
    for(auto& music : musicinfos) {
        istringstream iss(music);
        string stmp;
        vector<string> vtmp;
        
        while (getline(iss, stmp, ',')) {
            vtmp.push_back(stmp);
        }
        
        int time = calTime(vtmp[0], vtmp[1]);
        string title = vtmp[2];
        string melody = replaceHash(vtmp[3]);
        string newMelody;

        int q = time / melody.size();
        int r = time % melody.size();
        
        for(int i = 0; i < q; i++) {
            newMelody += melody;
        }
        
        for(int i = 0; i < r; i++) {
            newMelody += melody[i];
        }
        
        if(newMelody.find(replaceHash(m)) != string::npos) {
            info.push_back(make_pair(time, title));
        }
    }
    
    stable_sort(info.begin(), info.end(), cmp);

    return info.empty() ? "(None)" : info[0].second;
}