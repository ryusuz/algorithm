#include <string>
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int solution(string s) {
    int answer = 0;
    
    for (int i = 0; i < s.size(); i++) {
        string front = s.substr(i);
        string back = s.substr(0, i);
        string rts = front + back;
        
        bool flag = false;
        stack<char> st;

        for (auto& c : rts) {
            if (c == '(' || c == '[' || c == '{') st.push(c);
            else {
                if (st.empty()) continue;
                
                char top = st.top();
                st.pop();
                
                if (top == '(') {
                    flag = c == ')' ? true : false;
                } else if (top == '[') {
                    flag = c == ']' ? true : false;
                } else {
                    flag = c == '}' ? true : false;
                }
                
                if (!flag) break;
            }  
        }
        
        if (flag && st.empty()) answer++;
    
    }
    
    
    return answer;
}