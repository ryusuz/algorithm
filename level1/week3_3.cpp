// week3-3 다트 게임
#include <string>
#include <cctype>
#include <iostream>
#include <vector>

using namespace std;

int solution(string dartResult) {
    int answer = 0;
    int count = 0;                      // 기회 카운팅
    int scores[3] = {0};               // 기회별 점수
    string num = "";                    // 입력 스트링에서 숫자만 담을 변수
    
    for (char c : dartResult) {
        if (isalpha(c)) {               // 알파벳이면
            int score = stoi(num);      // 스트링 숫자 정수로 바꿈
            num ="";                    // 다음 스트링 숫자 넣기 위해 초기화
            
            switch(c) {
                case 'D':
                    score = score * score;
                    break;
                case 'T':
                    score = score * score * score;
                    break;
            }
            
            scores[count++] = score;
            
        } else if (c == '*') {
            scores[count-2] *= 2;
            scores[count-1] *= 2;
        } else if (c == '#') {
            scores[count-1] *= -1;
        } else {
            num += c;
        }
    }
    
    answer = scores[0] + scores[1] + scores[2];
    
    return answer;
}