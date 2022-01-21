//week10-1 숫자 문자열과 영단어
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    unordered_map<string, string> m;
    vector<string> numbers = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
    
    int i = 0;
    for (string num : numbers) {
        m[num] = to_string(i++);
    }
    
    string tmp = "";
    string num = "";
    for (char c : s) {
        if (c >= '0' && c <= '9') {
            num += c;
        } else {
            tmp += c;
            if (m.find(tmp) != m.end()) {
                num += m[tmp];
                tmp = "";
            }
        }
    } 

    return stoi(num);
}
