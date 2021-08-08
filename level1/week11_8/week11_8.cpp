//week11-8 문자열 다루기 기본
#include <string>
#include <vector>

using namespace std;

bool solution(string s) {        
    for (char c : s) {
        if (c >= 'a' && c <= 'z') return false;
    }
    
    if (s.size() == 4 || s.size() == 6) return true;

    return false;
}