// 22.03.27. 광고삽입 (투포인터 + 부분합)
#include <string>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;

int arr[360000];

int string_to_sec(string time){
    
    int sec = 0;
    string sub = "";
    
    for(int i=0;i<time.size();i++){
        
        if(time[i] == ':'){
            sec = (sec * 60) + (stoi(sub) * 60);
            sub = "";
            continue;
        }
        sub.push_back(time[i]);
    }
    sec += stoi(sub);
    return sec;
}

string sec_to_string(int sec){
    
     
    string s = to_string(sec % 60);
    if(s.size() == 1)
        s = "0" + s;
    sec /= 60;
    
    string m = to_string(sec % 60);
    if(m.size() == 1)
        m = "0" + m;
    sec /= 60;
    
    string h = to_string(sec);
    if(h.size() == 1)
        h = "0" + h;
    
    return h + ":" + m + ":" + s; 
}

int accumulate(int a_time, int p_time){
    
    long long maxsum = 0;
    int result = 0;
    
    for(int i=0;i<a_time;i++)
        maxsum += arr[i];
    
    long long sum = maxsum;
    
    for(int i = a_time; i < p_time; i++){
        
        sum += arr[i] - arr[i - a_time];
        
        if(maxsum < sum) {
            maxsum = sum;
            result = i - a_time + 1;
        }
    }
    return result;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    
    string answer = "";
    
    int p_time = string_to_sec(play_time);
    int a_time = string_to_sec(adv_time);
    
    for(int i=0;i<logs.size();i++){
        
        int start = string_to_sec(logs[i].substr(0, 8));
        int end = string_to_sec(logs[i].substr(9, 8));
        
        for(int i = start;i<end;i++) 
            arr[i]++;
    }
        
    int result = accumulate(a_time, p_time);
    
    answer = sec_to_string(result);
    
    return answer;
}




//
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

struct Log {
    int start;
    int end;
    int time; 
};

bool cmp(Log a, Log b) {
    if (a.start == b.start) return a.end < b.end;
    return a.start < b.start;
}

int getTime(string str) {
    int h = stoi(str.substr(0, 2)) * 3600;
    int m = stoi(str.substr(3, 2)) * 60;
    int s = stoi(str.substr(6, 2));
    
    return h + m + s;
}

string getTime(int t) {
    string h = to_string(t / 3600);
    string m = to_string(t % 3600 / 60);
    string s = to_string(t % 3600 % 60);
    
    if (h.size() == 1) h = "0" + h;
    if (m.size() == 1) m = "0" + m;
    if (s.size() == 1) s = "0" + s;
    
    return h + ":" + m + ":" + s; 
}

Log getLog(string str) {
    int s = getTime(str.substr(0, 8));
    int e = getTime(str.substr(9, 8));
    int t = e - s;
    
    Log log = {s, e, t};
    return log;
}

string solution(string play_time, string adv_time, vector<string> logs) {
    string answer = "";
    vector<Log> info;
    int time = 0;
    
    int play = getTime(play_time);
    int adv = getTime(adv_time);
    
    if (play <= adv) return "00:00:00";
    
    for(auto l : logs) {
        Log log = getLog(l);
        info.push_back(log);
    }
    
    sort(info.begin(), info.end(), cmp);
        
    for(int i = 0; i < info.size(); i++) {        
        int start = info[i].start;
        int end = start + adv;
        int cnt = 1;
        
        for(int j = 0; j < info.size(); j++) {
            if (i == j || start > info[j].end) continue;
            if (end < info[j].start || start > info[i].end) break;
            
            cnt++;
        }

        if (time < cnt) {
            time = cnt;
            answer = getTime(start);
        }
        
        cnt = 0;
    }
    
    return answer;
}