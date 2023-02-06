#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    bool check[123] = {false};
    
    for(auto c : skip) {
        check[c] = true;
    }
    
    for(auto c : s) {
        int cnt = 0;
        
        while (cnt < index) {
            if (c == 122) c = 96;
            
            if (!check[++c]) cnt++;
        }
        
        answer += c;
    }
    
    return answer;
}