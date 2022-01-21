//week12-7 JadenCase 문자열 만들기
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    string tmp = "";
    for (auto& elem : s) {
        if (elem == ' ') {
            if (tmp.size() != 0) {
                if (isalpha(tmp[0])) tmp[0] = toupper(tmp[0]);
                answer += tmp;
                tmp = "";
            }
            answer += elem;
        } else {
            if (isalpha(elem)) tmp += tolower(elem);
            else tmp += elem;
        }
    }
    
    for (int i = 0; i < tmp.size(); i++) {
        if (i == 0 || isalpha(tmp[0])) tmp[0] = toupper(tmp[0]);
        else {
            if (isalpha(tmp[i])) tmp[i] = tolower(tmp[i]);
        }
    }
    
    answer += tmp;
 
    return answer;
}

/////////////////////////////////////////
#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";

    answer += toupper(s[0]);
    for (int i = 1; i < s.size(); i++)
        s[i - 1] == ' ' ? answer += toupper(s[i]) : answer += tolower(s[i]);

    return answer;
}