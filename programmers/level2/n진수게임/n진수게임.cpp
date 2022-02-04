// 22.02.04. n진수게임
#include <string>
#include <vector>
using namespace std;
string var[16] = {"0", "1", "2", "3", "4", "5", "6", "7",
                  "8", "9", "A", "B", "C", "D", "E", "F"};

// n진수 구하는 함수
string invert(int n, int num) {
    string inv = "";
    string res = "";
    
    while(num > 0) {
        inv += var[num % n];
        num /= n;
    }
    
    for(int i = inv.size() - 1; i >= 0; i--) {
        res += inv[i];
    }
    // ===> reverse(inv.begin(), inv.end())   #include <algorithm>
    
    return res;
}

string solution(int n, int t, int m, int p) {
    string tmp = "0";
    int total = t * m;
    string answer = "";
    
    for(int i = 1; i < total; i++) {
        tmp += invert(n, i);
    }
    
    for(int i = p-1; i < tmp.size(); i = i+m) {
        answer += tmp[i];
        if (answer.size() == t) break;
    }
    
    return answer;
}