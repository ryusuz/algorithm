// 뉴스 클러스터링 21.10.07.
#include <string>
#include <vector>
#include <iostream>

#define NUM 65536
using namespace std;


vector<string> parseStr(string str) {
    vector<string> s;
    
    for (int i = 0; i < str.size()-1; i++) {
        if (!isalpha(str[i]) || !isalpha(str[i+1])) continue;
        
        if (isupper(str[i])) str[i] = tolower(str[i]);
        if (isupper(str[i+1])) str[i+1] = tolower(str[i+1]);
        // transform 함수 (algorithm 헤더에 포함) 쓰면 쉽게 대소문자 변경 가능!!!
        // transform(인풋벡터.begin(), 인풋벡터.end(), 아웃풋벡터.begin(), 함수);
        // -==> transform(v.begin(), v.end(), v.begin(), ::tolower);
        // -==> transform(v.begin(), v.end(), v.begin(), ::toupper);
        
        s.push_back(str.substr(i,2));
    }
    
    return s;
}

int solution(string str1, string str2) {    
    vector<string> s1 = parseStr(str1);
    vector<string> s2 = parseStr(str2);
    vector<bool> check(s2.size(), false);
    
    if (s1.empty() && s2.empty()) return 65536;
     
    // 벡터 돌면서 같은 애들 체크
    // 벡터1 사이즈 + 벡터2 사이즈 - 같은거 개수 10 - 2 = 8
    double same = 0;
    for (int i = 0; i < s1.size(); i++) {
        for (int j = 0; j < s2.size(); j++) {
            if (check[j] || s1[i] != s2[j]) continue;
            
            same++;
            check[j] = true;
            break;
        }
    }
    
    double answer = same / (s1.size() + s2.size() - same);

    return answer*NUM;
}