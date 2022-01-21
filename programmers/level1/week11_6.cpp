//week11-6 a 문자열 내 p와 y의 개수
#include <string>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    int pNum = 0, yNum = 0;
    
    for(char c : s) {
        if (c == 'p' || c == 'P') pNum++;
        else if (c == 'y' || c == 'Y') yNum++;
    }
    
    if (pNum != yNum) answer = false;

    return pNum+yNum == 0 ? true : answer;
}


/////
#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    int p = 0;
    int y = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == 'p' || s[i] == 'P')
            p++;
        else if (s[i] == 'y' || s[i] == 'Y')
            y++;
    }
    return p == y;
}