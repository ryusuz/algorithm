// 22.02.14. 이진 변환 반복하기

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

string getBinary(int n) {
    string result = "";
    while (n > 0) {
        result += to_string(n%2);
        n /= 2;
    }
    
    reverse(result.begin(), result.end());
    return result;
}

void binaryFunc(int depth, string s, vector<int> &answer) {
    if (s == "1") return;
    
    int size = s.size();
    int ones = 0;

    for(int i = 0; i < size; i++) {
        if (s[i] == '1') ones++;
    }
    
    answer[1] += (size - ones);
    
    binaryFunc(answer[0]++, getBinary(ones), answer);
}

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    binaryFunc(0, s, answer);
    return answer;
}