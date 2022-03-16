#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

int getTime(string tm) {
    string hr = tm.substr(0, 2);
    string mn = tm.substr(3, 2);
        
    return stoi(hr) * 60 + stoi(mn);
}

string getStringTime(int tm) {
    string hr = to_string(tm / 60);
    string mn = to_string(tm % 60);
    
    if (hr.size() == 1) hr = "0" + hr;
    if (mn.size() == 1) mn = "0" + mn;
    
    return hr + ":" + mn;
}

// 9시부터 n회, 배차간격 T, 셔틀인원 m
string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    
    sort(timetable.begin(), timetable.end());
    
    vector<int> bus_time;
    int start = getTime("09:00");
    bus_time.push_back(start);
    for(int i = 1; i < n; i ++) bus_time.push_back(start + t * i);
    
    int idx = 0;
    int person = 0, bus = 0;
    
    for(int i = 0; i < timetable.size(); i++) {
        int curr = getTime(timetable[i]);
        
        cout << curr << " " << bus_time[idx] << endl;
        if (curr <= bus_time[idx] && person < m) {
            person++;
        }
        
        if (person == m || curr > bus_time[idx]) {
            bus++;
            idx++;
            i--;
            
            cout << "leave bus " << bus << " :: person == " << person << endl;
            person = 0;
            
        }
        
        if (bus == n) {
            cout << "no bus" << endl;
            
            if (curr > bus_time[i]) return getStringTime(bus_time[idx-1]);

            return getStringTime(curr - 1);
        }
        
        
    }
    
    if (bus == 0) {
            return "09:00";
    }
    
    return answer;
}

/*
1. 버스는 무조건 9시에 온다.
2. 버스 시간표 만들기
3. 제일 늦은 도착시간이니까 마지막 버스를 타야함.
4. 애들이 9시보다 먼저 오면 사람수랑 버스수 생각해야함
5. 애들이 9시보다 늦게 와도...
*/