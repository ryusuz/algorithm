//week11-13 이상한 문자 만들기
#include <string>
#include <iostream>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int idx = 0;
    
    for (int i = 0; i < s.size(); i++) {
        if (i > 0 && s[i-1] == ' ' && isalpha(s[i])) idx = 0;
        
        if (idx % 2 == 0 && islower(s[i])) answer += toupper(s[i]);
        else if (idx % 2 != 0 && isupper(s[i])) answer += tolower(s[i]);
        else answer += s[i];
        
        idx++;
    }
    
    return answer;
}



//////////////////
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    int nIndex = 1;
    for (int i = 0; i < s.size(); i++, nIndex++)
    {
        if (s[i] == ' ')
        {
            nIndex = 0;
            answer += " ";
        }
        else
            nIndex & 1 ? answer += toupper(s[i]) : answer += tolower(s[i]);
    }

    return answer;
}


/// tolower, toupper 구현 방법
char toUp(char word) {
    if (word >= 'a' && word <= 'z') {
        word = word - ('a' - 'A');
    }
    return word;
}

char toLow(char word) {
    if (word >= 'A' && word <= 'Z') {
        word = word + ('a' - 'A');
    }
    return word;
}