// 22.03.16. 셔틀버스
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    int result = 0;

    sort(timetable.begin(), timetable.end());
    vector<int> timeTable;
    for (auto& time : timetable)
        timeTable.push_back(stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2)));

    int index = 0;
    int busTime = 540; // 09:00
    
    for (int count = 1; count <= n; ++count) {
        int numOfGetOn = 0;
        
        while (numOfGetOn < m && index < timeTable.size()) {
            if (timeTable[index] <= busTime) {
                numOfGetOn++;
                index++;
            }
            else break;
        }
        
        if (count == n) {
            if (numOfGetOn < m)
                result = busTime;
            else
                result = timeTable[index - 1] - 1;
        }
        busTime += t;
    }
  
    int hours = result / 60;
    if (hours <= 9)
        answer = "0" + to_string(hours) + ":";
    else
        answer = to_string(hours) + ":";

    int minutes = result % 60;
    if (minutes <= 9)
        answer += "0" + to_string(minutes);
    else
        answer += to_string(minutes);

    return answer;
}


/////2. 나의 틀린 풀ㅇ ㅣ시발
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
    
    int last = bus_time[bus_time.size()-1];
    
    int idx = 0;
    int person = 0, bus = 0;
    int tmp = 0;
    
    for(int i = 0; i < timetable.size(); i++) {
        int curr = getTime(timetable[i]);
        
        if (curr <= bus_time[idx] && person < m) person++;
        
        if (person == m || curr > bus_time[idx]) {
            bus++;
            idx++;
            i--;
            tmp = person;
            person = 0;
        }
        
        if (bus == n) {
            if (curr > last || tmp < m)
                return getStringTime(last);
            
            return getStringTime(curr - 1);
        }   
    }
    
    return getStringTime(last);
}