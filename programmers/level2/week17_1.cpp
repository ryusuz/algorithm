// week17-1 괄호 변환
#include <string>
#include <vector>
#include <iostream>

using namespace std;
string answer = "";

bool checkB(string p) {
    int count = 0;

    for (auto& c : p) {
        if (c == '(') count++;
        else count--;
        
        if (count < 0) return false;
    }
    
    return true;
}

string changeB(string p) {
    string answer = "";
    for (auto& c : p) {
        if (c == '(') answer += ')';
        else answer += '(';
    }
    return answer;
}

string balance(string p) {
    // 1. 빈 문자열
    if (p == "") return answer = p + answer ;
    
    // 2. u v로 분리
    string u = "";
    string v = "";
    int open = 0, close = 0;
    for(int i = 0; i < p.size(); i++) {
        if (p[i] == '(') open++;
        else if (p[i] == ')') close++;
        
        u += p[i];
        
        if (open == close) {
            if (i != p.size() - 1) v = p.substr(i+1);
            break;
        }
    }
    
    // 3. 올바른 문자열이라면
    if (checkB(u)) answer = u + balance(v);
    // 4. 올바른 문자열이 아니라면
    else {
        string tmp = "(";
        tmp = tmp + balance(v) + ")";
        u.erase(u.begin());
        u.erase(u.begin() + u.size() - 1);
        
        tmp += changeB(u);
        return tmp;
    }
    
    /*
    cout << answer << " ";
    if (checkB(answer)) cout << "balance" << endl;
    else cout << "unbal" << endl;
    */
    
    return answer;

}

string solution(string p) {
    //string answer = "";
    
    // 1. 빈 문자열
    
    // 2. 분리
    
    //answer = balance(p);
   
    
    
    return balance(p);
}