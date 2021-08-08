//week11-11 시저 암호
#include <string>
#include <vector>

using namespace std;

string solution(string s, int n) {
    string answer = "";
    
    for (int i = 0; i < s.size(); i++) {
        if (isspace(s[i])) continue;
        
        if (isupper(s[i])) {
            if (s[i] + n > 'Z') {
                int tmp = n - ('Z' - s[i]);
                s[i] = 64 + tmp;
            } else {
                s[i] += n;
            }
        } else {
            if (s[i] + n > 'z') {
                int tmp = n - ('z' - s[i]);
                s[i] = 96 + tmp;
            } else {
                s[i] += n;
            }
        }
    }
    
    return s;
}