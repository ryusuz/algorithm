//week13-5 올바른 괄호
#include<string>

using namespace std;

bool solution(string s)
{
    int count = 0;
    
    for (char c : s) {
        if (c == '(') {
            count += 1;
        } else if (c == ')') {
            count -= 1;
        }
        
        if (count < 0) break;
    }
    
    return (count == 0) ? true : false;
}