//서울에서 김서방 찾기
#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    for (int i = 0; i < seoul.size(); i++) {
        if (seoul[i] == "Kim") {
            answer += to_string(i) + "에 있다";
            return answer;
        }
    }
}

// 다른 방법
string solution(vector<string> seoul) {
    string answer = "";
    int pos=find(seoul.begin(),seoul.end(),"Kim")-seoul.begin();
    answer="김서방은 "+to_string(pos)+"에 있다";
    return answer;
}
