//week11 124나라
#include <string>
#include <algorithm>

using namespace std;

string solution(int n) {
    string answer = "";
    int q = 0, r = 0;
    
    while (n > 0) {
        r = n % 3;
        n /= 3;
        
        if (r == 1) answer += "1";
        else if (r == 2) answer += "2";
        else if (r == 0) {
            answer += "4";
            n -= 1;
        }
    }
    
    reverse(answer.begin(), answer.end());
    
    return answer;
}

