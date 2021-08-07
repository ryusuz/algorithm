// week1-3 신규 아이디 추천
#include <string>
#include <vector>
#include <cctype>
#include <iostream>

using namespace std;

string solution(string new_id) {
    string answer = "";
    
    // 1단계 : 대문자 -> 소문자
    for (char& c : new_id) {
        c = tolower(c);
    }
        
    // 2단계 : 소문자, 숫자, 빼기, 언더바, 마침표를 제외한 모든 문자 제거
    for (char c : new_id) {
        if (c != '-' && c != '_' && c != '.' && !(c >= 'a' && c <= 'z') && !(c >= '0' && c <= '9'))
            continue;   // 소문자,숫자, 빼기, 언더바, 마침표가 아닌 애들은 answer 더하는 코드 실행 안 하고 다음으로 넘어감
        answer += c;
    }
    
    // 3단계 : 마침표가 연속된다면 하나로 줄임
    string tmp;
    for (int i = 0; i < answer.size(); i++) {
        if (answer[i] == '.') {
            tmp.push_back('.');
            while (answer[i] == '.') i++;
            i--;
        } else tmp.push_back(answer[i]);
    }
    answer = tmp;
    
    // 4단계 : 마침표가 처음이나 끝에 위치한다면 제거
    if (answer[0] == '.') answer = answer.substr(1);     // idx 1부터 끝까지 빼옴
    if (answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
    
    // 5단계 : 빈 문자열이라면 a 대입
    if (answer.empty()) answer = 'a';
    
    // 6단계 : 길이제한 15, 길면 15 뒤는 자름, 잘랐는데 뒤가 .이면 지우기
    if (answer.size() > 15) answer = answer.substr(0, 15);
    if (answer[answer.size() - 1] == '.') answer = answer.substr(0, answer.size() - 1);
    
    // 7단계 : 길이가 2 이하면 마지막 문자를 길이 3이 될때까지 반복해서 넣음
    while (answer.size() < 3) {
        answer += answer[answer.size()-1];
    }

    
    return answer;
}