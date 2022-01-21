//week5 짝 지어 제거하기
#include <iostream>
#include<string>
#include <stack>
using namespace std;

int solution(string s)
{
    stack<char> st;    
        
    if (s.size() % 2 == 1) return 0;
    
    for (char c : s) {
        if (st.empty() || c != st.top()) st.push(c);
        else st.pop();
    }
    
    return st.empty()?1:0;
}