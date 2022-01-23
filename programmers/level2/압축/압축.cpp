// 21.01.23. 압축
#include <string>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

vector<int> solution(string msg)  {
    vector<int> answer;
    string alphas[26] = {"A", "B", "C", "D", "E", "F", "G", "H", "I", "J", "K", "L", "M",
                         "N", "O", "P", "Q", "R", "S", "T", "U", "V", "W", "X", "Y", "Z"};
    
    // 사전 생성
    map<string, int> m;
    for(int i = 0; i < 26; i++) {
        m[alphas[i]] = i+1;
    }
    
    int num = 27;
    
    /*
        1. w 확인
        2. w 사전에서 검사
        2-1. w가 사전에 있고 wc가 사전에 없다
            => w 출력, wc 사전 추가
        2-2. w가 사전에 있고 wc가 사전에 있다
            => wc(=w) + 다음 c 검사 => 2로
    */
    
    string w, c;
    for(int i = 0; i < msg.size(); i++) {
        w.append(1, msg[i]);
        c.append(1, msg[i+1]);
                
        if (m.find(w+c) == m.end()) {
            m[w+c] = num++;
            answer.push_back(m[w]);
            w.clear();
        }
        
        c.clear();
    }
 
    return answer;
}